// This program demonstrates an exception being thrown and caught.
#include <iostream>
using namespace std;

// Function prototype
double divide(int, int);

int main()
{
   int num1, num2;  // To hold two numbers
   double quotient; // To hold the quotient of the numbers

   // Get two numbers.
   cout << "Enter two numbers: ";
   cin >> num1 >> num2;

   // Divide num1 by num2 and catch any
   // potential exceptions.
   try
   {
      quotient = divide(num1, num2);
      cout << "The quotient is " << quotient << endl;
   }
   catch (char *exceptionString)
   {
      cout << exceptionString;
   }

   cout << "End of the program.\n";
   return 0;
}

//********************************************
// The divide function divides numerator by  *
// denominator. If denominator is zero, the  *
// function throws an exception.             *
//********************************************

double divide(int numerator, int denominator)
{
   if (denominator == 0)
      throw "ERROR: Cannot divide by zero.\n";

   return static_cast<double>(numerator) / denominator;
}
