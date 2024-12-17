/*
// Coding Question: 1.1
    Employee {id, age, name} //id, age, name are value objects
    Employee e1(101,22,"Athira"),e2(102,23,"Bhagya");
    cout << e1 << endl; //101 22 Athira
    cout << e2 << endl; //102 23 Bhagya
    e1.swap(e2);
    cout << e1 << endl; //102 23 Bhagya
    cout << e2 << endl; //101 22 Athira
    //1.2 "id, age, name" as dynamic memory using new and delete
    //1.3 Programmer { string* tasks; int taskCount; } : Employee | tasks is the multiple tasks - array of task
        swap function overloadable
        here, create the dynamic programmer object assigned to employee pointer.
        field 'tasks' is dynamic memoery.
        operator << overloadable, swap is overridden.
    //1.4 replace dynamic fields as smart pointers
        prove that Employee virtual destructor is not needed.
        create the dynamic programmer object assigned to employee smart pointer
    //1.5 construct array of N programmers. read programmers from keyboard.
        cin >> var; // overload operator>> in employee and programmer
*/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Employee
{
private:
    int *id;
    int *age;
    char *name;

public:
    Employee(int id = 0, int age = 0, const char *name = "")
    {
        this->id = new int(id);
        this->age = new int(age);
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Employee(Employee &&other) noexcept
    {
        id = other.id;
        age = other.age;
        name = other.name;

        other.id = nullptr;
        other.age = nullptr;
        other.name = nullptr;
    }

    Employee &operator=(Employee &&other) noexcept
    {
        if (this != &other)
        {
            delete id;
            delete age;
            delete[] name;

            id = other.id;
            age = other.age;
            name = other.name;

            other.id = nullptr;
            other.age = nullptr;
            other.name = nullptr;
        }
        return *this;
    }

    virtual ~Employee()
    {
        delete id;
        delete age;
        delete[] name;
    }

    virtual void swp(Employee &other)
    {
        Employee temp(move(*this));
        *this = move(other);
        other = move(temp);
    }

    friend ostream &operator<<(ostream &out, const Employee &employee)
    {
        out << "ID: " << *(employee.id) << ", Name: " << employee.name << ", Age: " << *(employee.age);
        return out;
    }

    friend istream &operator>>(istream &in, Employee &employee);
};

istream &operator>>(istream &in, Employee &employee)
{
    int tempId, tempAge;
    string tempName;

    cout << "Enter ID: ";
    in >> tempId;

    cout << "Enter Age: ";
    in >> tempAge;

    cout << "Enter Name: ";
    in >> tempName;

    delete employee.id;
    delete employee.age;
    delete[] employee.name;

    employee.id = new int(tempId);
    employee.age = new int(tempAge);
    employee.name = new char[tempName.length() + 1];
    strcpy(employee.name, tempName.c_str());

    return in;
}

class Programmer : public Employee
{
private:
    string *tasks;
    int *taskCount;

public:
    Programmer(int id = 0, int age = 0, const char *name = "", string *v_tasks = nullptr, int v_taskCount = 0)
        : Employee(id, age, name)
    {
        taskCount = new int(v_taskCount);
        tasks = new string[v_taskCount];
        for (int i = 0; i < v_taskCount; i++)
        {
            tasks[i] = v_tasks[i];
        }
    }

    Programmer(Programmer &&other) noexcept
        : Employee(move(other)), tasks(other.tasks), taskCount(other.taskCount)
    {
        other.tasks = nullptr;
        other.taskCount = nullptr;
    }

    Programmer &operator=(Programmer &&other) noexcept
    {
        if (this != &other)
        {
            Employee::operator=(move(other));
            delete[] tasks;
            delete taskCount;

            tasks = other.tasks;
            taskCount = other.taskCount;

            other.tasks = nullptr;
            other.taskCount = nullptr;
        }
        return *this;
    }

    ~Programmer()
    {
        delete[] tasks;
        delete taskCount;
    }

    void swp(Employee &other) override
    {
        if (Programmer *pOther = dynamic_cast<Programmer *>(&other))
        {
            Programmer temp(move(*this));
            *this = move(*pOther);
            *pOther = move(temp);
        }
        else
        {
            throw runtime_error("Incompatible types for swapping.");
        }
    }

    friend ostream &operator<<(ostream &out, const Programmer &programmer)
    {
        out << static_cast<const Employee &>(programmer);
        out << ", Task Count: " << *(programmer.taskCount) << ", Tasks: [";
        for (int i = 0; i < *(programmer.taskCount); i++)
        {
            out << programmer.tasks[i];
            if (i < *(programmer.taskCount) - 1)
                out << ", ";
        }
        out << "]";
        return out;
    }

    friend istream &operator>>(istream &in, Programmer &programmer);
};

istream &operator>>(istream &in, Programmer &programmer)
{
    in >> static_cast<Employee &>(programmer);

    int tempTaskCount;
    cout << "Enter Task Count: ";
    in >> tempTaskCount;

    string *tempTasks = new string[tempTaskCount];
    cout << "Enter Tasks:\n";

    for (int i = 0; i < tempTaskCount; ++i)
    {
        cout << "Task " << (i + 1) << ": ";
        getline(in, tempTasks[i]);
    }

    delete[] programmer.tasks;
    delete programmer.taskCount;

    programmer.taskCount = new int(tempTaskCount);
    programmer.tasks = tempTasks;

    return in;
}

int main()
{
    int N;
    cout << "Enter the number of programmers: ";
    cin >> N;

    Programmer **programmers = new Programmer *[N];

    for (int i = 0; i < N; ++i)
    {
        int id, age, taskCount;
        string name;

        cout << "\nEnter details for Programmer " << (i + 1) << ":\n";

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Task Count: ";
        cin >> taskCount;

        string *tasks = new string[taskCount];
        cout << "Enter Tasks:\n";

        for (int j = 0; j < taskCount; ++j)
        {
            cout << "Task " << (j + 1) << ": ";
            cin >> tasks[j];
        }

        programmers[i] = new Programmer(id, age, name.c_str(), tasks, taskCount);

        delete[] tasks;
    }

    cout << "\nProgrammer Details:\n";
    for (int i = 0; i < N; ++i)
    {
        cout << "Programmer " << (i + 1) << ":\n"
             << *programmers[i] << endl;
    }

    // Free allocated memory
    // for (int i = 0; i < N; ++i)
    // {
    //     delete programmers[i];
    // }
    delete[] programmers;

    return 0;
}
