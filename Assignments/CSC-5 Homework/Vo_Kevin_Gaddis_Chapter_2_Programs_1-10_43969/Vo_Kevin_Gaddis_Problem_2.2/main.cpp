/* 
 * name:  Kevin Vo
 * date:  Feb. 25th, 2012
 * Problem:  2.1
 * Description:  Predicting of sales for the East Coast sales division
 * preferences in Sales Prediction
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//This program will help predict the amount that the East Coast sales division
//will generate if the entire company has made $4.6 mill. in sales this year.

int main(int argc, char** argv) {
    float PercentOfTotal, TotalSale, totalGen;
    
    PercentOfTotal = 6.2E-1;
    TotalSale = 4.6E6;
    totalGen = TotalSale * PercentOfTotal;
   
    //Output Display of the program
    cout<<"Base on the given fact that the East Coast(E.C.) sales division generates 62%\n";
    cout<<"of total sales, and if the company as a whole will generate $4.6 million in\n";
    cout<<"sales this year. In theory, the E.C. sales divsion in term will generate a\n";
    cout<<"Total: "<<totalGen<<endl;//The total
    cout<<"\n";//Line skip    
    cout<<"\n";//Line skip 
    
    
    //List of information
    //East Coast div.'s Pecentage in sales
    cout<<"Percentage of East Coast's Total in Sales: "<<PercentOfTotal<<endl;
    cout<<"\n"; 
    //Overall Company Income This Year
    cout<<"Predicted Company's Overall Income (this year): "<<TotalSale;
    cout<<" ($4,600,000)\n";//Non-scientific notation format
    cout<<"\n"; 
    //The total repeated
    cout<<"Predicted Total Earning of East Coast division: "<<totalGen;
    cout<<" <--- This is the answer to Gaddis Problem 2.2"<<endl;

    
    
    return 0;
}

