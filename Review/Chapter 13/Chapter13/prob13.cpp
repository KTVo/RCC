#include "prob13.h"

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

void prob13(){
    Mortgage a;
    int yr;
    double loan, rate;
    
    do{
        cout<<"\nEnter Loan Period in (years): ";
        cin>>yr;
        cout<<"\nEnter Loan Amount: $";
        cin>>loan;
        cout<<"\nEnter the Annual Interest Rate: $";
        cin>>rate;
        
        if(yr < 0)
            cout<<"\nYear must be positive\n";
        if(loan < 0.00)
            cout<<"\nYear must be positive\n";
        if(rate < 0.00)
            cout<<"\nYear must be positive\n";
    }while(yr < 0 && loan < 0.00 && rate < 0.00);
    
    a.setLoan(loan);
    a.setRate(rate);
    a.setYear(yr);
    
    a.calPayment();
    
    cout<<"\nMonthly Payment: $"<<setprecision(2)<<fixed
        <<a.getMonthlyPay()<<endl;
    cout<<"Total Amount Paid until end of loan period: $"<<fixed<<setprecision(2)
        <<a.getPayAmount()<<endl;
}

void Mortgage::calPayment(){
    double term = pow((1 + rate/12), 12 * years);
    
    payment = (loan * rate/12 * term)/(term - 1);

}

void Mortgage::setLoan(double l){
    loan = l;
}

void Mortgage::setRate(double r){
    rate = r;
}

void Mortgage::setYear(int y){
    years = y;
}