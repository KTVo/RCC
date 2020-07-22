/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   prob6.h
 * Author: dangerouspirate
 *
 * Created on June 16, 2018, 11:33 PM
 */

#ifndef PROB6_H
#define PROB6_H
class Inventory{
    protected:
        int itemNumber,
            quantity;
        float cost,
              totalCost;
        
    public:
        Inventory();
        Inventory(int,int,float);
        
        //Manipulators
        void setItemNumber(int);
        void setQuantity(int);
        void setCost(float);
        void setTotalCost();
        
        //Accessors
        int getItemNumber() const {return itemNumber;}
        int getQuantity() const {return quantity;}
        float getCost() const {return cost;}
        float getTotalCost() const {return totalCost;}
    
};


#endif /* PROB6_H */

