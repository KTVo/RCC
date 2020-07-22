/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   prob12.h
 * Author: dangerouspirate
 *
 * Created on June 17, 2018, 11:37 AM
 */

#ifndef PROB12_H
#define PROB12_H

class Payroll{
private:
    float hrlyPayRate;
    float hrsWorked;
    float grossPayWk;
    int numEmploy;
    
    
public:
    //Calculates the gross pay for the week
    void calGross();
    
    //Manipulators
    void setHrlyRate(float);
    void setHrsWorked(float);
    void setGrossPayWk(float);
    
    //Accessors
    float getHrlyRate() const {return hrlyPayRate;}
    float getHrsWorked() const {return hrsWorked;}
    float getGrossPayWk() const {return grossPayWk;}
    
};

#endif /* PROB12_H */

