// // Coding Question: 1.1
//     Employee {id, age, name} //id, age, name are value objects 
//     Employee e1(101,22,"Athira"),e2(102,23,"Bhagya");
//     cout << e1 << endl; //101 22 Athira
//     cout << e2 << endl; //102 23 Bhagya
//     e1.swap(e2);
//     cout << e1 << endl; //102 23 Bhagya
//     cout << e2 << endl; //101 22 Athira

#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>

using namespace std;

class Employee
{
    private:
        int id;
        int age;
        string name;
    public:
        Employee(int id, int age, const string& name) : id(id), name(name), age(age) {}

        Employee(Employee&& other) 
        : id(other.id), age(other.age), name(move(other.name)) 
        {
            other.id = 0;
            other.age = 0;
        }

        Employee& operator=(Employee&& other)  
        {
            if (this != &other) 
            {
                id = other.id;
                age = other.age;
                name = move(other.name);
                other.id = 0;
                other.age = 0;
            }
        return *this;
    }
        
        friend ostream& operator<<(ostream &out, const Employee &employee);
            
        void swap(Employee& other)
        {
            Employee temp = move(*this);  
            *this = move(other);          
            other = move(temp);  
        }
};

ostream& operator<<(ostream &out, const Employee &employee) 
{
    out << employee.id << " " << employee.age << " " << employee.name;
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
