/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 13, 2017, 11:43 AM
 * Purpose:  Used as C++ functions for testing
 *           the GET/POST of PHP/Java-script
 */
#ifndef SAVINGSFUNCTIONS_H
#define SAVINGSFUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class SavingsFunctions{
    private:
        float pv, intr;
        int n;
        float save1();
        float save2();
        float save3();
        float save4(float, float, int);
        float save5(int);
    public:
        float getPV(){return pv;}
        float getIntr(){return intr;}
        int getN(){return n;}
        SavingsFunctions(float, float, int);
        void display(float *fv,int n);
        float getSave1(){return save1();}
        float getSave2(){return save2();}
        float getSave3(){return save3();}
        float getSave4(){return save4(pv, intr, n);}
        float getSave5(){return save5(12);}
        void save6(float&);
        float *save7();
};



#endif /* SAVINGSFUNCTIONS_H */

