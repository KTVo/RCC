#include "Prob4.h"

#include <iostream>

using namespace std;

saveAccount::saveAccount(float num){
    //Initilizes the balance if greater than zero
    if(num > 0){
        balance = num;
    }   
    else{
        balance = 0;
    }
    //Sets other properties to zero
    FreqDeposit = 0;
    FreqWithDraw = 0;
}

void saveAccount::Transaction(float numTran){
    //If transaction is greater than 0 then deposit, else Withdraw is made
    if(numTran > 0){
        Deposit(numTran);
    }
    else{
        Withdraw(numTran);
    }
}

//Deducts balance and increment the frequence of deposit
float saveAccount::Deposit(float numD){
    balance += numD;
    FreqDeposit++;
return balance;}

//Increases balance and frequence of withdraw for display
float saveAccount::Withdraw(float numW){
    float newBal = balance - numW;
    //Extra credit: Using exceptions
    try{
        if(newBal >= 0){
            balance -= numW;
            FreqWithDraw++;
        }
        else{
                throw 7855;
        }
    }
    catch (int z){
        cout<<"Error: "<<z<<" WithDraw not Allowed\n";
    }
    if(newBal >= 0){
        balance -= numW;
        FreqWithDraw++;
    }
    else{
        cout<<"WithDraw not Allowed\n";
    }
return balance;}

//Displays the results
void saveAccount::toString(){
    cout<<"Balance = "<<balance<<endl;
    cout<<"WithDraws = "<<FreqWithDraw<<endl;
    cout<<"Dospit = "<<FreqDeposit<<endl;
}

float saveAccount::Total(float savint = 0, int time = 0){
    float total = 0.0;
    
    for(int x = 1; x <= time; x++){
        total += (balance*(1+savint));
    }
return total;}

float saveAccount::TotalRecursive(float sInt, int time2){
    float total2 = 0.0;
    
    for(int x = 1; x <= time2; x++){
        total2 += (balance*TotalRecursive(x+sInt));
    }
return total2;};
