/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Book: Gaddis 7th Edition
 * Problem 9.1 -> Dyn. allocates an int. array then return pointer to array. 
 * Problem 9.2 -> Test score prog. that dyn. allocates an array of test scores.
 * Problem 9.3 -> Test score prog. that drops the lowest score
 * Problem 9.4 -> Test score prog. that displays user names & score in order
 * Problem 9.5 -> Rewrites a function to use pointers instead of ref. variables
 * Prob. Mean, Medan, Mode ->
 * Created on September 20, 2014, 5:22 PM
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Function prototype for the menu.
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Prototype for prob. 1 that requires a pointer to be turned to the funct.
int *prob1ReturnPointer(int);

float averageFinder(int, float[]);
float *dynAlloArray(int);
float averageFinderWithoutLowest(int, float[]);
//Prototype for the function that sorts the score & string for problem 4
void sortScore(int *, int, string *);

//Prototype for function in problem 9.5
int doSomething(int *, int *);


//Function Prototypes for the mode, mean, and median problem
int *fillArray(int,int);
void printArray(int *,int,int);
void printMode(int *);
int *sort(int *,int);
int *mode(int *,int);
float mean(int *[],int const);
float median(int *[],const int);
void MEDIANarrSorter(int *[], int);


int main(int argc, char** argv) {

    int inN;
        do{
            Menu();
            inN=getN();
            switch(inN){
                case 1: problem1();break;
                case 2: problem2();break;
                case 3: problem3();break;
                case 4: problem4();break;
                case 5: problem5();break;
                case 6: problem6();break;
                default: def(inN);}
            }while(inN<7);
            return 1;
}


void Menu(){
    cout<<endl;
    cout<<"Type 1 for Problem 9.1\n";
    cout<<"Type 2 for Problem 9.2\n";
    cout<<"Type 3 for Problem 9.3\n";
    cout<<"Type 4 for Problem 9.4\n";
    cout<<"Type 5 for Problem 9.5\n";
    cout<<"Type 6 for the Mean, Medium, and Mode Problem\n";

}

int getN()
{
    int inN;
    
    cin>>inN;
    return inN;
}

//starts problem 1
void problem1(){
    int sizeProb1;
    cout<<"Array Allocator is a program that dynamically allocates an array "<< 
          "of integers.\nEnter the number of elements you wish to "<<
          "be allocated: ";
    cin>>sizeProb1;
          
    prob1ReturnPointer(sizeProb1);

    for (int count = 0; count < sizeProb1; count++){
        cout<<prob1ReturnPointer(count)<<endl;
} 
    
    
}

//returns pointers for prob. 1
int *prob1ReturnPointer(int arraySIZE){
    int *ptr=new int[arraySIZE]; 
return ptr;}

//starts prob. 2
void problem2(){
    int numStudent;
    float *score, avg;
    

    cout<<"How many scores will be entered? ";
    cin>>numStudent;
    
    score = dynAlloArray(numStudent);

    for (int count = 0; count < numStudent; count++){
        cout<<"\nEnter the score of student #"<<count+1<<": ";
        cin>>score[count];
        
        if (score[count] < 0){
            cout<<"Input Validation: Do not accept negative numbers for test "<<
                "scores."<<endl;
        }
    }
    avg = averageFinder(numStudent, score);
    
    cout<<"\nAverage Score: "<<setprecision(1)<<fixed<<avg<<endl;

    delete []score;  
    
}

//allocates the array dynamically
float *dynAlloArray(int numStud){
    float *score;
    
    if (numStud <=0)
        return 0;
        
        score = new float[numStud];
return score;}

//finds the average for prob. 2
float averageFinder(int amountStudent, float studScore[]){
    float total = 0.0, avgScore;

//loops to sum the every stud score with total
    for (int count = 0; count < amountStudent; count++){ 
        total += studScore[count];
    }
    avgScore = (total/amountStudent);
return avgScore;}

