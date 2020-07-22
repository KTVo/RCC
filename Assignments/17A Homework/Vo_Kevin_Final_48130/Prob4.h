/* 
 * File:   Prob4.h
 * Author: Kevin Vo
 *
 * Created on December 10, 2014, 9:53 PM
 */

#ifndef PROB4_H
#define	PROB4_H

class saveAccount
{
public:
    saveAccount(float); //Constructor
    void Transaction(float); //Procedure
    float Total(float,int); //Savings Procedure
    float TotalRecursive(float=0,int=0);
    void toString(); //Output Properties

    private:
        float Withdraw(float); //Utility Procedure
        float Deposit(float); //Utility Procedure
        float balance; //Property
        int FreqWithDraw; //Property
        int FreqDeposit; //Property
};

#endif	/* PROB4_H */

