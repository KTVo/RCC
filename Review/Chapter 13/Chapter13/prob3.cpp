#include "prob3.h"

using namespace std;

void prob3(){
    Car a(2013, "KIA");
    
    cout<<endl;
    
    cout<<a.getYear()<<" "<<a.getMake()<<"'s Speed = "<<a.getSpeed()<<" MPH\n";
    cout<<endl;
    
    a.accelerate();
    a.accelerate();
    a.accelerate();
    a.accelerate();
    a.accelerate();
    
    cout<<a.getYear()<<" "<<a.getMake()<<"'s Speed = "<<a.getSpeed()<<" MPH\n";
    cout<<endl;
    
    a.brake();
    a.brake();
    a.brake();
    a.brake();
    a.brake();
    
    cout<<a.getYear()<<" "<<a.getMake()<<"'s Speed = "<<a.getSpeed()<<" MPH\n";
    cout<<endl;
}

Car::Car(int yrModel, string make){
    this->make = make;
    yearModel = yrModel;
    speed = 0;
}

void Car::accelerate(){
    speed += 5;
}

void Car::brake(){
    speed -= 5;
}