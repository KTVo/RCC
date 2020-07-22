/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   prob3.h
 * Author: dangerouspirate
 *
 * Created on June 16, 2018, 11:09 PM
 */

#ifndef PROB3_H
#define PROB3_H

#include <iostream>

class Car{
private:
    int yearModel,
            speed;
    std::string make;
    
public:
    Car(int, std::string);
    std::string getMake() const {return make;}
    int getYear() const {return yearModel;}
    int getSpeed() const {return speed;}
    void accelerate();
    void brake();
};


#endif /* PROB3_H */

