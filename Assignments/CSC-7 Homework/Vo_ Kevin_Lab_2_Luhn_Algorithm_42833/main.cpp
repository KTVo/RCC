/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Course: CSC-7 (42833)
 * Instructor: Dr. Lehr
 * Assignment: Lab 2 Luhn Algorithm
 * Created on March 23, 2016, 6:33 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

/*** 
 * NOTE: The only way I've found this to work with a prototype is to have the 
 * enum data type as declared global variable above it
 ***/
enum CrdCard {AmericanExpress, Visa, MasterCard, Discover, ALL};
char rndDgit();
void flipDig(char []);
void genCC(CrdCard,char []);
bool validCC(char[]);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));              
    CrdCard select;
    int input;
    //Do while loops until correct Luhn digit is calculated
    do{
        cout<<"Please select a card: "<<endl;
        cout<<"Enter 1 for American Express\n"
            <<"Enter 2 for Visa\n"
            <<"Enter 3 for MasterCard\n"
            <<"Enter 4 for Discover\n"
            <<"Enter 5 for ALL\nUser Input: ";
        cin>>input;
        if(input <= 0 || input >= 6)
            cout<<"Input is out of range please enter only 1-5.\n";
    }while(input <= 0 || input >= 6);
    //Switch statement: sets the enum based on input
    switch(input){
        case 1: select = AmericanExpress;break;
        case 2: select = Visa;break;
        case 3: select = MasterCard;break;
        case 4: select = Discover;break;
        case 5: select = ALL;break;
    }
    const int SIZE = 16;
    char cc[SIZE];//Array that holds all the credit card numbers
    genCC(select, cc);//Generates the different kinds of credit card numbers
    return 0;
}

