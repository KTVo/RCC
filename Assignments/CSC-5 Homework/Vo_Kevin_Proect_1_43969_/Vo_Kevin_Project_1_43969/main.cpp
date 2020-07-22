/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Purpose: Demonstrate what I have learned
 * Assignment: Project 1 
 * Description: 100+ lines project
 * Problem 1 -> Tests addition skills
 * Problem 2 -> Tests multiplication skills
 * Problem 3 -> Tests Sentences Completion skills
 * Problem 4 -> Calculate the total cost while shopping after sales tax
 * Created on April 4, 2012, 11:18 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int main(int argc, char** argv) {
  //Primitive data types for menu
    char Problem_Type, restart, restart1;
    int w;
    bool loop=true;
    do{
    //Usage of do-while loop to reload the program by user's command
    do{
        //Prompt of program
cout<<"This program will calculate the total amount paid after sales tax\n";
cout<<"and test both of your mathematics and language arts skills during free\n";
cout<<"time. Please select one of the options below to use this program.\n\n";    

//Output of menu options
cout<<"Type 1 for Addition Problems.\n";
cout<<"Type 2 for Multiplication Problems.\n";
cout<<"Type 3 for Completing Sentences.\n";
cout<<"Type 4 for Sales Tax Calculator.\n";
cout<<"Type anything else to quit with no solutions.\n";
cin>>Problem_Type;

//Usage of the Switch statement for menu
switch(Problem_Type)
{
    case '1':{
        //Primitive data types for case 1 
        int correct, Answer;
        unsigned seed = time(0), Number1, Number2; 
        
        //prompt of the mini program within case 1
cout<<"This program will be testing your basic math skills. You'll be able\n"
    <<"to pick between addition or multiplication. Depending on how many "
    <<"problems you\ndo, will did you a picture award.\nWarning: "
    <<"If you enter in an incorrect answer you will be forced to restart."
    <<endl<<endl;

//Random # gen. to provide addition problems
                srand(seed);
   
                       Number1 = rand()%999;
                       Number2 = rand()%999;
   
                correct= Number1 + Number2;
                cout<<"Please enter in the correct answer to the problem below.\n";         
                cout<<"  "<<Number1<<endl;
                cout<<"+ "<<Number2<<endl;
                cout<<"-------"<<endl;
                cin>>Answer;//Input variable from user
        //Use of if statement to determine right & wrong answers
        if (correct == Answer)
        {
            //Prize picture reward of sea horse after receiving correct answer
                cout<<"Congratulations, you have made it to sea horse status!\n";
                cout<<endl;
                cout<<"________$$$$.."<<endl;
                cout<<"______$$$$$$$$$"<<endl;
                cout<<"______$$$$$$$_$"<<endl;
                cout<<"_____$$$$$$$$$$"<<endl;
                cout<<"______$$$$$$$$$$"<<endl;
                cout<<"_____$$$$$$_$$$$$"<<endl;
                cout<<"____$$$$$$$_____$$$"<<endl;
                cout<<"____$$$$$$$$_____$"<<endl;
                cout<<"____$$$$$$$$$$"<<endl;
                cout<<"_____$$$$$$$$$$"<<endl;
                cout<<"_____$$$$$$$$$$$"<<endl;
                cout<<"______$$$$$$$$$$$"<<endl;
                cout<<"_$$$$___$$$$$$$$$"<<endl;
                cout<<"__$$$$$$$$$$$$$$$"<<endl;
                cout<<"_$$$$$$$$$$$$$$$"<<endl;
                cout<<"__$$$$$$$$$$$$$"<<endl;
                cout<<"$$$$$$$$$$$$$"<<endl;
                cout<<"__$__$$$$$$"<<endl;
                cout<<"____$$$$$$"<<endl;
                cout<<"____$$$$$"<<endl;
                cout<<"___$$$$$$_____$"<<endl;
                cout<<"___$$$$$$___$$_$$"<<endl;
                cout<<"____$$$$$___$__$$"<<endl;
                cout<<"____$$$$$______$$"<<endl;
                cout<<"_____$$$$$____$$$"<<endl;
                cout<<"_______$$$$$$$$$"<<endl;
                cout<<"__________$$$$"<<endl<<endl;      
                cout<<"(Photo provided by fsymbols.com)"<<endl;
                cout<<endl;

        }
  
        else
        {
                cout<<"Sorry you got it wrong please restart the program and "
                    <<"try again.\nWould you like to restart? (Enter Y/N). ";
               cin>>restart;
        }
    
    }break;
    
    case '2':{
        //Primitive data types for case 2
        int correct, Answer;
        unsigned seed = time(0), Number1, Number2; 

cout<<"This program will be testing your basic math skills. You'll be able\n"
    <<"to pick between addition or multiplication. Depending on how many "
    <<"problems you\ndo, will did you a picture award.\nWarning: "
    <<"If you enter in an incorrect answer you will be forced to restart."
    <<endl<<endl;
        //Random # gen. to provide multiplication problems
                srand(seed);
   
                       Number1 = rand()%99;
                       Number2 = rand()%99;
   
                correct= Number1 * Number2;
                cout<<"Please enter in the correct answer to the problem below.\n";         
                cout<<"  "<<Number1<<endl;
                cout<<"x "<<Number2<<endl;
                cout<<"-------"<<endl;
                cin>>Answer;//Input variable from user
   //Use of if statement to determine right & wrong answers
        if (correct == Answer){
            //Prize picture reward of dolphin after receiving correct answer
                cout<<"Congratulations, you have made it to dolphin status!\n";
                cout<<endl;
                cout<<"__________________ ##"<<endl;
                cout<<"_________________###*"<<endl;
                cout<<"______________.*#####"<<endl;
                cout<<"_____________*######"<<endl;
                cout<<"___________*#######"<<endl;
                cout<<"__________*########."<<endl;
                cout<<"_________*#########."<<endl;
                cout<<"_________*#######*##*"<<endl;
                cout<<"________*#########*###"<<endl;
                cout<<"_______*##########*__*##"<<endl;
                cout<<"_____*###########_____*"<<endl;
                cout<<"____############"<<endl;
                cout<<"___*##*#########"<<endl;
                cout<<"___*_____########"<<endl;
                cout<<"__________#######"<<endl;
                cout<<"___________*######"<<endl;
                cout<<"____________*#####*"<<endl;
                cout<<"______________*####*"<<endl;
                cout<<"________________*####"<<endl;
                cout<<"__________________*##*"<<endl;
                cout<<"____________________*##"<<endl;
                cout<<"_____________________*##."<<endl;
                cout<<"____________________.#####."<<endl;
                cout<<"_________________.##########"<<endl;
                cout<<"________________.####*__*####"<<endl;
                cout<<"(Photo provided by fsymbols.com)"<<endl;
        }
        else
        {
                cout<<"Sorry you got it wrong please restart the program and "
                    <<"try again.\nWould you like to restart? (Enter Y/N). ";
                cin>>restart;
        }      
    }break;
    
    case '3':{
        //primitive data types for case 3
        char answer1, answer2, answer3;
        cout<<"Complete the sentence active."<<endl<<endl<<endl;
        
        //Output of question# 1
        cout<<"1) There is a ____ cat sleeping on the couch."<<endl;
        cout<<setw(6)<<"A. black"<<endl;
        cout<<setw(6)<<"B. plane"<<endl;
        cout<<setw(6)<<"C. apple"<<endl;
        cout<<setw(6)<<"D. feel"<<endl;
        
        cin>>answer1;//Input variable from user
        
        //if statement for right/wrong answer
        if (answer1 == 'A' || answer1 == 'a')
        {
            cout<<"Good Job!"<<endl;
        }
        else
        {
            //Requests user to restart program
             cout<<"Sorry you got it wrong please restart the program and "
                 <<"try again.\nWould you like to restart? (Enter Y/N). ";
                cin>>restart;
        }
      //Pauses program and waits for user to continue  
        cout<<"Please press Enter to answer the next question... ";
        cin.ignore();
        cin.get();
        
        //Output of question# 2
        cout<<"2) The fish ____ across the lake."<<endl;
        cout<<setw(6)<<"A. hopped"<<endl;
        cout<<setw(6)<<"B. ran"<<endl;
        cout<<setw(6)<<"C. swam"<<endl;
        cout<<setw(6)<<"D. googled"<<endl;
        
        cin>>answer2;//Input variable from user
        
        //if statement for right/wrong answer
        if (answer2 == 'C' || answer2 == 'c')
        {
               cout<<"Good Job!"<<endl;;
        }
        else
        {
             cout<<"Sorry you got it wrong please restart the program and "
                 <<"try again.\nWould you like to restart? (Enter Y/N). ";
                cin>>restart;
        }
        
        //Pauses program and waits for user to continue  
        cout<<"Please press Enter to answer the next question... ";
        cin.ignore();
        cin.get();
        
        cout<<"3) ____ phones are very portable."<<endl;
        cout<<setw(6)<<"A. Bat"<<endl;
        cout<<setw(6)<<"B. Cell"<<endl;
        cout<<setw(6)<<"C. Diamond"<<endl;
        cout<<setw(6)<<"D. Foot"<<endl;
        
        cin>>answer3;//Input variable from user
        
        //if statement for right/wrong answer
        if (answer3 == 'C' || answer3 == 'c')
        {
                cout<<"Good Job!"<<endl;
        }
        else
        {
            //Requests user to restart program
             cout<<"Sorry you got it wrong please restart the program and "
                 <<"try again.\nWould you like to restart? (Enter Y/N). ";
                cin>>restart;
        }
        

    }
    
    case '4':{
        //primitive data types for case 4
        int count;
        float total = 0.0,subtotal, b, Num_items, item, prediction;
        const float sale_TAX = 0.0725;//constant variable
        //Output prompt for sales tax calculator
        cout<<"This program will calculate the total amount paid in sales tax "
            <<"and includes the total cost.\nNote: This program will only be "
            <<"valid in the state of California."<<endl<<endl;   
        
        cout<<"How many items did you purchased?: ";
        cin>>Num_items;
        
        //Stores data and letter informs the user if they over spend
        cout<<"How much are you expecting to spend?: ";
        cin>>prediction;
        
        //For Loop to repeat and store values
        for (count=1;count<=Num_items;count++)
        {
            cout<<"Price of Item "<<count<<": ";
            cin>>item;
            total += item; 
            
        }
        //Equation for stored data 
        b = total * sale_TAX;
        subtotal = total + b;
        //Use of else if statement mathematical expressions for result
        if(subtotal>prediction)
        {
        //Output Results
                cout<<"Sales Tax: $ "<<showpoint<<fixed<<setprecision(2)<<b<<endl;
                cout<<"Price w/ sales tax included: $ "<<showpoint<<fixed<<
                        setprecision(2)<<subtotal<<endl;
                cout<<"Uh-oh you have spend more than what you expected too."<<endl;  
        }
        else if(subtotal<prediction)
        {
                cout<<"Sales Tax: $ "<<showpoint<<fixed<<setprecision(2)<<b<<endl;
                cout<<"Price w/ sales tax included: $ "<<showpoint<<fixed<<
                        setprecision(2)<<subtotal<<endl;
                cout<<"Congratulations you have spend less than what you expected too."<<endl;  
        }
        else
        {
                cout<<"Sales Tax: $ "<<showpoint<<fixed<<setprecision(2)<<b<<endl;
                cout<<"Price w/ sales tax included: $ "<<showpoint<<fixed<<
                        setprecision(2)<<subtotal<<endl;
                cout<<"Congratulations you have exactly meant your expectation ."<<endl;
        }
        
        //Requests user to restart program
          cout<<"\nSorry you got it wrong please restart the program and "
          <<"try again.\nWould you like to restart? (Enter Y/N). ";
          cin>>restart;
     
     
        
    }
    
}
}while (restart == 'Y' || restart == 'y');//end of the do-while loop  
    }while(loop);
    return 0;
}

