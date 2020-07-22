/* 
 * name:  Kevin Vo
 * date:  Feb. 26th, 2012
 * Problem:  Gaddis Ch.2 Problem: 10
 * Description:  Calcul. then displays the "car"'s gas consumption rate in MPG
 * preferences in Miles per gallon 
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//Purpose: Calculates a car containing 12 gal. that is able to travel 350 mi.
//before refueling in to miles per gallon(MPG).
int main(int argc, char** argv) {
    
    int m350, g12, MPG;
    
    m350 = 350;//Variable for miles before refueling
    g12 = 12;//12 gal. of gas that the car holds
    MPG = m350 / g12;//The car's miles per gallon
    
    //Output of the MPG
    cout<<"Gaddis Problem 2.10 Answer:"<<endl<<endl;
    cout<<"The Car's Miles Per Gallon(MPG): "<<MPG<<endl;
    
            

    return 0;
}

