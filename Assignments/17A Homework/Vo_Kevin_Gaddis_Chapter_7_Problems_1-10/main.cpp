/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Chapter: Gaddis Chapter 7
 * Problem 1 -> Finds the smallest and largest array values
 * Problem 2 -> Displays rainfall statistics for a year
 * Problem 3 -> Stores and displays amount of salsa sold
 * Problem 4 -> Calculates how much a monkey/family of monkeys food consumption
 * Problem 5 -> Measures the days of the summer's months weather
 * Problem 6 -> Find analysis a series of numbers
 * Problem 7 -> Displays quarterly sales of six divisions
 * Problem 8 -> Finds the pay role of employees by their ID number
 * Problem 9 -> Driver's License Exam with answer checker
 * Problem 10 -> Exam Grade of 20 multiple-choice questions
 * Created on May 16, 2012, 5:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
//variables for Problem 5 (Rain or Shine) global
const int month = 3, day = 30;
//Function prototypes -> Problem 5 (Rain or Shine)
int Problem5RainMain();
void DataReader(char arr[][day], int NUM);
void MonthReportDisplay(char arr[][day], int NUM);
void totalMonth(char arr[][day], int NUM);
void mostRainMonth(char arr[][day], int NUM);
//Problem 6 Prototype (Number Analysis Program)
int Problem6Func();
int highestFunc(int[], int);
int lowestFunc(int[], int);
int sumFunc(int[], int);
int avgFunc(int[], int);
//Problem 7 function prototype
int Problem7Func();
//Problem 8 function prototype
int Problem8Func();
//Function prototype for Problem 9 "Driver's License Exam"
int Problem9Func();
void answerCheck(char[], char[], int, int);
//Function prototype for Problem 10
int Problem10Func();
void Data(char[],char[]);
void answerCheckProblem10(char[],char[]);


