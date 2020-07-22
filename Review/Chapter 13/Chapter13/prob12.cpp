#include "prob12.h"

#include <iostream>
#include <iomanip>

using namespace std;

void prob12(){
    int numEmployee;
    
    cout<<"\nEnter Number of Employees: ";
    cin>>numEmployee;
    
    Payroll p[numEmployee];
    
    float hrlyRate, hrsWorked;
    
    for(int i = 0; i < numEmployee; i++){
        cout<<"Enter Employee #"<<i+1<<"'s HOURLY RATE: ";
        cin>>hrlyRate;
        cout<<"Enter Employee #"<<i+1<<"'s Hours Worked: ";
        cin>>hrsWorked;
        
        p[i].setHrlyRate(hrlyRate);
        p[i].setHrsWorked(hrsWorked);
        p[i].calGross();
    }
   
    
    cout<<endl;
    
    for(int i = 0; i < numEmployee; i++){
        cout<<"\nEmployee #"<<i+1;
        cout<<"\nHours Worked: "<<p[i].getHrsWorked()<<" hours\n";
        cout<<"Hourly Pay: $"<<fixed<<setprecision(2)<<p[i].getHrlyRate()
            <<" per hour\n";
        cout<<"Gross Pay: $"<<fixed<<setprecision(2)<<p[i].getGrossPayWk();
    }
    
    cout<<endl<<endl;

   
}



void Payroll::calGross(){
    grossPayWk = hrlyPayRate * hrsWorked;
}

void Payroll::setHrlyRate(float hrlyRate){
    hrlyPayRate = hrlyRate;
}

void Payroll::setHrsWorked(float hrsWorked){
    this->hrsWorked = hrsWorked;
}
