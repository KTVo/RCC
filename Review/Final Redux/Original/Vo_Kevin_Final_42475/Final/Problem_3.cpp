/* 
 * File:   Problem_3.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Final
 * Created on May 31, 2018, 8:31 AM
 */

#include <iostream>
#include <queue>
#include <vector>
#include <ctime>

#include "Problem_3.h"

using namespace std;

void prob3(){
    cout<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"*             Problem 3 - Queues            *"<<endl;
    cout<<"*********************************************"<<endl;
    
    srand(time(NULL));
    
    //Stores customer queued in line
    queue<char> cust;
    
    //Indicates avaliable employee(s)
    vector<Clerk> employee;

    //Object for Service struct
    Service serve;

    //Number of employees at the start
    const int numEmp = 3;
    
    //Assign base values for original employees
    for (int i = 0; i < numEmp; i++){
            Clerk e;
            e.serving = false;
            e.timeBegin = 0;
            e.served = 0;
            
            //Assigns rate of service for each employee
            if(i == 0)
                e.time = 60;
            if(i == 1)
                e.time = 120;
            if(i == 2)
                e.time = 80;
            employee.push_back(e);
    }


    int temp;
    int maxCustInLine = cust.size();
    int hr = 1;
        
    cout<<"\nLet Simulated Time = "<<hr<<" Hour"<<endl<<endl;

    //converts hours to seconds
    int totalSec = hr * 3600;



    for (int numSec = 0; numSec <= totalSec; numSec += 5) {
        if(maxCustInLine < cust.size())
            maxCustInLine = cust.size();
        
        serve.avaliable = false;
        int diffTime;

        for(int i = 0; i < employee.size(); i++){
            if(i > 2)
                diffTime = 60;
            else
                diffTime = employee[i].time;

            if(employee[i].serving){
                int t = employee[i].timeBegin + diffTime;

                    if(t == numSec) {
                        employee[i].serving = false;
                        employee[i].timeBegin = 0;
                        employee[i].served++;
                        serve.avaliable = true;
                    }
            }

        }

        if(numSec % 15 == 0){
            cust.push('c'); 

        }

        serve.waiting = true;

        if(cust.size() > 0){
            for (int i = 0; i < employee.size(); i++)
                if (!( employee[i].serving ) && cust.size( ) > 0){
                    serve.waiting = false;
                        employee[i].serving = true;
                        employee[i].timeBegin = numSec; 
                        cust.pop();
                }

            temp = serve.waitTime;

            if(serve.waiting == true)
                temp += cust.size() * 5;

            serve.waitTime = temp;    
        }

        if(serve.avaliable == false && cust.size( ) > 5){
            Clerk extra;

            extra.timeBegin = 0;
            extra.served = 0;
            extra.serving = false;

            employee.push_back(extra);
        }

        if(cust.size() == 0 && employee.size() > numEmp)
            employee.pop_back();

    }




    serve.totalCust = 0;

    for(int i = 0; i < employee.size(); i++){
        cout<<"Clerk #"<<i+1<<" -> "<<employee[i].served<<" customers served\n";
        serve.totalCust += employee[i].served;

    }

    float aveTime = (float)((serve.waitTime /60.0f) / (serve.totalCust* 1.0f));

    cout<<"\nMax Number of Customers in the Line: "<<maxCustInLine<<endl;

    cout<<"\nMax Number of Customers: "<<serve.totalCust<<endl;

    cout<<"\nAverage Wait Time = "<<aveTime<<" minutes"<<endl;

    cout<<"\n--------------------------------------------------------------\n";



}