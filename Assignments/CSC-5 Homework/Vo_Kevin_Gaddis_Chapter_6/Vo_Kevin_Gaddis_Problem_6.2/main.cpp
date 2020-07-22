/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Problem: Gaddis Problem 6.2
 * Description: Finds the area of a rectangle
 * Created on May 8, 2012, 9:34 AM
 */

// Chapter 6, Programming Challenge 2
#include <iostream>
using namespace std;

// Write the prototypes for the getLength,
// getWidth, getArea, and displayData
// functions here.

float getLength();
float getWidth();
float getArea(float, float);
void displayData(float, float, float);

int main()
{
   float length,    // The rectangle's length
          width,     // The rectangle's width
          area;      // The rectangle's area
          
   // Get the rectangle's length.
   length = getLength();
   
   // Get the rectangle's width.
   width = getWidth();
   
   // Get the rectangle's area.
   area = getArea(length, width);
   
   // Display the rectangle's data.
   displayData(length, width, area);
          
   return 0;
}


float getLength(){
    float LENGTH;
    cout<<"What is the length of the rectangle? ";
    cin>>LENGTH;

return LENGTH;}

float getWidth(){
float WIDTH;
    cout<<"What is the with of the rectangle? ";
    cin>>WIDTH;

return WIDTH;}

float getArea(float length, float width){
    float AREA;
    AREA = length * width;
return AREA;}

void displayData(float length, float width, float area){

    cout<<"Rectangle's Length: "<<length<<endl;
    cout<<"Rectangle's Width: "<<width<<endl;
    cout<<"Rectangle's Area: "<<area<<endl;
}





//***************************************************
// You must write the getLength, getWidth, getArea, *
// and displayData functions.                       *
//***************************************************