// This program demonstrates the bad_alloc exception.
#include <iostream>
#include <new>       // Needed for bad_alloc
using namespace std;

int main()
{
   double *ptr;   // Pointer to double

   try
   {
      ptr = new double [1000000000];
      delete [] ptr;
   }
   catch (bad_alloc)
   {
      cout << "Insufficient memory.\n";
   }

   return 0;
}

