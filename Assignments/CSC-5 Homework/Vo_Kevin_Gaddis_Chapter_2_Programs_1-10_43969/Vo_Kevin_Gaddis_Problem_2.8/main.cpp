/* 
 * name:  Kevin Vo
 * date:  Feb. 26th, 2012
 * Problem:  Gaddis Ch.2 Problem: 8
 * Description:  Stores and displays total purchases variables etc.
 * preferences in Total Purchase of Goods
 * 
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//The purpose here is to hold all five items in varaiables and then display the 
//price, subtotal, tax amount and the total.

int main(int argc, char** argv) {
    
    //Using string to display all the prices
    //Uppercase "P"s represents the strings use to display the items' prices
    string P1, P2, P3, P4, P5;
    
    P1 = "Price of item 1 = $12.95";
    P2 = "Price of item 2 = $24.95";
    P3 = "Price of item 3 = $6.95";
    P4 = "Price of item 4 = $14.95";
    P5 = "Price of item 5 = $3.95";
            
    //double data type to store into varaiables
    //Lowercase "p"s represents the prices under "double"
    double p1 = 12.95, p2 = 24.95, p3 = 6.95, p4 = 14.95, p5 = 3.95, Subtotal,
            SalesTax, Total;
    
    Subtotal = p1 + p2 + p3+ p4 + p5;     
    SalesTax= 6.0e-2 * Subtotal;
    Total = Subtotal + SalesTax;
    
    //Output of the prices, subtotal, sales tax, and then the total
    cout<<"Gaddis Problem 2.8 Answers:\n"<<endl;
    cout<<"Prices of Each Items:\n";
    cout<<""<<P1<<endl;
    cout<<""<<P2<<endl;
    cout<<""<<P3<<endl;
    cout<<""<<P4<<endl;
    cout<<""<<P5<<endl<<endl;
    cout<<"Subtotal: $"<<Subtotal<<endl<<endl;
    cout<<"Amount of Sales Tax: $"<<SalesTax<<endl<<endl;
    cout<<"Total: $"<<Total<<endl;
    
    

    return 0;
}

