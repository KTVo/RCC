/* 
 * name:  Kevin Vo
 * date:  Feb. 26th, 2012
 * Problem:  Gaddis Ch.2 Problem: 9
 * Description:  Determining the amount of memory per data type w/out manual
 * preferences in data type sizes
 * 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//The purpose of this program to determine the amount of memory each data types
//(char, int, float, and double) uses in bytes without the use of a manual.
int main(int argc, char** argv) {
    
    //Output table chart of data types & its memory usage 
    cout<<"Gaddis Problem 2.9 Answers:"<<endl<<endl;
    cout<<"Data Types / Memory Usage(bytes)"<<endl;
    cout<<"   char    /       "<<sizeof(char)<<endl;
    cout<<"   int     /       "<<sizeof(int)<<endl;
    cout<<"   float   /       "<<sizeof(float)<<endl;
    cout<<"   double  /       "<<sizeof(double)<<endl;
    
    
            

    return 0;
}

