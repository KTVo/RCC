/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dangerouspirate
 *
 * Created on June 22, 2018, 11:07 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#include "Vector.h"

int main(int argc, char** argv) {
    Vector<int> v;
    
    v.insert(1);
    v.insert(2);
    v.insert(3);
    v.insert(4);
    v.insert(5);
    v.insert(6);
    v.insert(7);
    v.insert(8);
    v.insert(9);
    v.adv_Insert(999);
    v.insert(10);
    v.insert(11);
    v.insert(12);
    v.insert(13);
    v.insert(14);
    v.insert(15);
    
    
    v.displayAll();
    
    cout<<endl<<endl;
    
    v.deleteVal(4);
    
    v.displayAll();
    
    cout<<endl<<endl;
    
    v.deleteIndx(7);

    v.displayAll();
    
    cout<<endl<<endl;
    
    v.insert(24);
    
    v.displayAll();
    
    cout<<endl<<endl;
    return 0;
}

