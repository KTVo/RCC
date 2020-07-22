#include <iostream>
#include "prob1.h"
using namespace std;

Date::Date(int m, int d, int y){
    month = m;
    day = d;
    year = y;
}

void Date::displayDate(){
    
    if(day >= 1 && day <= 31 || month >= 1 && month <= 12 ||
            year >= 1000 && year <= 9999){
        const string nameMonth[12] = 
                              {"January","February","March","April","May","June",
                               "July","August","September","October","November",
                               "December"};

        cout<<endl;
        cout<<month<<"/"<<day<<"/"<<year<<endl;
        cout<<nameMonth[month-1]<<" "<<day<<", "<<year<<endl;
        cout<<day<<" "<<nameMonth[month-1]<<" "<<year<<endl;
        cout<<endl;
    }else
        cout<<"\nInput Validation: Do not accept values for the day greater "
            <<"than 31 or less than 1. Do not accept values for the month "
            <<"greater than 12 or less than 1.\n";


}

void prob1(){
    int numM, numD, numY;
    
    do{
        
        cout<<endl;
        cout<<"Enter date in format -> MONTH DAY YEAR: ";
        cin>>numM >> numD >> numY;
        
        if(numD < 1 || numD > 31)
            cout<<"\nInput Error: DAY must [1,31]\n";
        if(numM < 1 || numM > 12)
            cout<<"\nInput Error: MONTH must [1,12]\n";
        if(numY < 1000 || numY > 9999)
            cout<<"\nInput Error: YEAR must [1000,9999]\n";
                    
    }while(numD < 1 && numD > 31 || numM < 1 && numM > 12 ||
            numY < 1000 && numY > 9999);
    
    Date date(numM, numD, numY);
    
    date.displayDate();
}