/* 
 * File:   Prob1_LinearBinary.cpp
 * Author: Kevin Vo
 * Course: CSC-17C
 * Assignment: Midterm
 * Problem: #1
 * Created on April 19, 2018, 11:43 PM
 */

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <cmath>


using namespace std;

//*****************************************************************
// The searchList function performs a linear search on an         *
// integer array. The array list, which has a maximum of numElems *
// elements, is searched for the number stored in value. If the   *
// number is found, its array subscript is returned. Otherwise,   *
// -1 is returned indicating the value was not in the array.      *
//*****************************************************************
 int searchList(const int list[], int numElems, int value, float &C_compare, float &C_equal, float &C_incr)
 {
    C_equal+=3;
    int index = 0; // Used as a subscript to search array
    int position = -1; // To record position of search value
    bool found = false; // Flag to indicate if the value was found
    
    C_compare+=2;
    while (index < numElems && !found){
        C_compare++;
        if (list[index] == value) // If the value is found
        {
            C_equal+=2;
            found = true; // Set the flag
            position = index; // Record the value's subscript
        }
        C_incr++;
        index++; // Go to the next element
        C_compare+=2;
    }

    
    return position; // Return the position, or -1
}
 

//Runs the linear search from Gaddis book 
void runLinear(){
    float C_compare = 0.0;
    float C_equal = 0.0;
    float C_incr = 0.0;
     
    cout<<"\n**** Problem 1 - Linear Search ****\n"; 
     
    for(int k = 1; k <= 8; k *= 2){
        int SIZE = 1000000 * k;

        cout<<"\nLet N = "<<SIZE<<endl;

        const int numRuns = 1;
        float *storeTime = new float[numRuns];
        float timeAve = 0.00;
        const int findVal = -1;  

        int *tests = new int[SIZE];

        int results;

        for(int i = 0; i < SIZE; i++){
            tests[i] = rand()%100 + 1;
        }

        for(int x = 0; x < numRuns; x++){
           
            
            std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
            
            // Search the array for findVal
            results = searchList(tests, SIZE, findVal, C_compare, C_equal, C_incr);
            
            std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
            storeTime[x] = time_span.count();

            

        }

        for(int i = 0; i < numRuns; i++){
            timeAve += storeTime[i];
        }

        if(results == -1)
            cout<<"\nValue = "<<findVal<<" was not found!\n";
        
        cout << "Runtime =  " << timeAve/numRuns<< " seconds\n";
        cout<<"\nNumber of Compare Operations = "<<C_compare;
        cout<<"\nNumber of Equal (assigning values) Operations = "<<C_equal;
        cout<<"\nNumber of Incrementing Operations = "<<C_incr;
        cout<<"\nTotal Number of Operations = "<<C_compare + C_equal + C_incr<<endl;
        cout<<"\n----------------------------------------------------------------\n";
        delete[] storeTime;
        delete[] tests;
     }
    /*
    // If searchList returned -1, then 100 was not found.
    if (results == -1)
        cout << "You did not earn 100 points on any test\n";
    else
    {
        // Otherwise results contains the subscript of
        // the first 100 found in the array.
        cout << "You earned 100 points on test ";
        cout << (results + 1) << endl;
    }
     */
 }


 

//***************************************************************
// The binarySearch function performs a binary search on an     *
// integer array. array, which has a maximum of size elements,  *
// is searched for the number stored in value. If the number is *
// found, its array subscript is returned. Otherwise, -1 is     *
// returned indicating the value was not in the array.          *
//***************************************************************
int binarySearch(const int array[], int size, int value, float &C_compare, float &C_equal, float &C_incr)
{
    C_equal+=5;
    int first = 0, // First array element
    last = size - 1, // Last array element
    middle, // Midpoint of search
    position = -1; // Position of search value
    bool found = false; // Flag

    C_compare+=2;
    while (!found && first <= last)
    {
        C_equal+=3;
        middle = (first + last) / 2; // Calculate midpoint
        C_compare++;
        if (array[middle] == value) // If value is found at mid
        {
            C_equal+=2;
            found = true;
            position = middle;
        }
        else if (array[middle] > value){ // If value is in lower half
            C_compare++;
            C_equal+=2;
            last = middle - 1;
        }else{
            C_equal+=2;
            first = middle + 1; // If value is in upper half
        }
        C_compare+=2;
    }
    return position;
}


//Runs the binary search from Gaddis bok
void runBinary(){
    
    
    cout<<"\n**** Problem 1 - Binary Search ****\n";
    
    for(int k = 1; k <= 8; k*=2){
    float C_compare = 0.0;
    float C_equal = 0.0;
    float C_incr = 0.0;    
    
    int SIZE = 1000000 * k;
    const int numRuns = 1;

    cout<<"\n\tLet N = "<<SIZE<<endl;
    //float *storeTime = new float[numRuns];
    // Array with employee IDs sorted in ascending order.
    int *idNums = new int[SIZE];
    //float timeAve = 0.00;
    
    for(int i = 0; i < SIZE; i++)
        idNums[i] = i;

    int results; // To hold the search results
    const int empID = -1; // To hold an employee ID

    //int start_s = clock();
    
     cout<<"\n--- Timer Started ---\n";
    //for(int i = 0; i < numRuns; i++){
     //int start = 0;
        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        // Search for the ID.
        results = binarySearch(idNums, SIZE, empID, C_compare, C_equal, C_incr);
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        //int end = 0;
        cout<<"\n--- Timer Ended ---\n\n";
       // storeTime[i] = time_span.count();
       //cout<<"\nTIME = "<<end-start;
        cout<<"\nRuntime for Binary Search = "<<time_span.count()<<" seconds\n";
        
    //}
    
    /*
    for(int i = 0; i < numRuns; i++){
        timeAve += storeTime[i];
    }
    */
    // If results contains -1 the ID was not found.
    if (results == -1)
        cout << "That number does not exist in the array.\n";
     else
    {
        // Otherwise results contains the subscript of
        // the specified employee ID in the array.
        cout << "That ID is found at element " << results;
        cout << " in the array.\n\n";
    }
    
    //cout << "Runtime =  " << timeAve/numRuns << " seconds\n";


    cout<<"\nNumber of Compare Operations = "<<C_compare;
    cout<<"\nNumber of Math Operations (+, -, *, /, =) = "<<C_equal;
    cout<<"\nNumber of Incrementing Operations = "<<C_incr;
    cout<<"\nTotal Number of Operations = "<<C_compare + C_equal + C_incr<<endl;
    cout<<"\n----------------------------------------------------------------\n";

    delete[] idNums;
    //delete[] storeTime;
  
    }
}