/* 
 * name:  Kevin Vo
 * date:  Feb. 25th, 2012
 * Problem:  Gaddis Ch.2 Problem: 1
 * Description:  Summing two integers
 * preferences in Sum of Two Numbers
 * 
 */

#include <iostream>

//As instructed this program will both stores the two integers of "62 and 99".
//Then it provides of the sum of those two int. under the total variable. 
using namespace std;


int main(int argc, char** argv) {
    //Declaring the integers
    int o, e, total;
    
    o = 99;//Assignment statement of the int. 99
    e = 62;//Assignment statement of the int. 62
    total = e + o;//Total rep. both varaiables added together.
    
    //Display sect. of the program
    cout<<"This program is forumated to store the integers below.\n";
    cout<<"Integers: "<<e;//The e(62) int. given from Program Challenge 2.1
    cout<<" & "<<o<<endl;//The o(99) int. given from Program Challenge 2.1
    cout<<"Then store & display the result of summing of the two integers ";
    cout<<"above under the variable Total underneath."<<endl;
    cout<<"Total: "<<total;//The variable of the sum of the two int. above
    cout<<" <--- Answer to Gaddis Problem 2.1"<<endl;
    

    return 0;
}

