#include "prob2.h"

using namespace std;

//Prototype
void displayData(Employee);

void prob2(){
    Employee a, 
             b("Mark Jones", "IT", "Programmer", 39119), 
             c("Joy Rogers", 81774);
    
    //Setting employee of object a
    a.setName("Susan Meyers");
    a.setDep("Accounting");
    a.setPos("Vice President");
    a.setID(47899);
    
    //Setting employee of object c
    c.setDep("Manufacturing");
    c.setPos("Engineer");
    
    //Shows data of each employees
    displayData(a);
    displayData(b);
    displayData(c);
    

}

void displayData(Employee per){
    cout<<"\nName: "<<per.getName()<<endl;
    cout<<"ID Number: "<<per.getID()<<endl;
    cout<<"Department: "<<per.getDep()<<endl;
    cout<<"Position: "<<per.getPos()<<endl;
    cout<<endl;
}

//Constructor overloads
Employee::Employee(string name, string dep, string position, int idNum){
    this->name = name;
    department = dep;
    this->position = position;
    idNumber = idNum;
}
Employee::Employee(string name, int idNum){
    this->name = name;
    department = "";
    position = "";
    idNumber = idNum;
}

Employee::Employee(){
    name = "";
    department = "";
    position = "";
    idNumber = 0;
}

void Employee::setDep(string d){
    department = d;
}

void Employee::setPos(string p){
    position = p;
}

void Employee::setName(string n){
    name = n;
}

void Employee::setID(int id){
    idNumber = id;
}