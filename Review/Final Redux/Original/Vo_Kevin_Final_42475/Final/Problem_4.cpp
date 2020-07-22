/* 
 * File:   Problem_4.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Final
 * Created on May 31, 2018, 8:31 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <array>
#include <chrono>

using namespace std;

const int sizeArr = 100000; //Holds the constant size of the full array

void printArray(int A[], int size);

void runSelectionSort(short *);
void selectionSort(short[], long long&, long long&, long long&);


void mergeSort(short[], int, int, long long*);
void merge(short[], int, int, int, long long *);
void printArray(short[], int);


void prob4(){
    cout<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"*            Problem 4 - Sorting            *"<<endl;
    cout<<"*********************************************"<<endl;
    
    enum {cmp, eq, incr};
    
    //Seed for random number generator
    srand(time(NULL));
    long long cntOpM[3] = {0, 0, 0};
    
    short arrMain[sizeArr];      //Allocate memory for unsorted array
    short arrSelect[sizeArr];
    
    const short maxForShort = 32767;
    
    for(int i = 0; i < sizeArr; i++){
        int tempShort = rand()%maxForShort;
        arrMain[i] = tempShort;
        arrSelect[i] = tempShort;
    }
    
    cout<<"\nLet Number of Elements = "<<sizeArr<<endl;
    
    cout<<"\n\n****** Generating list of random Short Integers ******\n";
    
    
    cout<<"\n\n====== Merge Sort Started ======\n";
 
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    mergeSort(arrSelect, 0, sizeArr - 1, cntOpM);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_span = t2 - t1;
    
    cout<<"\n\tRuntime for Merge Sort = "<<time_span.count()/1000<<" seconds"<<endl;
    cout<<"\n\tFirst 10 p of Merge Sort: ";
    printArray(arrSelect, 10);
    
    cout<<"\nOperations for Merge Sort\n";
    cout<<"----------------------------";
    cout<<"\nNumber of Compare Operations = "<<cntOpM[cmp];
    cout<<"\nNumber of Arithmetic (+, - , *, /, =) Operations = "<<cntOpM[eq];
    cout<<"\nNumber of Incrementing Operations = "<<cntOpM[incr];
    cout<<"\nTotal Number of Operations = "<<cntOpM[cmp] + cntOpM[eq] + cntOpM[incr]<<endl;
    cout<<"\n----------------------------------------------------------------\n";
        
    
    cout<<"\n\n====== Selection Sort Started ======\n";
    runSelectionSort(arrSelect);
}



void merge(short arr[], int l, int m, int r, long long *op){
    enum {cmp, eq, incr};
    
    op[eq] += 5;
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], 
        R[n2];
 
    op[cmp]++;
    op[eq]++;
    op[incr]++;
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
        op[incr]++;
        op[cmp]++;
        op[eq]+= 2;
        
    }
    op[cmp]++;
    op[incr]++;
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
        op[eq]+=3;
    }
    op[eq]+=3;
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    
    op[cmp]+=2;
    while (i < n1 && j < n2){
        op[cmp]++;
        if (L[i] <= R[j])
        {
            op[eq]++;
            op[incr]++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            op[eq]++;
            op[incr]++;
            arr[k] = R[j];
            j++;
        }
        op[incr]++;
        k++;
        op[cmp]+=2;
        
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    op[cmp]++;
    while (i < n1)
    {
        op[eq]++;
        op[incr]+=2;
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    op[cmp]++;
    while (j < n2){
        
        op[eq]++;
        op[incr]+=2;
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(short arr[], int l, int r, long long *op){
    enum {cmp, eq, incr};
    op[0]++;
    if (l < r){
        op[1]+=4;
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m, op);
        mergeSort(arr, m+1, r, op);
 
        merge(arr, l, m, r, op);
    }
}
 
//Prints the array
void printArray(short A[], int size){

    for (int i = 0; i < size; i++)
        cout<<A[i]<<" ";
    cout<<endl;
}














//==================================================================================================================================

// This program uses the selection sort algorithm to sort an
// array in ascending order.

//**************************************************************
// Definition of function selectionSort. *
// This function performs an ascending order selection sort on *
// array. size is the number of elements in the array. *
//**************************************************************

//Using long long to prevent overflowing
void selectionSort(short *array, long long& cmp, long long& equal, long long& incr)
{
    int startScan, minIndex, minValue;

    cmp++;
    equal+=2;
    for (startScan = 0; startScan < (sizeArr - 1); startScan++)
    {
        equal+=2;
        minIndex = startScan;
        minValue = array[startScan];
        
        cmp++;
        equal+=2;
        for(int index = startScan + 1; index < sizeArr; index++)
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




void runSelectionSort(short* values){
    
    //Using long long to prevent overflowing
    long long cmp = 0;
    long long equal = 0;
    long long incr = 0;

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    // Sort the values.
    selectionSort(values, cmp, equal, incr);

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_span = t2 - t1;


  
    cout<<"\n\tRuntime for Selection Sort = "<<time_span.count()/1000<<" seconds"<<endl;

    // Display the values again.
    cout << "\n\tFirst 10 p of Selection Sort: ";
    printArray(values, 10);


    cout<<"\nOperations for Selection Sort\n";
    cout<<"--------------------------------";
    cout<<"\nNumber of Compare Operations = "<<cmp;
    cout<<"\nNumber of Arithmetic (+, - , *, /, =) Operations = "<<equal;
    cout<<"\nNumber of Incrementing Operations = "<<incr;
    cout<<"\nTotal Number of Operations = "<<cmp + equal + incr<<endl;
    cout<<"\n----------------------------------------------------------------\n";


}