void genCC(CrdCard select,char cc[]){
    int TOTAL = 0, temp, valid = 0, invalid = 0;
    int even = 0, totEven = 0, odd = 0, totOdd = 0, total = 0;
    int length, chooseIIN;
    int countValid = 0;
    int randomSelect;
    int z = 0;
    bool pickALL = false;
    if (select == ALL) pickALL = true;
    do{

        for(z = 0; z <= 10000; z++){
            //resets enum so that it loops through all the diff. cards if "ALL"
            randomSelect = rand()%1000;
            cout<<"--------------------------    "<<endl;
            if(randomSelect >= 0 && randomSelect <250 && pickALL == true) select = AmericanExpress;
            else if(randomSelect >= 250 && randomSelect <500 && pickALL == true) select = Visa;
            else if(randomSelect >= 500 && randomSelect <750 && pickALL == true) select = MasterCard;
            else if(randomSelect >= 750 && randomSelect <10001 && pickALL == true) select = Discover;
            

            chooseIIN = rand()%100;//Sets the starting IIN for each card

            //American Express
            if (select == AmericanExpress){    
                length = 15; 
                cout<<"* American Express * ";
                //Presets the IIN starting value for American Express
                cc[0] = '4';
                if(chooseIIN <= 50) cc[1] = '4';
                else if(chooseIIN >= 51) cc[1] = '7';

                //Loops to assign the rest of the array cc[]
                for(int i = 2; i < (length); i++){
                    cc[i] = rndDgit();
                }

                //Put null terminator at the end
                for(int i = length; i <= length+1; i++){
                    cc[i]='\0';
                }

            }else if(select == Visa){ //Visa
                length = 16;
                cout<<"* Visa * ";
                cc[0] = '4';//Presets the IIN start for Visa
                for(int i = 1; i < length; i++){
                    cc[i] = rndDgit();
                    if(i == 0) cc[0] = '4';
                }

                //Put null terminator at the end
                for(int i = length; i <= length+1; i++){
                    cc[i]='\0';
                }
            }else if(select == MasterCard){
                length = 16;
                cout<<"* MasterCard * ";
                cc[0] = '5';
                if(chooseIIN<=19) cc[1] = '1';
                else if(chooseIIN>19 && chooseIIN<=40) cc[1] = '2';
                else if(chooseIIN>40 && chooseIIN<=60) cc[1] = '3';
                else if(chooseIIN>60 && chooseIIN<=80) cc[1] = '4';
                else if(chooseIIN>80 && chooseIIN<=100) cc[1] = '5';

                for(int i = 2; i < length; i++){ 
                    cc[i] = rndDgit();
                }

                //Put null terminator at the end
                for(int i = length; i <= length+1; i++){
                    cc[i]='\0';
                }
            }else if(select == Discover){
                length = 16;
                cout<<"* Discover * ";
                cc[0] = '6';
                cc[1] = '0';
                cc[2] = '1';
                cc[3] = '1';
                for(int i = 4; i < length; i++){
                    cc[i] = rndDgit();
                }

                //Put null terminator at the end
                for(int i = length; i <= length+1; i++){
                    cc[i]='\0';
                }
            }


            //Slips up every odd and even elements
            // 2 * every even elements
            //if cc["EVEN ELEMENT"] > 9 then -9 from it
            //Odd elements, leave it alone
            //Sum all up
            for(int elem = 9; elem >= 0; elem--){
                if(elem%2!=0){
                        even = (cc[elem]-48)* 2;
                        if(even > 9) even -= 9;
                        totEven += even;

                    }
                    else{
                        odd = (cc[elem]-48);
                        totOdd += odd;

                    }
            }

            //Calculates and displays Sum of Digits, Check Digit, in/valid
            total = totOdd + totEven;

            cout<<"Generated Credit Card Number #"<<z<<": "<<cc;
            total *= 9;
            total %= 10;
            int flipChance = rand()%1000;
            if(flipChance < 500){
                flipDig(cc);
            }    
            bool checkBool = validCC(cc);
            if(checkBool == true){countValid++;}
            if(z>=10000){
                cout<<endl<<endl<<"--- Validation Tracker ---\n";
                cout<<"Number of Valid = "<<countValid<<endl;
                cout<<"Number of Invalid = "<<(10000-countValid)<<endl;
            }else cout<<endl;
                if(select == ALL && z<=999){
                    if (select == ALL){
                randomSelect = rand()%1000;
                cout<<"--------------------------    "<<randomSelect<<endl;
                if(randomSelect >= 0 && randomSelect <250) select = AmericanExpress;
                else if(randomSelect >= 250 && randomSelect <500) select = Visa;
                else if(randomSelect >= 500 && randomSelect <750) select = MasterCard;
                else if(randomSelect >= 750 && randomSelect <10001) select = Discover;
            }
    }
        }
    }while(total == cc[length-1]);

}

    
void flipDig(char cc[]){
    int elemFlip = rand()%14;
    int valFlip = rand()%14;
    char temp;
    if(cc[elemFlip] != valFlip){
        temp = cc[elemFlip];
        cc[elemFlip] = cc[valFlip];
        cc[valFlip] = temp;
        cout<<" --> FLIPPED: ";
        for(int i = 0; i <= 15; i++) cout<<cc[i];
    }
    
};

bool validCC(char cc[]){
    bool flipChecker;

    int totEven = 0, even, totOdd = 0, odd;
    //Checks if flipped digit is still VALID

    //Slips up every odd and even elements
    // 2 * every even elements
    //if cc["EVEN ELEMENT"] > 9 then -9 from it
    //Odd elements, leave it alone
    //Sum all up
    for(int elem = 9; elem >= 0; elem--){
        if(elem%2!=0){
                even = (cc[elem]-48)* 2;
                if(even > 9) even -= 9;
                totEven += even;
            }
            else{
                odd = (cc[elem]-48);
                totOdd += odd;
            }
    }
        
    //Calculates and displays Sum of Digits, Check Digit, in/valid
    int total = totOdd + totEven;
    total *= 9;
    total %= 10;

    if(total %10 != 0){flipChecker = false;}
    else {flipChecker = true;}

return flipChecker;}

char rndDgit(){
    return rand()%10+48;  
}
