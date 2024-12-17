 //1.2 "id, age, name" as dynamic memory using new and delete 

#include<iostream>
#include <algorithm>
using namespace std;
#include<string>

class Employee{
public:    
    int* id;
    int* age;
    string* name;
public:
    Employee(int v_id, int v_age, string v_name){
        id = new int (v_id);
        age = new int (v_age);
        name = new string (v_name);
    }
    ~Employee() {
        delete id;    
        delete age;   
        delete name;  
    }

    friend void swap(Employee&, Employee& ); 
    friend ostream& operator << (ostream& os, Employee&);
};
void swap(Employee& a, Employee& other) 
    {
        std::swap(a.id, other.id);      
        std::swap(a.age, other.age);     
        std::swap(a.name, other.name);   
    }

ostream& operator << (ostream& os, Employee& obj){
    os << *obj.id <<" " << *obj.age << " "<< *obj.name;
    return os;
}

int main(){
    Employee e1(101,22,"Athira"),e2(102,23,"Bhagya");
    cout << "e1: " <<  e1 << endl;
    cout << "e2: " <<  e2 << endl;
    swap(e1,e2);
    cout << "after swap"<< endl;
    cout << "e1: " <<  e1 << endl;
    cout << "e2: " <<  e2 << endl;

    return 0;
}