//starts prob. 3
void problem3(){
    int numStudent;
    float *score, avg;
    

    cout<<"How many scores will be entered? ";
    cin>>numStudent;
    
    score = dynAlloArray(numStudent);

    for (int count = 0; count < numStudent; count++){
        cout<<"\nEnter the score of student #"<<count+1<<": ";
        cin>>score[count];
        
        if (score[count] < 0){
            cout<<"Input Validation: Do not accept negative numbers for test "<<
                "scores."<<endl;
        }
            
    avg = averageFinderWithoutLowest(numStudent, score);
    
    }
        cout<<"\nAverage Score (without lowest): "<<setprecision(1)<<fixed<<avg
            <<endl;
            
        delete []score;    
}

//Finds the average test score without the lowest (prob. 3)
float averageFinderWithoutLowest(int amountStudent, float studScore[]){
    float total = 0.0, avgScore;
    float lowest = studScore[0];
    for (int count = 1; count < amountStudent; count++){
        if (studScore[count] < lowest){
            lowest = studScore[count];
        }
    }
    for (int count = 0; count < amountStudent; count++){ 
        total += studScore[count];
    }
    
    total-=lowest;
    
    avgScore = (total/(amountStudent-1));
return avgScore;}


void problem4(){
        int amountStud;//Stores value of students.

    //Requests the user to input the # of student to set the size of the array.
    cout<<"Enter the number of students: ";
    cin>>amountStud;

    //Defines the pointers that will be used to store the score & names of stud.
    int* score=new int[amountStud];
    string* nameStud=new string[amountStud];

    for (int studRotation=0; studRotation<amountStud; studRotation++){  
        cout<<"\nEnter the name of "<< studRotation + 1 <<" student: ";
        cin>>nameStud[studRotation];
        cout<<"\nEnter the score of the student: ";
        cin>>score[studRotation];
    }

    //Defines the pointers that will be used to store the score & names of stud.
    sortScore(score, amountStud, nameStud);

    cout<<"\nList of Scores in Order: \n";
    cout<<"=============================\n";

    for(int count = 0; count < amountStud; count++){
        cout<<"\nName:"<<nameStud[count]<<"\t\t"<<"Score: "<<score[count];
    }

    cout<<endl;

    //clears the memory from score
    delete [] score;
    cin.get();
}


//Sorts the score and name to develop a list
void sortScore(int *score, int studentSize, string *name){
    int sorter = 0, minIndex;
    int minScore;
    string minName;

    for(sorter; sorter<(studentSize-1);sorter++){
        minIndex=sorter;
        minScore=score[sorter];

        for(int index=sorter+1;index<studentSize;index++){
            if(score[index] < minScore){
                minScore = score[index];
                minIndex = index;
                minName = name[index];
            }
        }
        score[minIndex] = score[sorter];
        score[sorter] = minScore;
        name[minIndex] = name[sorter];
        name[sorter] = minName;
    }

}

//starts prob. 5
void problem5(){
int y, z, w;

    //Asks user for two digits where &y and &z will be the parameters
    cout<<"This program will has a function that uses pointers instead of "<<
        "reference variables.\n";
    cout << "Enter the first number: ";
    cin >> y;
    cout << "Enter the second number: ";
    cin >> z;

    w = doSomething(&y, &z);

    //Displays the answers that has been returned from int doSomething() funct.
    cout<<"= "<<w<<endl;
}

//The accepts the pointers *x and *y since it was converted from ref. variables
//to pointers
int doSomething(int *x, int *y){
    int temp=*x;

    *x= *y * 10;
    *y = temp * 10;
    return *x+*y;}

//starts the mean, median, mode problem
void problem6(){
    //Create the array
    const int size=109;
    int *a=fillArray(size,5);
    //Sort the array
    int *b=mode(a,size);
    //Print the result
    printArray(a,size,10);
    printMode(b);

//+++++MEDIAN PROBLEM+++++//
    //the array pointer for median
    int *ArrayPointer[size];			
    float displayMedianAnswer;
	//make array of pointers set to array
	for (int count = 0; count < size; count++)
		ArrayPointer[count] = &a[count];

	MEDIANarrSorter(ArrayPointer,size);


    displayMedianAnswer = median(ArrayPointer,size);

//Displays the median
    cout<<"Median = "<<displayMedianAnswer<<endl;

//++++Mean Problem++++//

mean(ArrayPointer, size);

float meanAnswer = mean(ArrayPointer, size);

//Displays the mean
cout<<"Mean = "<<meanAnswer<<endl;

    
//Deallocate memory and exit
    delete []a;
    delete []b;
}


