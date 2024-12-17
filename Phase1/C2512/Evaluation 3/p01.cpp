
#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    int id;
    int age;
    string name;

public:
    void swp(Employee &other)
    {
        int tempID = this->id;
        this->id = other.id;
        other.id = tempID;

        int tempAge = this->age;
        this->age = other.age;
        other.age = tempAge;

        string tempName = this->name;
        this->name = other.name;
        other.name = tempName;
    }

    Employee(int id, int age, string name);

    friend ostream &operator<<(ostream &out, Employee &employee);
};

int main()
{
    Employee e1(101, 22, "Athira"), e2(102, 23, "Bhagya");
    cout << e1 << endl
         << e2 << endl;
    e1.swp(e2);
    cout << e1 << endl
         << e2 << endl;

    return 0;
}

Employee::Employee(int id, int age, string name) : id(id), age(age), name(name) {}
ostream &operator<<(ostream &out, Employee &employee)
{
    out << "ID: " << employee.id << ", name: " << employee.name << ", age: " << employee.age;
    return out;
}
