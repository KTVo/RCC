/* 
 * File:   Problem_2.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Final
 * Created on May 31, 2018, 8:31 AM
 */

#include "hyperbolics.h"    //Lehr's recursive hyperbolic function
#include <stack>    //STL's stack
using namespace std;

void prob2(){
    stack<char> *st = new stack<char>;
    cout<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"*            Problem 2 - Stacks             *"<<endl;
    cout<<"*********************************************"<<endl;
    
    //Testing out recursive trig functions
    float angDeg;
    
    float angRad=angDeg*atan(1)/45;
    
    for(float i = -1.0; i <= 1.1; i+=0.1){
        angDeg = i;
        angRad=angDeg*atan(1)/45;
        angDeg = floor(10 * angDeg + 0.5f) / 10;
        float a_sinh = sinh(angRad);
        float a_h = h(angRad, st);
        float a_cosh = cosh(angRad);
        float a_g = g(angRad, st);
        //float sizeStack = stack->size();
        int cnt_h = 0, cnt_g = 0;

        
        while(st->empty() == false){
            if(st->top() == 'g')
                cnt_g++;
            else 
                cnt_h++;
            st->pop();
        };
        
        cout<<endl;
        cout<<"Angle = "<<angDeg<<" sinh = "<<a_sinh<<
            " our h = "<<a_h<<endl;
        cout<<"Angle = "<<angDeg<<" cosh = "<<a_cosh<<
                " our g = "<<a_g<<endl;
        cout<<endl;
        cout<<"Number of calls to function g = "<<cnt_g<<endl;
        cout<<"Number of calls to function h = "<<cnt_h<<endl;
        
        cout<<"\nTotal Number of Calls: "<<cnt_g+cnt_h<<endl;
        cout<<endl<<"-------------------------------------------------------\n";
        
    }

}