int main(int argc, char** argv) {
    int choice;
    bool loop = true;
    do{
    cout<<"\nPlease type in the numbers 1-10 to select from the menu.\n";
    cout<<"Type 1 for problem #1\n";
    cout<<"Type 2 for problem #2\n";
    cout<<"Type 3 for problem #3\n";
    cout<<"Type 4 for problem #4\n";
    cout<<"Type 5 for problem #5\n";
    cout<<"Type 6 for problem #6\n";
    cout<<"Type 7 for problem #7\n";
    cout<<"Type 8 for problem #8\n";
    cout<<"Type 9 for problem #9\n";
    cout<<"Type 10 for problem #10\n";
    cin>>choice;
 
    switch(choice){
    
        case 1:{
            const int Nine = 9;
            int x; //x represents the amount of iterations for the for loops 
            float inputValue[Nine], highest, lowest;
            
            //Displayed prompt
            cout<<"*** Largest/Smallest Array Value ***\n\n";
            cout<<"This program will search and display the smallest and largest"
                <<" value\nfrom the set of 10 digits that are entered.\n";
            
            //for loop for entering values to array var.
            for (x=0; x<=Nine; x++){
                
                cout<<"Enter in value #"<<(x + 1)<<": ";
                cin>>inputValue[x];
            }
            //setting var. low. and high. to the first value inputed
            highest = inputValue[0];
            lowest = inputValue[0];
            
            //cycles through the set of values to find the highest & lowest
            for (x = 0; x<=Nine; x++){
                
            if (inputValue[x]>highest){
                highest = inputValue[x];}
                
            if (inputValue[x]<lowest){
                lowest = inputValue[x];
                }
            }
            //display of the result
            cout<<"Highest: "<<highest<<endl;
            cout<<"Lowest: "<<lowest<<endl;
        };break;
    
        case 2:{
            const int month = 11;
            float rainfall[month], TOTAL = 0.0, avgRain, highest, lowest;
            int count;
            //prompt
            cout<<"This program will calculate and display the total amount of "
                <<"rainfall for a year, average monthly rainfall, and highest "
                <<"and lowest amounts.\n";
            
            //for loop for array input & calculations
            for (count=0; count<=month;count++){
                
                cout<<"Please enter total amount of rainfall for month #"
                    <<(count + 1)<<": ";
                cin>>rainfall[count];
                
                //Input Validation checker
                if (rainfall[count]<0){
                        cout<<"Input Validation: Do not accept numbers for "
                            <<"monthly rainfall figures.";
                  exit (0);}
                //calculations for total, highest, and lowest value
                TOTAL += rainfall[count];
                
                highest = rainfall[0];
                lowest = rainfall[0];
                
                if (rainfall[count]>highest){
                    highest = rainfall[count];
                }
                
                if (rainfall[count]<lowest){
                    lowest = rainfall[count];
                }                 
            }
            
            avgRain = TOTAL/12;//calculation for total value
            //result output
            cout<<"Total Rainfall: "<<TOTAL<<endl;
            cout<<"Average Rainfall: "<<avgRain<<endl;
            cout<<"Highest Amount of Rainfall: "<<highest<<endl;
            cout<<"Lowest Amount of Rainfall: "<<lowest<<endl;
            
        };break;
        
        case 3:{
            const int FIVE = 5;
            int jarSold[FIVE], count, total = 0, highest, lowest;
            string salsaName[] ={"Mild", "Medium", "Sweet", "Hot", "Zesty"},
                    highestName, lowestName;
            
            
           //prompt
            cout<<"This program will provide sales of each salsa type, total "
                <<"sales, and the names of the highest and lowest selling "
                <<"salsa.\n";
            //find 
            for (count = 0; count < FIVE; count++){
                
                cout<<"Enter in the number of jars sold for salsa "<<salsaName[count]<<": ";
                cin>>jarSold[count];
                
                if(jarSold[count]<0){//check input
                    cout<<"Input Validation: Do not accept negative values for "
                        <<"number of jars sold.\n";
                exit (0);}
                
                total += jarSold[count];        
            }
            
            //finds the highest and lowest
            
            highest = 0;
            lowest = 0;
            int NameOfHighest;
            for (count = 0; count < 5; count++){
                
                //finds the lowest sold jars
                if (jarSold[count]>highest){ 
                    highest=jarSold[count];
                    
                }
                
                if(jarSold[count]<lowest){
                    lowest = count;
                }

            
            }

            //Output display
            cout<<"--- Results ---\n";
            
            for (count = 0; count< FIVE; count++){
                cout<<"Salsa: "<<salsaName[count]<<" --> Sold: "<<jarSold[count]
                        <<endl;
            }
            cout<<"Total Sales: "<<total<<" jars\n";
            cout<<"Highest Units Sold: "<<salsaName[highest]<<endl;
            cout<<"Lowest Units Sold: "<<salsaName[lowest]<<endl;
        };break;  
   
        case 4:{
            const int row = 3, column = 6;//row = monkeys, column = days of week
            float monkey[row][column], total1=0.0, total2=0.0, total3=0.0, avg,
                    GREATESTeat;
            int count;
            
            cout<<"This program will calculate 3 different monkey's food consumption "
                <<"rate in bounds.\n";
            //cins for array inputs
            for (count = 0; count <=column; count++){
                cout<<"How much did monkey #1 eat on day "<<(count + 1)<<": ";
                cin>>monkey[1][count];
                total1+=monkey[1][count];
                
                if(monkey[1][count]<0){
                    cout<<"Input Validation: Do not accept negative numbers for pounds of food.\n";
                }
            }
            
            for(count = 0; count <=column; count++){
                cout<<"How much did monkey #2 eat on day "<<(count + 1)<<": ";
                cin>>monkey[2][count];
                total2+=monkey[2][count];
                
                if(monkey[2][count]<0){
                    cout<<"Input Validation: Do not accept negative numbers for pounds of food.\n";
                }
            }   
            
            for (count=0;count<=column;count++){
                cout<<"How much did monkey #3 eat on day "<<(count + 1)<<": ";
                cin>>monkey[3][count];
                total3+=monkey[3][count];
                
                if(monkey[3][count]<0){
                    cout<<"Input Validation: Do not accept negative numbers for pounds of food.\n";
                }
            }
            avg=total1+total2+total3/row;
            
            float highest = monkey[1][0], highest2 = monkey[2][0], highest3 
                = monkey[3][0];
            //Find the highest and least
            for (count=0;count<=column;count++){
                
                if (monkey[1][count]>highest){
                    highest=monkey[1][count];
                }
                if (monkey[2][count]>highest2){
                    highest2=monkey[2][count];
                }
                if (monkey[3][count]>highest3){
                    highest3=monkey[3][count];
                }

            }
            
          for(count=0;count<=column;count++){
                   
                if (highest>highest2 && highest>highest3){
                    GREATESTeat = highest;
                }
                else if (highest2>highest && highest2>highest3){
                    GREATESTeat = highest2;
                }
                else if (highest3>highest && highest3>highest2){
                    GREATESTeat = highest3;
                }
          }
            float LEASTATE;
            for (count = 0; count<=column;count++){
            if (highest<highest2 && highest<highest3){
                    LEASTATE = highest;
                }
                else if (highest2<highest && highest2<highest3){
                    LEASTATE = highest2;
                }
                else if (highest3<highest && highest3<highest2){
                    LEASTATE = highest3;
                }
            }    
                
            
            //Output Display
            cout<<"Average Consumption (whole family): "<<avg<<endl;
            cout<<"Least Amount Consumed: "<<LEASTATE<<endl;
            cout<<"Greatest Amount Consumed: "<<GREATESTeat<<endl;
            
        };break;
        
        case 5:{
        Problem5RainMain(); 
        };break;
        
        case 6:{
            Problem6Func();
        };break;
        
        
        case 7:{
            Problem7Func();
        };break;
        
        case 8:{
            Problem8Func();
        };break;
        
        case 9:{
        Problem9Func();
        };break;
        
        case 10:{
            Problem10Func();
        };break;
                
                
    }
    
    }while(loop = true);
    return 0;
}

