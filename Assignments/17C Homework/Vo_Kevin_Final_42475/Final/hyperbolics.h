/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Apr 2, 2018, 8:11 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

float h(float, stack<char> *);
float g(float, stack<char> *);

float h(float angR, stack<char> *st){
    st->push('h');
    float tol=1e-6;
    if(angR>-tol&&angR<tol)return angR+angR*angR*angR/6;
    return 2*h(angR/2, st)*g(angR/2,st);
}
float g(float angR, stack<char> *st){
    st->push('g');
    float tol=1e-6;
    if(angR>-tol&&angR<tol)return 1+angR*angR/2;
    float b=h(angR/2, st);
    return 1+2*b*b;
}