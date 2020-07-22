/* 
 * name:  Kevin Vo
 * date:  Feb. 25th, 2012
 * Problem:  Ch.2,Problem: 3
 * Description:  Computing sales tax on a purchase
 * preferences in Sales Taxes
 * 
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//This program will compute the total sales tax on a made up $52 dollars purchase
//The state sales tax is 4 percent and country sales tax is 2 percent

int main(int argc, char** argv) {
    //CT is County Sales Tax
    //ST is State Sales Tax
    //Pur is the cost of the Purchase 
    //Total is Total Sales Tax
    
    float CT, ST, Total, Pur;
    
    CT = 4.0e-2;
    ST = 2.0e-2;
    Pur = 5.2e1;
    Total = (CT + ST) * Pur;
    
    //Output Display of Program
    cout<<"If a purchase is $52 and considering the state sales tax is 4 percent,\n";
    cout<<"along with the county sales tax being 2 percent. Then the total\n";
    cout<<"sales tax would cost: $"<<Total<<endl;//Sale Tax Total
    cout<<"\n";//Line Skip
    cout<<"\n";//Line Skip
    
    //Cost of purchase
    cout<<"Purchase Cost: $ "<<Pur<<endl;
    cout<<"\n";//Line Skip
    
    //The stated amount of county sales tax
    cout<<"County Sales Tax: $ "<<CT<<endl;
    cout<<"\n";
    
    //The stated amount of state sales taxes
    cout<<"State Sales Tax: $ "<<ST<<endl;
    cout<<"\n";           
    
    //The cost of the total sales tax
    cout<<"Total Sales Tax: $ "<<Total;
    cout<<" <-- Here is the answer to Gaddis Problem 2.3"<<endl;
    
    
    
            
    

    return 0;
}

