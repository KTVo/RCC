/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Problem: Gaddis Problem 6.5
 * Description: Figures out the falling time of the object
 * Created on May 10, 2012, 8:59 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

float fallingDistance(float);
int main(int argc, char** argv) {
float time, dist;
    int x;

   cout<<"This program will determine the distance in meters the object falls\n"
       <<"in a specific time period.\n";
    
    for (x = 0; x<=9; x++){
        time = x+1;
        dist = fallingDistance(time);
    }

    cout<<"Distance: "<<dist<<" meters\n";
    return 0;
}

float fallingDistance(float time){
    float d;
    const float grav = 9.8;
    d = .5*(grav*(time*time));
    return d;
}