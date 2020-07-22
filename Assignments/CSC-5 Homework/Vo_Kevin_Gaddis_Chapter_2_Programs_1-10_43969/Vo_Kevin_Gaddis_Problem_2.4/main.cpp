/* 
 * name:  Kevin Vo
 * date:  Feb. 25th, 2012
 * Problem:  Gaddis Ch.2 Problem: 4
 * Description:  Computes tax & tip on restuarant bill
 * preferences in Restaurant Bill
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//This program will compute the tax and tip of a restaurant bill with the
//meal cost of $44.50.
int main(int argc, char** argv) {

//Declaring floats
    float MealCost, Tax, Tip, Total;
    
    MealCost = 4.45e1;//MealCost is Meal Cost
    Tax = MealCost * 6.75e-2;//Tax is Tax Amount
    Tip = (Tax + MealCost) * 1.5e-2;//Tip is Tip Amount
    Total = Tax + MealCost + Tip;//Total is Total Bill
    
    //The output display of the program
    cout<<"Gaddis Problem 2.4 Answers:\n";
    cout<<"\n";
    cout<<"Meal Cost: $"<<MealCost<<endl;
    cout<<"\n";
    cout<<"Tax Amount: $"<<Tax<<endl;
    cout<<"\n";
    cout<<"Tip Amount: $"<<Tip<<endl;
    cout<<"\n";
    cout<<"Total Bill: $"<<Total<<endl;
    
    
    
    return 0;
}

