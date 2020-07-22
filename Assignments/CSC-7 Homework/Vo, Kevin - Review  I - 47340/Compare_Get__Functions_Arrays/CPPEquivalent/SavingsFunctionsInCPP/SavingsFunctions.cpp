
#include "SavingsFunctions.h"

SavingsFunctions::SavingsFunctions(float pv, float intr, int n){
    this->pv = pv;
    this->intr = intr;
    this->n = n;
}

//Display the savings array
void SavingsFunctions::display(float *fv7,int n){
    //Output the heading for our table
    cout<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Years   Savings"<<endl;
    for(int year=0;year<n;year++){
        cout<<setw(5)<<year;
        cout<<setw(10)<<fv7[year]<<endl;
    }
    cout<<endl;
}

//Savings with a for-loop
float SavingsFunctions::save1(){
    float tempPV = pv;
    for(int year=1;year<=n;year++){
        tempPV*=(1+intr);
    }
    return tempPV;
}



//Savings with a power function
float SavingsFunctions::save2(){
    return pv*pow((1+intr),n);
}

//Savings with the exponential-log
float SavingsFunctions::save3(){
    return pv*exp(n*log(1+intr));
}
 

//Savings with recursion
float SavingsFunctions::save4(float pv,float intr,int n){
    if(n<=0)return pv;
    return save4(pv,intr,n-1)*(1+intr);
}


//Savings with a defaulted parameter
float SavingsFunctions::save5(int n=12){
    float tempPV = pv;
    for(int year=1;year<=n;year++){
        tempPV*=(1+intr);
    }
    return tempPV;
}


//Savings with a reference object
void SavingsFunctions::save6(float &fv6){
    fv6=pv*exp(n*log(1+intr));
}

//Savings with an array
float* SavingsFunctions::save7(){
    //Declare an array
    float *fv=new float[n];
    //Calculate all the values in the array
    fv[0]=pv;
    for(int year=1;year<=n;year++){
        fv[year]=fv[year-1]*(1+intr);
    }
    return fv;
}