void printMode(int *m){
    //Print the mode array
    cout<<"Number of modes = "<<m[0]<<endl;
    cout<<"The frequency of the modes = "<<m[1]<<endl;
    if(m[0]==0){
        cout<<"The mode set = {0}"<<endl;
    }else{
        cout<<"The mode set = {";
            for(int i=2;i<m[0]+1;i++){
                cout<<m[i]<<",";
        }
    cout<<m[m[0]+1]<<"}"<<endl;
    }
}


int *sort(int *a,int n){
    //Allocate a sortable array
    int *b=new int[n];
    //Copy the array
    for(int i=0;i<n;i++){
    b[i]=a[i];
    }
    //Sort the array
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]>b[j]){
            b[i]=b[i]^b[j];
            b[j]=b[i]^b[j];
            b[i]=b[i]^b[j];
            }
        }
    }
return b;
}


int *mode(int *a,int n){
    //Create a parallel array to sort
    int *b=sort(a,n);
    //Count to max frequency
    int count=0,maxFreq=0;

    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
        count++;
        if(maxFreq<count)maxFreq=count;
        }else{
        count=0;
        }
    }
    cout<<"Max Freq = "<<maxFreq+1<<endl;
    //Count number of modes
    count=0;
    
    int nmodes=0;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            count++;
            if(maxFreq==count)nmodes++;
        }else{
        count=0;
        }
    }

    cout<<"Number of Modes = "<<nmodes<<endl;

    //Declare and fill the mode array
    int *mode=new int[nmodes+2];
        mode[0]=nmodes;
        mode[1]=maxFreq+1;
        nmodes=2;
    count=0;
    
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            count++;
            if(maxFreq==count)mode[nmodes++]=b[i];
        }else{
            count=0;
        }
    }

    //Clean up and return
    delete []b;
return mode;
}


//Prints the list of array
void printArray(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}


int *fillArray(int n,int mod){
    //Allocate memory
    int *array=new int[n];
    
    //Initialize with
    for(int i=0;i<n;i++){
        array[i]=i%mod;
    }
return array;
}



//Sorts the array for the median
void MEDIANarrSorter(int *ArrayPointer[], int size)
{
	int finder, indexLowest;
	int *minElem;

	for (finder = 0; finder < (size -1);finder++)
	{
		indexLowest = finder;
		minElem = ArrayPointer[finder];
		for(int index = finder + 1; index < size; index++)
		{
			if (*(ArrayPointer[index]) < *minElem)
			{
				minElem = ArrayPointer[index];
				indexLowest = index;
			}
		}
		ArrayPointer[indexLowest] = ArrayPointer[finder];
		ArrayPointer[finder] = minElem;
	}
}





//Finds the median of array and then returns it
float median(int *ArrayPointer[], const int size){

	int middlePlace;	
	float medianAnswer; 	
	middlePlace = size / 2.0;
        
        //If the size of the array is an even number it will do this.
	if (size % 2)
	{
		medianAnswer = 
            (*ArrayPointer[middlePlace] + *ArrayPointer[middlePlace + 1]) / 2.0;

	}else{
        //if the size of the array is an odd number it will just display this
                medianAnswer = *(ArrayPointer[middlePlace]);
                }
return medianAnswer;}





//Finds the mean and returns it
float mean(int *ArrayPointer[],int const size){
    float sum = 0.0, average = 0.0;
    
    for (int count = 0; count < size; count++){
        sum += *ArrayPointer[count];
        }
        average = sum/size;
    return average;
}


void def(int inN)
{
   cout<<"You typed "<<inN<<" to exit the program"<<endl;
}