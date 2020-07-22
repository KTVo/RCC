/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Problem: Gaddis Problem 6.3
 * Description: Determines which 4 division of a company made the most
 * Created on May 10, 2012, 8:00 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;


float getSales();
void findHighest();
float NE, SE, NW, SW;
int main(int argc, char** argv) {

    
    
    getSales();
    findHighest();
    

    return 0;
}

float getSales(){
   const float Z = 0.00;//Z = zero
        cout<<"What is the quarterly sales figure of Northeast division? $";
        cin>>NE;


        cout<<"What is the quarterly sales figure of the Southeast division? $";
        cin>>SE;
    

        cout<<"What is the quarterly sales figure of the Northwest division? $";
        cin>>NW;

        cout<<"What is the quarterly sales figure of the Southwest division? $";
        cin>>SW;

        if(NE<Z || SE<Z || NW<Z || SW<Z){
    cout<<"\nInput Validation: Do not accept dollar amounts less than $0.00\n";    
    exit (0);
    }

}

void findHighest(){
    if (NE>SE&&NE>NW&&NE>SW){
        cout<<"The highest grossing division is the Northeast division with $"<<
                fixed<<setprecision(2)<<showpoint<<NE<<endl;    
    }
    
    else if (SE>NE&&SE>NW&&SE>SW){
        cout<<"The highest grossing division is the Southeast division with $"<<
                fixed<<setprecision(2)<<showpoint<<SE<<endl;    
    }
    
    else if (NW>NE&&NW>SE&&NW>SW){
        cout<<"The highest grossing division is the Northwest division with $"<<
                fixed<<setprecision(2)<<showpoint<<NW<<endl;    
    }
    
    else if (SW>NE&&SW>SE&&SW>NW){
        cout<<"The highest grossing division is the Southwest division with $"<<
                fixed<<setprecision(2)<<showpoint<<SW<<endl;
    }
    else{
        cout<<"There has seem to be a tie between two or more the divisions.\n";
    }    
}