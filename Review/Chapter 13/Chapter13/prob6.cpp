#include "prob6.h"
#include <iostream>

using namespace std;

void prob6(){
    Inventory a,
              b(2222, 23, 3.68);
    
    a.setItemNumber(1111);
    a.setQuantity(7);
    a.setCost(1.99);
    a.setTotalCost();
    
    cout<<endl;
    cout<<"\nItem Number: "<<a.getItemNumber();
    cout<<"\nQuantity: "<<a.getQuantity();
    cout<<"\nCost: $"<<a.getCost();
    cout<<"\nTotal Cost: $"<<a.getTotalCost();
    cout<<endl<<endl;
    
    
    cout<<"\nItem Number: "<<b.getItemNumber();
    cout<<"\nQuantity: "<<b.getQuantity();
    cout<<"\nCost: $"<<b.getCost();
    cout<<"\nTotal Cost: $"<<b.getTotalCost();
    cout<<endl<<endl;
}

Inventory::Inventory(){
    if(itemNumber >= 0 && quantity >= 0 && cost >= 0.00 && totalCost >= 0.00){
        itemNumber = 0;
        quantity = 0;
        cost = 0.00;
        totalCost = 0.00;
    }else
        cout<<"\nInput Validation: There cannot be a NEGATIVE value.\n";
}
Inventory::Inventory(int itemNumber, int quantity, float cost){
    totalCost = 0.00;
    if(itemNumber >= 0 && quantity >= 0 && cost >= 0.00 && totalCost >= 0.00){
        this->cost = cost;
        this->quantity = quantity;
        this->itemNumber =itemNumber;

        setTotalCost();
    }else
        cout<<"\nInput Validation: There cannot be a NEGATIVE value.\n";
}

//Manipulators
void Inventory::setItemNumber(int itemNumber){
    this->itemNumber = itemNumber;
}
void Inventory::setQuantity(int quantity){
    this->quantity = quantity;
}
void Inventory::setCost(float cost){
    this->cost = cost;
}
void Inventory::setTotalCost(){
    totalCost = quantity * cost;
}