int Problem5RainMain(){

       
       //prompt
       cout<<"This program will examine the RainOrShine.dat file then "
           <<"conducts a report from the examined data.\n";
        
 
//Function callers for problem 5 prototypes
	char weatherReport[month][day];
    
	DataReader(weatherReport, month);
	MonthReportDisplay(weatherReport, month);



	return 0;}

void DataReader(char arr[][day], int NUM)
{
	//This part of the program opens the file
	ifstream DatFile("RainOrShine.dat");
	if (!DatFile)
	{
		cout << "Sorry cannot find the RainOrShine.dat file." << endl;
		
                exit(0);}


	//This part of the program reads the files
	for (int row = 0; row < NUM; row++)
	{
		for (int nCol = 0; (nCol < day) && (DatFile >> arr[row][nCol]); nCol++)
		{     
		}
	}
	//Closes the file after the program is done reading it.
	DatFile.close();
}

void MonthReportDisplay(char arr[][day], int NUM)
{
	cout << "***Results ***\n";
int rain = 0, cloud = 0, sun = 0, JuneRainCount = 0, JulyRainCount = 0,
                        AugRainCount = 0;
	for (int rows = 0; rows < NUM; rows++)
	{
		
	
		for (int column = 0; column < day; column++)
		{
			//counts how many days of each weather type
			if (arr[rows][column] == 'R')
				rain++;
			else if ((arr[rows][column] == 'C'))
				cloud++;
			else if ((arr[rows][column] == 'S'))
				sun++;
                        
                        if (arr [0][column] == 'R'){
                            JuneRainCount++;
                        }   
                        if (arr [1][column] == 'R'){
                            JulyRainCount++;
                        }
                        if (arr [2][column] == 'R'){
                            AugRainCount++;
                        }
                       
		}
                 
                     
		//Result Output
                cout<<"Note: 1 = June, 2 = July, 3 = August\n";
		cout<<"Month "<<(rows + 1)<<": \n";
		cout<<"Rain: "<<rain<<endl;
		cout<<"Cloudy: "<<cloud<<endl;
		cout<<"Sunny: "<<sun<<endl;
		
	}

if (JuneRainCount > JulyRainCount && JuneRainCount > AugRainCount){
                        
                     cout<<"June has the highest days of rain.\n";                          
                        }
                 else if(JulyRainCount>JuneRainCount && JulyRainCount > AugRainCount){
                        cout<<"July has the highest days of rain.\n";
                 }
                 else{
                     cout<<"August has the highest days of rain.\n";
                 }
}

