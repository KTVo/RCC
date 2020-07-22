/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   prob14.h
 * Author: dangerouspirate
 *
 * Created on June 17, 2018, 3:12 PM
 */

#ifndef PROB14_H
#define PROB14_H
class Temperature{
private:
    int temp;
    bool isEthylFreezing;
    bool isWaterFreezing;
    bool isOxygenFreezing;
    bool isEthylBoiling;
    bool isWaterBoiling;
    bool isOxygenBoiling;
    
public:
    Temperature();
    void setTemp(int);
    void calulate();
    bool ethylFreezing() const { return isEthylFreezing; }
    bool oxyFreezing() const { return isOxygenFreezing; }
    bool waterFreezing() const { return isWaterFreezing; }
    
    bool ethylBoiling() const { return isEthylBoiling; }
    bool oxyBoiling() const { return isOxygenBoiling; }
    bool waterBoilingg() const { return isWaterBoiling; }
    
    
};


#endif /* PROB14_H */

