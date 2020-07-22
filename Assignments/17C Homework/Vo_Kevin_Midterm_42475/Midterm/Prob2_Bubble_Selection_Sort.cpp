/* 
 * File:   Prob2_Bubble_Selection_Sort.cpp
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Problem: #2
 * Created on April 19, 2018, 11:43 PM
 */

// This program uses the bubble sort algorithm to sort an
// array in ascending order.
#include <iostream>
#include <cmath>
#include <ctime>
#include <ratio>
#include <chrono> //For recording short time
using namespace std;

//*************************************************************
// Definition of function showArray.                          *
// This function displays the contents of array. size is the  *
// number of elements.                                        *
//*************************************************************

void showArray(const int array[], int size){
    for (int count = 0; count < size; count++)
    cout << array[count] << " ";
    cout << endl;
}


//***********************************************************
// Definition of function sortArray                         *
// This function performs an ascending order BUBBLE SORT on *
// array. size is the number of elements in the array.      *
//***********************************************************

void sortArray(int array[], int size, float& C_arithm, float& C_compare, float& C_incr)
{
    bool swap;
    int temp;

    do
    {
        C_arithm++;
        swap = false;
        
        C_compare++;
        C_arithm+=2;
        for (int count = 0; count < (size - 1); count++)
        {
            C_compare++;
            C_arithm++;
            if (array[count] > array[count + 1])
            {
                C_arithm+=6;
                temp = array[count];
                array[count] = array[count + 1];
                array[count + 1] = temp;
                swap = true;
            }
            C_incr++;
        }
        C_compare++;
    } while (swap);
}

void runBubbleSort()
{
   
    //const int numRuns = 1;
    //float storeTime[numRuns];
   // float timeAve = 0.0;
    
    cout<<"\n**** Problem 2 - Bubble Sort ****\n";
    
    //for(int k = 1; k <= 8; k*=2){
        float C_arithm = 0.0;
        float C_compare = 0.0;
        float C_incr = 0.0;
    
    //    int N = 10000 * k;
          int N = 20000;
        cout<<"\nLet N = "<<N<<endl;
        // Array of unsorted values
        int *values = new int[N];

        cout<<"\nAssigning random integers to be sorted...\n";
        //Assigns random values to array
        for(int i; i < N; i++)
            values[i] = rand()%100+1;


        // Display the values.
        //cout << "The unsorted values are:\n";
        //showArray(values, N);

        cout<<"\nSorting values...\n";

        cout<<"\n--- Timer has Started ---\n";
        //for(int i = 0; i < numRuns; i++){
            //std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
            // Sort the values.
        
        int start = time(0);
        
        sortArray(values, N, C_arithm, C_compare, C_incr);

        int end = time (0);    
            //std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
            //std::chrono::duration<double, std::milli> time_span = t2 - t1;
          //  storeTime[i] = time_span.count();
        //}
        //for(int i = 0; i < numRuns; i++){
          //  timeAve += storeTime[i];
        //}

        //cout<<"\ntimeAve = "<<timeAve<<"\nnumRuns = "<<numRuns<<endl;
        cout<<"\n--- Ending has Ended ---\n";

        cout<<"\nArray has been sorted with Bubble Sort.\n";
        // Display them again.
        //cout << "The sorted values are:\n";
        //showArray(values, N);
        
       // cout << "Runtime =  " << timeAve/numRuns*100 << " seconds\n";
        
        cout << "Runtime = "<<end - start<<endl;
        cout<<"\nNumber of Arithmetic Operations = "<<C_arithm;
        cout<<"\nNumber of Compare Operations = "<<C_compare;
        cout<<"\nNumber of Increment Operations = "<<C_incr;
        cout<<"\nTotal Numbers of Operation = "<<C_arithm+C_compare+C_incr;
        cout<<"\n----------------------------------------------------\n";
        delete[] values;    //Deallocates array that holds values
    //}
    
    cout<<endl<<endl;
}




// This program uses the selection sort algorithm to sort an
// array in ascending order.

//**************************************************************
// Definition of function selectionSort. *
// This function performs an ascending order selection sort on *
// array. size is the number of elements in the array. *
//**************************************************************

//Using floats to prevent overflowing
void selectionSort(int array[], int size, float& cmp, float& equal, float& incr)
{
    int startScan, minIndex, minValue;

    cmp++;
    equal+=2;
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        equal+=2;
        minIndex = startScan;
        minValue = array[startScan];
        
        cmp++;
        equal+=2;
        for(int index = startScan + 1; index < size; index++)
        {
            cmp++;
            if (array[index] < minValue)
            {
                equal+=2;
                minValue = array[index];
                minIndex = index;
            }
            cmp+=1;
            equal+=2;
            incr++;
        }
        equal+=2;
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
        incr++;
        cmp+=2;
        equal++;
    }
}




void runSelectionSort()
{
    
    //const int numRuns = 1;
    //float storeTime[numRuns];
    //float timeAve = 0.0;
    
    cout<<"\n**** Problem 2 - Selection Sort ****\n";
    //for(int k = 1; k <= 8; k*=2){
        // Define an array with unsorted values
        //const int SIZE = 10000 * k;
          const int SIZE = 20000;
        cout<<"\n\tLet N = "<<SIZE<<endl;

        int *values = new int[SIZE];

        cout<<"\nAssigning Values to Array to be sorted by Selection Sort...\n";
        
        for(int i = 0; i < SIZE; i++)
            values[i] = rand()%100 + 1;

        // Display the values.
        //cout << "The unsorted values are\n";
        //showArray(values, SIZE);

        cout<<"\nSorting Array with Selection Sort...\n";
        
        cout<<"\n--- Timer has started. ---\n";
        
        //for(int i = 0; i < numRuns; i++){
            //Using float to prevent overflowing
            float cmp = 0.0;
            float equal = 0.0;
            float incr = 0.0;
            
            int start = time(0);
            //std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
            // Sort the values.
            selectionSort(values, SIZE, cmp, equal, incr);

            int end = time(0);
            //std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
            //std::chrono::duration<double, std::milli> time_span = t2 - t1;
            //storeTime[i] = time_span.count();
            //storeTime[i] = end - start;
        //}
        //for(int i = 0; i < numRuns; i++){
        //    timeAve += storeTime[i];
        //}

        cout<<"\n--- Timer has ended. ---\n";
        
        cout<<"\nSelection Sort completed.\n";
        
        // Display the values again.
        //cout << "The sorted values are\n";
        //showArray(values, SIZE);
        
        cout << "Runtime =  " << end - start << " seconds\n";
        
        cout<<"\nNumber of Compare Operations = "<<cmp;
        cout<<"\nNumber of Arithmetic (+, - , *, /, =) Operations = "<<equal;
        cout<<"\nNumber of Incrementing Operations = "<<incr;
        cout<<"\nTotal Number of Operations = "<<cmp + equal + incr<<endl;
        cout<<"\n----------------------------------------------------------------\n";
        
        
        delete[] values;    //Deallocate memory
    //}

}




