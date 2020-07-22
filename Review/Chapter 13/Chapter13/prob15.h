/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   prob15.h
 * Author: dangerouspirate
 *
 * Created on June 17, 2018, 3:43 PM
 */

#ifndef PROB15_H
#define PROB15_H
#include "prob6.h"

class Register : public Inventory{
    private:
        float finalCost;
        float buyQuantity;
        float tax; 
        float taxCost;
        float subtotal;
        
    public:
        //Constructor
        Register(int, float, const float);
        
        float getFinalCost() const {return finalCost;}
        
        float getTaxCost() const { return taxCost; }
        
        void setBuyQuantity(float);
        
        void calculateFinalCost();
        
        float getSubTotal() const { return subtotal; }
        
};

#endif /* PROB15_H */