//Problem 6: "Number Analysis Program"
int Problem6Func(){
const int arrNUM = 12; 
int numbers[arrNUM], sum, avg, highest, lowest, count; 
ifstream File; 
File.open("numbers.txt");


// Read the 10 numbers from the file into the array.
for (count = 0; count < arrNUM; count++)
File >> numbers[count];


//Calculations for displays
highest = highestFunc(numbers, arrNUM);
lowest = lowestFunc(numbers, arrNUM);
sum = sumFunc(numbers, arrNUM);
avg = avgFunc(numbers, arrNUM);

//Result Output Display
cout<<"*** Results ***\n";
cout<<"Highest Value: "<<highest<<endl;
cout<<"Lowest Value: "<<lowest<<endl;
cout<<"Total Sum: "<<sum<< endl;
cout<<"Average: "<<avg<<endl;


//Closes the file 
File.close();

return 0;}

//Finds the lowest
int lowestFunc(int numbers[], int arrNUM)
{

int lowest;
lowest = numbers[12];
for (int count = 1; count < arrNUM; count++)
{
if (numbers[count] < lowest)
lowest = numbers[count];
}
return lowest;
}

//finds the highest
int highestFunc(int numbers[], int arrNUM)
{
int highest;

highest = numbers[12];
for (int count = 1; count < arrNUM; count++)
{
if (numbers[count] > highest)
highest = numbers[count];
}
return highest;

}

//adds all the of the numbers up
int sumFunc(int numbers[], int arrNUM)
{
int total = 0;

for (int count = 0; count < arrNUM; count++)
total += numbers[count];
return total;
}

//averages all of the summed numbers
int avgFunc(int numbers[], int arrNUM)
{
int total = 0, average; 

for (int count = 0; count < arrNUM; count++)
total += numbers[count];

average = total/arrNUM;
return average;
}

//Problem 9 "Driver's License Exam"
int Problem9Func(){
        const int numQ = 20, min= 15;
        int corAnswers= 0, incorAnswers= 0, answer; 
        char answers[numQ] = { 'B', 'D', 'A', 'A', 'C','A', 'B', 'A', 'C', 'D',
        'B', 'C', 'D', 'A', 'D', 'C', 'C', 'B', 'D', 'A'}, inputAnswer[numQ];

        //Loop for users answers
        for (answer = 0; answer < numQ; answer++){
                cout<< "Input Answer "<<(answer + 1)<<": ";
                cin>>inputAnswer[answer];

//Validation of users answers
while (inputAnswer[answer] != 'A' && inputAnswer[answer] != 'B' && 
        inputAnswer[answer] != 'C' && inputAnswer[answer] != 'D')
{
cout<<"Invalid Input: Only accept the letters A, B, C, or D as answers.\n";

cout<<"Input Answer "<<(answer + 1)<<": ";
cin>>inputAnswer[answer];
}

}
answerCheck(answers, inputAnswer, numQ, min);

return 0;}

void answerCheck(char answers1[], char inputAnswer1[], int numQ, int min)
{

int corAnswers= 0, incorAnswers= 0, j = 0;
int wrongAnswers[]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


//checks for the right and wrong answers
for (int i = 0; i < numQ; i++)
{
if (answers1[i] == inputAnswer1[i])
corAnswers++;
else if (answers1[i] != inputAnswer1[i])
{
incorAnswers++;
wrongAnswers[j] = i + 1;
j++;
}
}
//Output display of passes and fail
if (corAnswers>= min)
{
cout<<"\nCongratulations you have passed the exam.\n";
}
else
{
cout<<"\nSorry you need at least 15 answers correct to pass.\n";
}
//Output display of questions gotten wrong
cout<<"*** Questions that are wrong ***\n";
for (int count = 0; count < numQ; count++)
{
if (wrongAnswers[count] != 0)
cout<<"Question # "<<wrongAnswers[count]<<" is incorrect."<<endl;
}
//Output display of exam result
cout<<"\nCorrect Answers: " <<corAnswers<<"\nIncorrect Answers: "<<incorAnswers<<endl;
}

