//1.2 "id, age, name" as dynamic memory using new and delete 

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

class Employee
{
    private:
        int* id;
        int* age;
        char* name;
    public:
        Employee(int id, int age, const string& name) 
        {
            this->id = new int (id);
            this->age = new int (age);
            this->name = new char[name.length()+1];
            strcpy(this->name, name.c_str());
        }

        Employee(Employee&& other) 
        : id(other.id), age(other.age), name(other.name)
        {
            other.id = nullptr;
            other.age = nullptr;
            other.name = nullptr;
        }

        Employee& operator=(Employee&& other) 
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
        
        ~Employee()
        {
            delete id;
            delete age;
            delete[] name;
        }
        friend ostream& operator<<(std::ostream &out, const Employee &employee);
        
        void swap(Employee& other)
        {
            std::swap(id,other.id);
            std::swap(age,other.age);
            std::swap(name,other.name);
        }
};

ostream& operator<<(std::ostream &out, const Employee &employee) 
{
    out << *employee.id << " " << *employee.age << " " << employee.name;
    return out;
}

int main()
{
     Employee e1(101,22,"Athira");
     Employee e2(102,23,"Bhagya");

     cout << "Before swapping.." << endl;
     cout << e1 << endl;
     cout << e2 << endl;
     
     e1.swap(e2);
     
     cout << "After swapping.." << endl;
     cout << e1 << endl;
     cout << e2 << endl;
     
     return EXIT_SUCCESS;
}
