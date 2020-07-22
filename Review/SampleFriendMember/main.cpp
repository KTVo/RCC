/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kevin
 *
 * Created on June 26, 2018, 3:55 PM
 */
#include <iostream>
#include <cstdlib>

using namespace std;
class Classname;    //Forward declaration of class Classname

class AnotherClass{
    
    public:
        void functAnotherClass(Classname &);
};


class Classname{
    private:
        string name;
        int age;
    public:
        friend void set(Classname &, string, int);
        friend void print(Classname &);
        friend void AnotherClass::functAnotherClass(Classname &);
};


void AnotherClass::functAnotherClass(Classname & instance){
    cout<<endl<<endl;
    cout<<"*******************************************************************";
    cout<<"\n* Hey look, I belong to class AnotherClass and I am using private *"
        <<"\n* member variables from class Classname because I used the        *"
        <<"\n* 'friend' syntax.                                                *";
    cout<<"\n*                                                                 *";
    cout<<"\n*\tName = "<<instance.name<<"\t\t\t\t\t\t  *";
    cout<<"\n*\tAge = "<<instance.age<<"\t\t\t\t\t\t  *\n";
    cout<<"*******************************************************************"
        <<endl<<endl;
}

void set(Classname &obj, string n, int a){
    obj.age = a;
    obj.name = n;
    
}

void print(Classname &obj){
    cout<<"\nName = "<<obj.name<<endl;
    cout<<"\nAge = "<<obj.age<<endl;
}

int main(int argc, char** argv) {
    Classname o;
    
    set(o, "Bob Ross", 89);
    
    print(o);
    
    AnotherClass anotherO;
    
    anotherO.functAnotherClass(o);
    
    return 0;
}