//Problem 7 Quarterly Sales Statistic
int Problem7Func(){

            const int cSales = 4, cDivisions = 6;
            int sales, div;
            float input[cDivisions][cSales], total = 0.0, avg;
            
            //prompt
            cout<<"This program will calculate and display results from quarterly";
            cout<<"\nsales figures of six different divisions of a company.\n";
 
            //for loop for user input
            for (div = 0; div < cDivisions; div++){
                for (sales = 0; sales < cSales; sales++){
                        cout<<"Division "<<(div + 1)<<", Quarter "<<(sales+1)<<": $";
                        cin>>input[div][sales];
                        }
                
                if(input[sales][div] < 0){
                
                    cout<<"Input Validation: Do not accept negative numbers for sales figures.\n";
      
                        exit (0);}
                            
                }

            //Quarter 1 
            float totalD1 = 0.0, totalD2 = 0.0, totalD3 = 0.0, totalD4 = 0.0, 
                    totalD5 = 0.0, totalD6 = 0.0, avg1, avg2, avg3, avg4, avg5, 
                    avg6, highest1, highest2, highest3, highest4, highest5,
                    highest6;
            

            for (div = 0; div < cDivisions; div++){
                for (sales = 0; sales < cSales; sales++){
                    totalD1 += input[div][sales];
                   //Sales figure 
                   totalD1 = input[0][sales]+input[0][sales]+input[0][sales]+input[0][sales];
                   totalD2 = input[1][sales]+input[1][sales]+input[1][sales]+input[1][sales];
                   totalD3 = input[2][sales]+input[2][sales]+input[2][sales]+input[2][sales];
                   totalD4 = input[3][sales]+input[3][sales]+input[3][sales]+input[3][sales];
                   totalD5 = input[4][sales]+input[4][sales]+input[4][sales]+input[4][sales];
                   totalD6 = input[5][sales]+input[5][sales]+input[5][sales]+input[5][sales];
                }
            }
            
                for (div = 0; div < cDivisions; div++){
                for (sales = 0; sales < cSales; sales++){
                        avg1 = totalD1/6;
            
                           cout<<"---Quarter "<<div<<"---\n";
                           cout<<"Sales Figure by Division:\n";
                           cout<<"     Division 1: "<<input[div][sales]<<endl;
                           cout<<"     Division 2: "<<input[div][sales]<<endl;
                           cout<<"     Division 3: "<<input[div][sales]<<endl;
                           cout<<"     Division 4: "<<input[div][sales]<<endl;
                           cout<<"     Division 5: "<<input[div][sales]<<endl;
                           cout<<"     Division 6: "<<input[div][sales]<<endl;
                           cout<<"Total Sales: $"<<totalD1<<endl;
                           cout<<"Average Sale: $"<<avg1<<endl;
                           cout<<"Division w/ Highest Sales: Division "<<highest1<<endl;
                }
            }
    return 0;}

//function for problem 8 "Payroll"
int Problem8Func(){int count, empld[7] = {5658845,4520125,7895122,8777541,8451277,
1302850, 7580489};
float rate, hour, wage[7];

for(count=0;count<=6;count++)
{
cout<<"Employee ID: "<<empld[count]<<endl;

cout<<"Please enter Employee's Hour:  ";
cin>>hour;
cout<<"Please enter Employee's Pay Rate: ";
cin>>rate;

wage[count] = hour * rate;
}

for(count=0;count<=6;count++)
{
cout<<"Employee ID: "<<empld[count]<<endl;
cout<<"Employee's Gross Wager: "<<fixed<<showpoint<<setprecision(2)<<wage[count]<<endl;
}


return 0;
}
//Problem 10 function

int Problem10Func(){
int wrong;
char right[20], answer[20];
Data(right,answer);
answerCheckProblem10(right,answer);  
return 0;}


void Data(char r[],char a[])
{int i;
ifstream File;
File.open("CorrectAnswers.txt");
if(File.fail()) 

       { cout<<"Sorry cannot find file CorrectAnswers.txt\n";
        exit (0);
        }
for(i=0;i<20;i++)

   File>>r[i];
File.close();
File.open("StudentAnswers.txt");

 if(File.fail())  

       { cout<<"Sorry cannot find file StudentAnswers.txt\n";
        exit (0);
       }

for(i=0;i<20;i++)

   File>>a[i];

File.close();
}


void answerCheckProblem10(char row[],char a[])
{
int wrong=0,count;
cout<<"wrong answers\n";


 for(count=0;count<20;count++)
   if(row[count]!=a[count])

    {cout<<count<<"\t"<<a[count]<<"\t"<<row[count]<< endl;
    wrong++;
}

 if(wrong==0)
      cout<<"Congratulations, your answers are flawless!\n";  
 else
      cout<<"Sorry you have "<<wrong<<" wrong answers\n";
      cout<<"Your grade is "<<(100-wrong)/2000<<"%\n";
}

