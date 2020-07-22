/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Purpose: Using menu for challenge selection
 * Problem 1 -> Find sums for all integers from 1 - 50
 * Problem 2 -> Displays ASCII Codes from 1 - 127
 * Problem 3 -> Displays a chart of ocean level in 25 yrs
 * Problem 4 -> Amount of calories burned for every 5 mins from 10 - 30 mins
 * Problem 5 -> Displays increased charge rate of a country club
 * Problem 6 -> Displays the distance traveled by hour
 * Problem 7 -> Display the total amount and value of pennies
 * Problem 8 -> Generates math problems on +,-,*,/
 * Problem 9 -> Calculates total amount of rooms and occupancies of a hotel
 * Problem 10 -> Shows the average of rainfall based on input amount of years
 * Created on May 03, 2012, 6:18 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    bool loop=true;
    char Banking_Restart;
    int Sel;
    //Do-while loop to restart program of usage
     do{
        cout<<"\n***********************\n";
        cout<<"Type 1 to solve problem 1\n";
        cout<<"Type 2 to solve problem 2\n";
        cout<<"Type 3 to solve problem 3\n";
        cout<<"Type 4 to solve problem 4\n";
        cout<<"Type 5 to solve problem 5\n";
        cout<<"Type 6 to solve problem 6\n";
        cout<<"Type 7 to solve problem 7\n";
        cout<<"Type 8 to solve problem 8\n";
        cout<<"Type 9 to solve problem 9\n";
        cout<<"Type 10 to solve problem 10\n";
        cout<<"Type anything else to quit with no solutions.\n";
        cin>>Sel;
   //Switch statement for selection menu
switch (Sel){
case 1:{
    
 int numInput, startingNum = 0, x;
 
 cout<<"*** Gaddis Problem 5.1 (Sum of Numbers) ***\n\n";
 
 //Request for user input
   cout<<"Please enter a positive integer value to find the sum of numbers from"
       <<" one to the inputed value.\nUser Input: ";
    cin>>numInput;
    
    //if statement for invalid input
    if (numInput < 0)
    {
        cout<<"Input Validation: Do not accept a negative starting number.\n";
    }
    else
    {
        for(x=1;numInput >= x; x++)//For loop for summing up money
        {
            startingNum+=x;
            cout<<startingNum<<endl;
        }
        cout<<"^^^^ The Total\n";//output indicating the total
            
    }
                };break; 
                
                
case 2:{
             
    cout<<"*** Gaddis Problem 5.2 (Characters for the ASCII Codes) ***\n\n";
    //Request for user to hit enter to run the program
    cout<<"Press enter to run the program...";
    cin.ignore();
    cin.get();
    
    //defining variables for actual program
    int ASCIIdisplayer, rowDisplayAmount = 0;
    
    //for loop to display all of the chars. up to 128
    for (ASCIIdisplayer=0; ASCIIdisplayer<=127; ASCIIdisplayer++)
    {
        cout<<(char)ASCIIdisplayer<<" ";//converts to char 
        rowDisplayAmount++;//adds 1 to rowDisplayAmount for every loop
        if (rowDisplayAmount == 16)//Restricts each row to 16, if any higher the
        {                          // character turns to space and jumps a line
            rowDisplayAmount = 0;
            cout<<endl;
        }
    }
    
    
    
    
   int numInput, startingNum = 0, x;
    
   cout<<"*** Gaddis Problem 5.2 (Characters for the ASCII Codes) ***\n\n";
   
   cout<<"Please enter a positive integer value to find the sum of numbers from"
       <<" one to the inputed value.\nUser Input: ";
    cin>>numInput;
    
    if (numInput < 0)
    {
        cout<<"Input Validation: Do not accept a negative starting number.\n";
    }
    else
    {
        for(x=1;numInput >= x; x++)
        {
            startingNum+=x;
            cout<<startingNum<<endl;
        }
        cout<<"^^^^ The Total\n";
            
    }    
                };break; 
                
case 3:{
                    
    short numOfYears=1;
    int i;
    float seaLevel = 1.5, totalSeaLvl;
    
    cout<<"*** Gaddis Problem 5.3 (Ocean Levels) ***\n\n";
    
    //displayed prompt for the program
    cout<<"This program that will display a chart showing the ocean's level at\n"
        <<"its current rate of 1.5 millimeters per year for the next 25 years."
        <<endl<<endl;    
    
    //Requests user to hit enter to run the actual program
    cout<<"Press enter in order to display the chart...";
    cin.get();
    
    //the actual program itself
    cout<<"\nNumbers of Years .......... Total Sea Level\n";
    for(i=1; i <= 25; i++){//i represents the counter up until 25
        totalSeaLvl += seaLevel; 
        cout<<"In "<<numOfYears++<<" years ..................... "<<totalSeaLvl
                <<endl;
    }
                
                };break; 
                
case 4:{
    
    int mins = 10;
    const int MinIncreasedRate = 5;
    float TotalCal;
    const float CalPerMin = 3.9;

    cout<<"*** Gaddis Problem 5.4 (Calories Burned) ***\n\n";
    
    //Output prompt of the program
    cout<<"Considering when running on the treadmill on average 3.9 calories "
        <<"will be burnt every minute.\nThis program will display the amount "
        <<"every 5 minutes starting from 10.\n\n";  
    //do while loop will continue to iterate the program as long as its under 30 mins
    do{
        TotalCal = mins*CalPerMin;//calculations for total calories burnt
        cout<<"By "<<mins<<" minutes you will burn "<<TotalCal<<" calories on"
            <<" the treadmill."<<endl;//Displayed output of result
        mins+= MinIncreasedRate;//adds all of the minutes after every iteration
    }while(mins<=30);
    
                };break; 
                
case 5:{
    
    int years;
    float yearlyRate = 2500, TOTALChargeIncrease;
    const float ChargeIncrease = .04;
    
    cout<<"*** Gaddis Problem 5.5 (Membership Fees Increase) ***\n\n";
    
    //Out prompt for the program
    cout<<"This program display the amount charged for membership of a country "
        <<"club for the next\nsix years which is currently $2,500.\n\n";    
    
    //for loop iterates program until it reaches the sixth year
    for(years=1; years<=6; years++){
        TOTALChargeIncrease = ChargeIncrease*2;
        yearlyRate += (yearlyRate * TOTALChargeIncrease);
        cout<<"Charge rate in "<<years<<" year(s): $"<<fixed<<setprecision(2)<<
                showpoint<<yearlyRate<<endl;
    }
    
                };break; 
                
case 6:{
                
    float distance, inputSpeed, inputTime, hour, TotalDistance;
    
    cout<<"*** Gaddis Problem 5.6 (Distance Traveled) ***\n\n";
    
    //Questions for the input
    cout<<"What is the speed of the vehicle in mph? ";
    cin>>inputSpeed;
    cout<<"How many hours has it traveled? ";
    cin>>inputTime;
    
   //if statement to disallow input violations
    
    if (inputSpeed > 0 || inputTime >= 1){
        cout<<"Hour       Distance Traveled\n";
        cout<<"----------------------------\n";
        
        for(hour = 1; hour <= inputTime; hour++){
               distance = inputSpeed * hour;
               cout<<hour<<"         "<<distance<<endl;
        }
    }
    else
    {
        cout<<"Input Validation: Do not accept a negative number for speed and "
            <<"do not accept\nany value less than 1 for time traveled.\n";    
    }
    
                };break; 
                
case 7:{
    
    int day;
    float daysWorked, totalPennies, time, absoluteTotal = 0.0;
    const float pennies = 0.01;
    
    cout<<"*** Gaddis Problem 5.7 (Pennies for Pay) ***\n\n";
    
    //Requests for the amount of days worked
    cout<<"How many days have you worked? ";
    cin>>daysWorked;
    
    //There has to be at least 1 day of work for output to be valid
    if(daysWorked < 1){
        cout<<"Input Validation: Do not accept a number less than 1 for the "
            <<"number of days worked.\n";    
    }
    else
        //else will display the actual program if input value was valid
    {
     for(day = 1; day<= daysWorked; day++){//for loop will double amount of pennies
         totalPennies = (pennies * day);
         cout<<"Day "<<day<<": $"<<fixed<<setprecision(2)<<showpoint<<
                 totalPennies<<endl;
         absoluteTotal += totalPennies;
         

     }
     cout<<"Total Pay: $"<<absoluteTotal<<endl;//Output display of result
         
    }
                
                };break;
                
case 8:{
    
    bool loop=true;
    int inputCHOICE, Num1, Num2, Answer, inputAnswer;
    float divNum1, divNum2, divAnswer, divInputAnswer;
    char INPUTrestart;
    
    cout<<"*** Gaddis Problem 5.8 (Math Tutor) ***\n\n";
    
    //do while loop to restart the program on when user wishes to after answering
    do{
    //display menu for problem type selection
    cout<<"Input 1 to do addition problems.\n";
    cout<<"Input 2 to do subtraction problems.\n";
    cout<<"Input 3 to do multiplication problems.\n";
    cout<<"Input 4 to do division problems.\n";
    cout<<"Input 5 to exit the program.\n";
    cout<<"User Input: ";
    cin>>inputCHOICE;
    
    
    if (inputCHOICE >=1 && inputCHOICE<=5){
    
        //randomizer for all the numbers
    unsigned seed = time (0);
    
    srand(seed);
    
    Num1 = 10 + rand()%99;
    Num2 = 1 + rand()%9;
    
    //custom randomizer for numbers relating to the division problems
    divNum1 = 10 + (5*(rand()%99));
    divNum2 = 5 * (rand()%9);
            
   
   //switch state to choose between the problem types 
   switch (inputCHOICE){
            case 1:{
                Answer = Num1 + Num2;//Calcution of the correct answer 
                
                //vertical display of math problem
                cout<<Num1<<endl;
                cout<<Num2<<endl;
                cout<<"+\n";
                cout<<"---------\n";
                cin>>inputAnswer;//user answer input
                
                //if statement to determine for wrong and right answer output
                if (Answer == inputAnswer){
                    cout<<"Good job! ";
                    
                    //Asks if user wants to restart the program
                    cout<<"Would you like to restart? (Enter Y/N). ";
                    cin>>INPUTrestart;
                }
                else{
                    cout<<"Sorry you have the wrong answer.\n";
                    //Asks if user wants to restart the program
                    cout<<"Would you like to restart? (Enter Y/N). ";
                    cin>>INPUTrestart;
                }
                
                
                        };break; 
       
        //The reason why I didn't commentate any further was because the rest of 
       //the body was similar up until the end.
                        
       case 2:{
           Answer = Num1 - Num2;
           
                cout<<Num1<<endl;
                cout<<Num2<<endl;
                cout<<"-\n";
                cout<<"---------\n";
                cin>>inputAnswer;
                
                if (Answer == inputAnswer){
                    cout<<"Good job! ";
                    
                    cout<<"Would you like to restart? (Enter Y/N). ";
                    cin>>INPUTrestart;
                }
                else{
                    cout<<"Sorry you have the wrong answer.\n";
                    
                    cout<<"Would you like to restart? (Enter Y/N). ";
                    cin>>INPUTrestart;
                }
       };break;
       
       case 3:{
           
            Answer = Num1 * Num2; 
                
                cout<<Num1<<endl;
                cout<<Num2<<endl;
                cout<<"x\n";
                cout<<"---------\n";
                cin>>inputAnswer;
                
                if (Answer == inputAnswer){
                    cout<<"Good job! ";
                    
                    cout<<"Would you like to restart? (Enter Y/N). ";
                    cin>>INPUTrestart;
                }
                else{
                    cout<<"Sorry you have the wrong answer.\n";
                    
                    cout<<"Would you like to restart? (Enter Y/N). ";
                    cin>>INPUTrestart;
                }
       
       };break;
       
       case 4:{
           
           cout<<"Note: Round to the nearest tenth if have required.\n\n";
                   
           divAnswer = divNum1 / divNum2;
           
           
           cout<<"  _______\n";
           cout<<divNum2<<"| "<<divNum1<<endl;
           cout<<"Answer: ";
           cin>>divInputAnswer;
           
            if (divAnswer == divInputAnswer){
                    cout<<"Good job! ";
                    
                    cout<<"Would you like to restart? (Enter Y/N). ";
                    cin>>INPUTrestart;
                }
                else{
                    cout<<"Sorry you have the wrong answer.\n";
                    
                    cout<<"Would you like to restart? (Enter Y/N). ";
                    cin>>INPUTrestart;
                }
       
       };break;
                //output if exit option was selected
                default:{//exit for last option
                        cout<<"Exit?"<<endl;
                        loop=false;
                }break;
                
   }
    }
                else 
                {
                    cout<<"Input Validation: Do not accept a number less than "
                        <<"1 for the number of days worked.\n";
                    
                    cout<<"Would you like to restart? (Enter Y/N). ";
                    cin>>INPUTrestart;
                }
    }while(INPUTrestart == 'Y' || INPUTrestart == 'y');//do while's condition
    

                };break; 
                
case 9:{
    
int i, inputFLOORS, inputOCCUPANCY, inputROOMS, totalROOMS = 0;
float totalOCCUPANTS = 0.0;
const float percentConverter = 100.0;

        cout<<"*** Gaddis Problem 5.9 (Hotel Occupancy) ***\n\n";

//Output display of first question
    cout<<"How many floors are there? ";
    cin>>inputFLOORS;

    //If statement if invalid input was enter for # of floors
    if (inputFLOORS < 0){
        cout<<"Input Validation: Do not accept a value less than 1 for "
            <<"the numbers of floor. Do not\naccept a number less than "
            <<"10 for the number of rooms on a floor.\n"; 
    }
    for (i = 1; i <= inputFLOORS; i++){
        if (i==13) continue;
        do{
            cout << "How many rooms are on floor "<<i<<"? ";
            cin>>inputROOMS;
            
            //if statement for invalid inputs of # of rooms
            if (inputROOMS < 10 ) {
                cout<<"Input Validation: Do not accept a value less than 1 for "
                    <<"the numbers of floor. Do not\naccept a number less than "
                    <<"10 for the number of rooms on a floor.\n"; 
            }

            //asks how many of the rooms are occupied
            cout<<"How many of the rooms are occupied on floor "<<i<<"? ";
            cin>>inputOCCUPANCY;
            
            //calculations for total # of rooms and occupied rooms percentage
            totalROOMS+=inputROOMS;
            totalOCCUPANTS = (inputOCCUPANCY * percentConverter)/inputROOMS;
            

        }while(inputROOMS > 10 && inputFLOORS < 0);//condition for do while loop
}    
    //if all goes well this will be output
    if (inputROOMS >= 10 && inputFLOORS > 0){
                totalOCCUPANTS = (inputOCCUPANCY * percentConverter)/inputROOMS;
                cout<<"Total Amount of Rooms: "<<totalROOMS<<endl;
                cout<<"Percentage of Rooms Occupied: "<<totalOCCUPANTS<<"%\n";   
    }
                
                };break; 
                
case 10:{
    
    int YearCounter, MonthCounter, INPUTyear, totalMonth;
    const int MONTHS = 12;
    float INPUTrainfall, totalRainfall = 0.0, AVGrainfall;
    //Display prompt of the program
    cout<<"*** Gaddis Problem 5.10 (Average Rainfall) ***\n\n";
    cout<<"This program will request the average rainfall of every month of "
        <<"each year. After when the duration\nof year has been enter to solve "
        <<"total amount of rainfall.\n\n";    
    
    //Requests for the input of the amount of years
    cout<<"How many years would you like to consider into the calculation? ";
    cin>>INPUTyear;
    
    //use of if statement to only let the program continue if the INPUTyear was 
    // greater than 0.
    if (INPUTyear >= 1)
    {
    //outer for loop to count down the year
    for (YearCounter = 1; YearCounter <= INPUTyear; YearCounter++){

    //inner for loop to request avg rainfall of each month
        for (MonthCounter = 1; MonthCounter <= MONTHS; MonthCounter++){
        
            cout<<"How many inches of rainfall are there in Month #"<<
                    MonthCounter<<" Year #"<<YearCounter<<"? ";
            cin>>INPUTrainfall;
            
           //Program can only progress if the INNPUTrainfall value is 0 or above
            if (INPUTrainfall < 0){
                
                cout<<"Input Validation: Do not accept a number less than 1 for"
                <<" the number of years. Do not\naccept negative numbers for "
                <<"the monthly rainfall.\n";
                return 0;//Ends the program if this if statement's condition is
                //meant
            }
             //gathers and store the amount of rainfall for total
        totalRainfall += INPUTrainfall;
        }
    
    }
    totalMonth = MONTHS * INPUTyear;//Calculations for the total amount of months
    AVGrainfall = totalRainfall/totalMonth;//"    " average rainfall
    cout<<endl;
    //Output display of the all the results requested
    cout<<"Total Amount of Month(s): "<<totalMonth<<endl;
    cout<<"Total Amount of Rainfall: "<<totalRainfall<<" inches."<<endl;
    cout<<"Average Amount of Rainfall: "<<AVGrainfall<<" inches."<<endl;
    }
    //Else statement for the other if statement
    else{
        cout<<"Input Validation: Do not accept a number less than 1 for the "
            <<"number of years. Do not\naccept negative numbers for the monthly"
            <<" rainfall.\n";    
        return 0;//Ends the program
    }
                
                };break; 
                
                default:{//exit for last option
                        cout<<"Exit?"<<endl;
                        loop=false;
                        break;
                }
            }

        }while(loop);//do while loop to restart the entire program
    return 0;
}

