#include "prob15.h"
#include "prob6.h"
#include <iostream>
#include <iomanip>

using namespace std;
void prob15(){
    
    int idNum; 
    float buyQuantity;
    const float tax = 0.0600;
    
    do{
        cout<<"\nEnter Item's ID: ";
        cin>>idNum;
        cout<<"\nEnter Quantity: ";
        cin>>buyQuantity;
        
        if(idNum < 0)
            cout<<"\nError: Item's ID is not valid\n";
        
        if(tax < 0.000)
            cout<<"\nError: Tax rate is not valid.\n";
        
        if(buyQuantity < 0)
            cout<<"\nError: Cannot have negative buy quantity.\n";
        
        
    }while(idNum < 0 || buyQuantity < 0 || tax < 0.000);
    
    Register r(idNum, buyQuantity, tax);
    
    //Setting up Inventory
    r.setItemNumber(1111);
    r.setCost(2.99);
    r.setQuantity(200);
    r.setTotalCost();
    
    //Setting up cart info
    r.calculateFinalCost();

    
    cout<<endl<<fixed<<setprecision(2)
        <<"Subtotal: $"<<r.getSubTotal()<<endl
        <<"Tax: $"<<r.getTaxCost()<<endl
        <<"Total Cost: $"<<r.getFinalCost()<<endl<<endl;
}

Register::Register(int id, float buyQuantity, const float tax){
    
    if(buyQuantity > 0 && tax > 0.0000){
        this->tax = tax;
        itemNumber = id;
        this->buyQuantity = buyQuantity;

    }else
        cout<<"\nError: Negative Cart input detected.\n";
    
    if(quantity < buyQuantity)
        cout<<"\nYou have purchased more than what's in stock. "
            <<(buyQuantity - quantity)<<" of your "<<buyQuantity
            <<" will be back-ordered.\n";
}

void Register::calculateFinalCost(){

    
    //Add 30% profit to cost
    finalCost = cost + (cost * 0.30);
    
    finalCost *= buyQuantity;
    
    subtotal = finalCost;
    
    taxCost = finalCost * tax;
    
    finalCost += taxCost;
    
    quantity -= buyQuantity;
}

void Register::setBuyQuantity(float bQuantity){
    buyQuantity = bQuantity;
}