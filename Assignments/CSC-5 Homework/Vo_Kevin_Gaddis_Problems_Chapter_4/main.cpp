/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Purpose: Using menu for challenge selection
 * Chapter: Gaddis Chapter 4
 * Problem 1 -> Finds the minimum and maximum of 2 #s
 * Problem 2 -> Converts #s to Roman numeral format
 * Problem 3 -> Figures if the input date is a "magic date"
 * Problem 4 -> Determines which triangle has the greater area
 * Problem 5 -> Determines a person's sedentary weight w/ BMI
 * Problem 6 -> Converts seconds to mins., hours/ days
 * Problem 7 -> Figures weight in newtons through mass
 * Problem 8 -> Informs user if their coins = up to $1 game
 * Problem 9 -> Randomly generates addition problems
 * Problem 10 -> Determines quantity discounts
 * Created on March 27, 2012, 11:18 AM
 */
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    //General Menu Format
    bool loop=true;
    do{
        //Display the selection
        cout<<"Type A to solve problem 1\n";
        cout<<"Type B to solve problem 2\n";
        cout<<"Type C to solve problem 3\n";
        cout<<"Type D to solve problem 4\n";
        cout<<"Type E to solve problem 5\n";
        cout<<"Type F to solve problem 6\n";
        cout<<"Type G to solve problem 7\n";
        cout<<"Type H to solve problem 8\n";
        cout<<"Type I to solve problem 9\n";
        cout<<"Type J to solve problem 10\n";
        cout<<"Type anything else to quit with no solutions.\n";
        //Defining user input variable
        char choice;
        cin>>choice;
        //List of problems to be chosen from
        switch(choice){
            //Min. or Max
            case 'a':    
            case 'A':{
                    int num1, num2;
                cout<<"Please enter in two numbers to determine which is ";
                cout<<"smaller \nand which is larger. \n";
                cout<<"First Number: ";
                cin>>num1;
                cout<<"Second Number: ";
                cin>>num2;
                
                if (num1 > num2)
                {
                    cout<<num1<<" is the larger number and "<<num2<<" is the ";
                    cout<<"smaller number. \n";
                    cout<<"Minimum: "<<num2<<endl;
                    cout<<"Maximum: "<<num1<<endl;
                }
                else
                    if (num1 < num2)
                    {
                    cout<<num2<<" is the larger number and "<<num1<<"is the ";
                    cout<<"smaller number. \n";
                    cout<<"Minimum: "<<num1<<endl;
                    cout<<"Maximum: "<<num2<<endl;
                    }
                    else
                    cout<<num1<<" and "<<num2<<" are equal to each other.\n";
                cout<<endl;    
                break;
                }
                //Roman Numeral Converter
            case 'b':    
            case 'B':
                int Roman;
                cout<<"Please enter in a # value of 1 - 10 for to be converted";
                cout<<" to Roman numeral.\n";
                cin>>Roman;
                
                switch(Roman){
                    case 1:cout<<"Roman Numeral Version: I\n"; 
                         break;
                    case 2:cout<<"Roman Numeral Version: II\n";
                         break;
                    case 3:cout<<"Roman Numeral Version: III\n";
                         break;
                    case 4:cout<<"Roman Numeral Version: IV\n";
                         break;
                    case 5:cout<<"Roman Numeral Version: V\n";
                         break;
                    case 6:cout<<"Roman Numeral Version: VI\n";
                         break;
                    case 7:cout<<"Roman Numeral Version: VII\n";
                         break;
                    case 8:cout<<"Roman Numeral Version: VIII\n";
                         break;
                    case 9:cout<<"Roman Numeral Version: IX\n";
                         break;
                    case 10:cout<<"Roman Numeral Version: X\n";
                        break;
                    default: cout<<"Input Validation: Do not accept a number ";
                    cout<<"less than 1 or greater than 10.\n";
                    cout<<endl;
                }
               
                break;
                //Magic Dates
            case 'c':    
            case 'C':
                    int month, day, year, Magic;
                    
                    cout<<"Please enter in parts of the date in numeric form ";
                    cout<<"with the same order between the month, day, and year";
                    cout<<"(Two digits).\nTo determine if the date is a magic date.";
                    cout<<"ex: 6 10 60 (Month Day Year)"<<endl<<endl;
                    cin>>month>>day>>year;
                    Magic=month*day;
                    
                    if (Magic == year)
                        cout<<"This date is magic!\n";
                    else
                        cout<<"This date is not magic.\n";
                    cout<<endl;
                    break;

            break;
                //Areas of Rectangles
            case 'd':    
            case 'D':{
                    float LengthA, WidthA, length_B, width_B, AreaA, area_B;
                    
                    cout<<"Please enter in the requested information of both\n";
                    cout<<"Rectangle A and Rectangle B, beginning with A then B.\n";
                    cout<<"To determine which area of the triangle is greater.\n";
                    
                    cout<<"Length of Triangle A: ";
                    cin>>LengthA;
                    cout<<"Width of Triangle A: ";
                    cin>>WidthA;
                    AreaA= LengthA * WidthA;
                    cout<<"Length of Triangle B: ";
                    cin>>length_B;
                    cout<<"Width of Triangle B: ";
                    cin>>width_B;
                    area_B=length_B*width_B;
                    
                    if (AreaA > area_B)
                        cout<<"The area of Triangle A is greater than Triangle B's.\n";
                    else if (AreaA < area_B)
                        cout<<"The area of Triangle B is greater than Triangle A's.\n";
                    else
                        cout<<"The area of both triangles are equal to each other.\n";
                    cout<<endl;
                    break;
                }
                //Body Mass Index
            case 'e':
            case 'E':{
                float BMI, weight, height; 
                const float minW=18.5, MaxW=25;
                
                
                cout<<"Enter in the following information to determine your BMI.\n";
                cout<<"Your Weight (pounds): ";
                cin>>weight;
                cout<<"Your Height (inches): ";
                cin>>height;
                BMI=(weight*703)/(height*height);
                
                if(BMI>=minW && BMI<=MaxW)
                {
                    cout<<"Congratulations your sedentary weight is consider ";
                    cout<<"to be optimal.\n";
                }
                else if(BMI<18.5)
                    cout<<"Your sedentary weight is consider to be underweight.\n";
                else if(BMI>25)
                    cout<<"Your sedentary weight is consider to be overweight.\n";
                cout<<endl;
                break;
            }
            break;
            //Mass and Weight
            case 'f':    
            case 'F':{
                    float Weight, mass;
                    
                    
                    cout<<"Enter in the mass of the object to determine its "<<
                            "weight in newtons.\n";
                    cout<<"Mass of the object: ";
                    cin>>mass;
                    
                    Weight = (mass * 9.8);
                    
                    if(Weight>10 && Weight<25)
                        cout<<"Weight: "<<Weight<<" newtons";
                    else if (Weight>1000)
                        cout<<"Sorry but this object is too heavy.\n";
                    else if(Weight<10)
                        cout<<"Sorry but this object is too light.\n";
                         cout<<endl;
                    break;
                }
            break;
                //Time Calculator
            case 'g':
            case 'G':{
                int sec, SM, SH, SD; 
                const int day=86400, hour=3600, min=60;
                cout<<"Please enter in the number of seconds you wish to be ";
                cout<<"minutes, hours, or days.\n";
                cout<<"Number of Seconds: ";
                cin>>sec;
                
                if(sec>=min && sec<hour && sec<day)
                {
                    SM = sec/min;
                    cout<<"There are "<<SM<<" minutes in "<<sec<<" seconds.\n";
                }
                else if(sec>=hour && sec<day && sec>min)
                {
                    SH = sec/hour;
                cout<<"There are "<<SH<<" hours in "<<sec<<" seconds.\n";
                }
                else if(sec>=day && sec>hour && sec>min)
                {
                    SD= sec/day;
                cout<<"There are "<<SD<<" days in "<<sec<<" seconds.\n";
                }
            }
            break;
            //Change for a Dollar Game
            case 'h':
            case 'H':{
                const int dollar = 100;
                int coin, pennies, nickels, dimes, quarters, p, n, d, q;
                cout<<"Please enter the amount of each coin to make exactly $1.\n";
                cout<<"Penny: ";
                cin>>pennies;
                cout<<"Nickel: ";
                cin>>nickels;
                n=(nickels*5);
                cout<<"Dime: ";
                cin>>dimes;
                d=(dimes*10);
                cout<<"Quarter: ";
                cin>>quarters;
                q=(quarters*25);
                coin =(p+n+d+q);
               
                        if(coin == dollar)
                {
                    cout<<"Congratulations the amount of coins you have entered";
                    cout<<" equals exactly to one dollar!\n";
                }
                else if (coin<dollar)
                {
                    cout<<"The amount you entered was less than a dollar.\n";
                }
                else
                {
                    cout<<"The amount you entered was more than a dollar.\n";
                }
            }
            break;
            //Math Tutor
            case 'i':
            case 'I':{
                unsigned seed = time(0), Num1, Num2, Answer, correct; 
   
                srand(seed);
   
                       Num1 = rand()%9999;
                       Num2 = rand()%9999;
   
                 correct= Num1 + Num2;
                cout<<"Please enter in the correct answer to the problem below.\n";         
                cout<<"  "<<Num1<<endl;
                cout<<"+ "<<Num2<<endl;
                cout<<"-------"<<endl;
  cin>>Answer;
   
        if (correct == Answer)
                cout<<"Congratulations you have the correct answer.\n";
        else
                cout<<"Sorry you got it wrong please restart the program and try again.\n";
            }
            break;
            //Software Sales
            case 'j':
            case 'J':{
                float Twenty_Percent, Thirty_Percent, Forty_Percent,
                        Fifty_Percent, Twen, Thir, Fort, Fift, TotalCost;
                const int Package = 99;
                int quantity;
                
                cout<<"Please enter the amount of package(s) you've purchased to";
                cout<<" determine the value of the quantity discount.\n";
                cout<<"How many packages did you buy?: ";
                cin>>quantity;
                
                TotalCost=(quantity*Package);
              
                        if (quantity>=10 && quantity<=19)
                {
                    Twenty_Percent=(TotalCost *.2);
                Twen=(TotalCost-Twenty_Percent);
                
                cout<<"You have earn a quantity discount of 20%, therefore the";
                cout<<" subtotal is $ "<<Twen<<endl;
                
                        
                }
                else if(quantity>=20 && quantity<=49)
                {
                    Thirty_Percent=(TotalCost*.3);
                    Thir=TotalCost-Thirty_Percent;
                
                cout<<"You have earn a quantity discount of 30%, therefore the";
                cout<<" subtotal is $ "<<showpoint<<setprecision<<Thir<<endl;
                }
                else if (quantity>=50 && quantity<=99)
                {
                    Forty_Percent=(TotalCost * .4);
                    Fort=(TotalCost - Forty_Percent);
                
                cout<<"You have earn a quantity discount of 40%, therefore the";
                cout<<" subtotal is $ "<<showpoint<<setprecision(2)<<Fort<<endl;
                }
                else if (quantity<=100)
                {
                    Fifty_Percent=(TotalCost * .5);
                    Fift=(TotalCost - Fifty_Percent);
                cout<<"You have earn a quantity discount of 50%, therefore the";
                cout<<" subtotal is $ "<<showpoint<<setprecision(2)<<Fift<<endl;
                }
                else
                {
                cout<<"Input Validation: Make sure the number of units is ";
                cout<<"greater than 1.\n";
                }
            }
                default:{
                        cout<<"Exit?"<<endl;
                        loop=false;
                        break;
                }
               
        }
    }while(loop);//Does a loop w/out manually restarting program
    return 0;
}

