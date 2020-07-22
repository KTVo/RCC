#include "prob14.h"
#include <iostream>

using namespace std;

void prob14(){
    Temperature t;
    int inTemp;
    
    const string stat[2] = {"False", "True"};
    
    cout<<"\nEnter Temperature in (F): ";
    cin>> inTemp;
    
    t.setTemp(inTemp);
    
    t.calulate();
    
    cout<<endl;
    cout<<"0 -> False"<<endl<<"1 -> True"<<endl<<endl;
    cout<<"Is Ethyl Alcohol Freezing? "<<stat[t.ethylFreezing()]<<endl;
    cout<<"Is Ethyl Alcohol Boiling?  "<<stat[t.ethylBoiling()]<<endl;
    cout<<endl;
    cout<<"Is Oxygen Freezing? "<<stat[t.oxyFreezing()]<<endl;
    cout<<"Is Oxygen Boiling?  "<<stat[t.oxyBoiling()]<<endl;
    cout<<endl;
    cout<<"Is Water Freezing? "<<stat[t.waterFreezing()]<<endl;
    cout<<"Is Water Boiling?  "<<stat[t.waterBoilingg()]<<endl;
    cout<<endl;
}

//Constructor
Temperature::Temperature(){
    isEthylFreezing = false;
    isEthylBoiling = false;
    isOxygenFreezing = false;
    isOxygenBoiling = false;
    isWaterFreezing = false;
    isWaterBoiling = false;
}

//Mutator
void Temperature::setTemp(int t){
    temp = t;
}

//Determine if a substance if boiling, freezing, or neither 
void Temperature::calulate(){
    if(temp < -173)
        isEthylFreezing = true;
    else if(temp >= 172)
        isEthylBoiling = true;
    
    if(temp <= -362)
        isOxygenFreezing = true;
    else if(temp >= -306)
        isOxygenBoiling = true;
    
    if(temp <= 32)
        isWaterFreezing = true;
    else if(temp >= 212)
        isWaterBoiling = true;
            
}

