/* 
 * File:   Prob5.h
 * Author: Kevin Vo
 *
 * Created on December 10, 2014, 8:54 PM
 */

#ifndef PROB5_H
#define	PROB5_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

class Employee{
    public:
	Employee(char[], char[],float);  //Constructor
	float  CalculatePay(float,int); //Procedure
	float  getGrossPay(float,int);  //Procedure
	float  getNetPay(float);        //Procedure
	void   toString();              //Procedure
	int    setHoursWorked(int);     //Procedure
	float  setHourlyRate(float);    //Procedure
    private:
	double Tax(float); //Utility Procedure
	char   MyName[20]; //Property
	char   JobTitle[20]; //Property
	float  HourlyRate; //Property
	int    HoursWorked; //Property
	float  GrossPay; //Property
        float  NetPay; //Property
};

#endif	/* PROB5_H */

