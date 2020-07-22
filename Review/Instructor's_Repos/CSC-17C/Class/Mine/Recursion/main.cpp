/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on March 29th, 2018, 11:20 AM
 * Purpose:  CPP Template
 *           To be copied for each project
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
#include <cmath>    //Math functions
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes
float rExp(int,int);   //recursive bloom filter sum
float rExpBad(int,int);//recursive bloom filter sum
float aExp(int,int);   //approximate bloom filter sum
float eExp(int,int);   //exact bloom filter sum
int gcd(int,int);      //greatest common divisor
int bCoeff(int,int);   //binomial coefficient, combination
float fv(float,float,int);//future value function
int mx(int [],int,int);//Find a maximum in the array
double rSin(double);     //Recursive sin
double rCos(double);     //Recursive cos

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    int n=365;
    int km=32;
    int num=920,den=138,snum,sden;
    
    //Output for a comparison Bloop Filter
    cout<<"Bloom filter km="<<km<<" n="<<n<<endl;
    cout<<"Recursive     Bloom filter sum = "<<rExp(km,n)<<endl;
    //cout<<"Recursive Bad Bloom filter sum = "<<rExpBad(km,n)<<endl;
    cout<<"Approximate   Bloom filter sum = "<<aExp(km,n)<<endl;
    cout<<"Exact         Bloom filter sum = "<<eExp(km,n)<<endl;

    //Simplify a fraction
    int comFact=gcd(num,den);
    snum=num/comFact;
    sden=den/comFact;
    cout<<"The fraction "<<num<<"/"<<den
            <<" = "<<snum<<"/"<<sden<<endl;
    
    //Output a triangular array
    for(int n=0;n<=15;n++){
        for(int i=0;i<=n;i++){
            cout<<bCoeff(n,i)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    //Output the future value using the rule of 72
    float pv=100.0f;//$100
    float ir=0.06f;//6 percent
    int nc=0.72f/ir;//Rule of 72
    cout<<"Savings Function"<<endl;
    cout<<"Present Value = $"<<pv<<endl;
    cout<<"Interest Rate = "<<ir*100<<"%"<<endl;
    cout<<"Compounding Periods = "<<nc<<" years"<<endl;
    cout<<"Future Value = $"<<fv(pv,ir,nc)<<endl;
    
    //Output the maximum value in an array
    int a[]={1,2,3,4,3,2};
    cout<<endl<<"Max value in the array = "<<mx(a,0,5)<<endl;
    
    //Output and compare the recursive sin and cos
    double angle=atan(1);//Pi/4
    cout<<endl<<"The angle = "<<angle<<" radians"<<endl;
    cout<<"The recursive cos = "<<rCos(angle)<<endl;
    cout<<"The recursive sin = "<<rSin(angle)<<endl;
    cout<<"The actual    cos = "<<cos(angle)<<endl;
    cout<<"The actual    sin = "<<sin(angle)<<endl;
    
    //Exit program!
    return 0;
}

double rSin(double angle){
    double tol=1e-7f;
    if(abs(angle)<tol)return angle;
    angle/=2;
    return 2*rSin(angle)*rCos(angle);
}
double rCos(double angle){
    double tol=1e-7f;
    if(abs(angle)<tol)return 1-angle*angle/2;
    angle/=2;
    double a=rSin(angle);
    double b=rCos(angle);
    return b*b-a*a;
}

int mx(int a[],int beg,int end){
    if(end-beg<=1)return a[beg];
    int half=(beg+end)/2;
    int m1=mx(a,beg,half);
    int m2=mx(a,half,end);
    return (m1>m2?m1:m2);
}

float fv(float pv,float ir,int nc){
    if(nc<=0)return pv;
    return fv(pv,ir,nc-1)*(1+ir);
}

int bCoeff(int n,int i){
    if(i==0)return 1;
    if(i==n)return 1;
    return bCoeff(n-1,i-1)+bCoeff(n-1,i);
}

int gcd(int m,int n){
    if(m==0)return n;
    if(m>=n)return gcd(m%n,n);
    else return gcd(n%m,m);
}
float rExp(int km,int n){
    if(km<=0)return 0;
    if(km==1)return 1;
    float val=rExp(km-1,n);
    return val+(n-val)/n;
}
float rExpBad(int km,int n){
    if(km<=0)return 0;
    if(km==1)return 1;
    return rExpBad(km-1,n)+(n-rExpBad(km-1,n))/n;
}
float aExp(int km,int n){
    return n*(1-exp(-km/static_cast<float>(n)));
}
float eExp(int km,int n){
    return n*(1-pow((1-1.0f/n),km));
}