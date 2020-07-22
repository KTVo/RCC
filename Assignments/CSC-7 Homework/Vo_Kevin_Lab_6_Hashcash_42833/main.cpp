/*
 * Name: Kevin Vo
 * Instructor: Dr. Lehr
 * Student ID: 2394221
 * Class: CSC-7 (42833)
 * Assignment: Lab 6 Hashcash
 * Date: May 5, 2016
 * File: main.cpp
 *
 * Testing something like a hashcash algorithm
 * Sample output
 *      The initial random number = 867605078
 *      The base message = What a difference a day makes!
 *      The total time take = 5 (secs)
 *      The number of zeroes = 5
 *      The hex output = 00000273f4e5e9e2c510995a0b1116cdaf6d4f5f
 *              0 zeroes occured 915586 times
 *              1 zeroes occured 57248 times
 *              2 zeroes occured 3557 times
 *              3 zeroes occured 212 times
 *              4 zeroes occured 22 times
 *              5 zeroes occured 1 times
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>
#include <sstream>
using namespace std;

//Sha1 algorithm copied from somewhere
#include "GeneralHashFunctions.h"
#include "sha1.h"
using namespace sha1;

//Function Prototypes
int count0(char [],int);
void prntRes(int [],int);

//Execution Begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Choose a random number and declare the hex for sha1
    int randNum=rand();
    const int HXSIZE=41;
    string key;
    char hex[HXSIZE];;
    int v = 0;
    unsigned int hexVal[8];
       unsigned int encrypt = RSHash(key)+JSHash(key)+PJWHash(key)+ELFHash(key)+
        BKDRHash(key)+SDBMHash(key)+DJBHash(key)+DEKHash(key)+FNVHash(key)+
        BPHash(key)+APHash(key);
   
   int i = 1, x, newVal;
   long int ori = encrypt; 
   char resultHex[100];
    cout<<"The initial random number = "<<randNum<<endl;
    //Create a message
    string msg="What a difference a day makes!";
    cout<<"The base message = "<<msg<<endl;
    //Setup the number of loops and loop variables
    int endLoop=5,freq[HXSIZE]={},cntZero;
    //Record the start time
    int strTime=time(0);
    //Loop until you have reached the number of zeroes desired
    do{
        //Create a concatenation of the two by first converting the random
        //number to a string
        ostringstream convert;   // stream used for the conversion
        convert << randNum++;      // insert the textual representation of 'Number' in the characters in the stream
        string strRnd = convert.str();
        string newMsg=msg+strRnd;
        key = newMsg;
        //cout<<newMsg<<endl;
        //Convert to a character message
        char cMsg[100];
        strcpy(cMsg, newMsg.c_str());
        int size=sizeof(cMsg)-1;
        //utilize the sha1 function
        unsigned char code[20];
        calc(cMsg, size, code);
        toHexString(code, hex);
        cntZero=count0(hex,endLoop+1);
        freq[cntZero]++;
        
    }while(cntZero<endLoop);
    //Take the time it took
    int endTime=time(0);


   
   while(ori != 0){
       newVal=ori%16;
       if(newVal<10) newVal += 48;
       else newVal += 55;
       
       resultHex[i++] = newVal;
       ori=ori/16;
   }
    
    
   cout<<"The hex output = : ";
   for(x = i-1; x>0;x--) cout<<resultHex[x]; 
    
    //Output the result
    cout<<"\nThe total time take = "<<endTime-strTime<<" (secs)"<<endl;
    prntRes(freq,cntZero);
    
    std::cout << "\n\nGeneral Purpose Hash Function Algorithms Test" << std::endl;
    std::cout << "By Arash Partow - 2002        " << std::endl;
    std::cout << "Key: "                          << key           << std::endl;
    std::cout << " 1. RS-Hash Function Value:   " << RSHash(key)   << std::endl;
    std::cout << " 2. JS-Hash Function Value:   " << JSHash(key)   << std::endl;
    std::cout << " 3. PJW-Hash Function Value:  " << PJWHash(key)  << std::endl;
    std::cout << " 4. ELF-Hash Function Value:  " << ELFHash(key)  << std::endl;
    std::cout << " 5. BKDR-Hash Function Value: " << BKDRHash(key) << std::endl;
    std::cout << " 6. SDBM-Hash Function Value: " << SDBMHash(key) << std::endl;
    std::cout << " 7. DJB-Hash Function Value:  " << DJBHash(key)  << std::endl;
    std::cout << " 8. DEK-Hash Function Value:  " << DEKHash(key)  << std::endl;
    std::cout << " 9. FNV-Hash Function Value:  " << FNVHash(key)  << std::endl;
    std::cout << "10. BP-Hash Function Value:   " << BPHash(key)   << std::endl;
    std::cout << "11. AP-Hash Function Value:   " << APHash(key)   << std::endl;

    //Exit stage right
    return 0;
}

void prntRes(int freq[],int n){
    //Output the frequency for each occurence
    int j = 9;
    for(int i=0;i<=n;i++){
        cout<<"10^"<<j<<": "<<freq[i]<<" times"<<endl;
        j--;
    }
}

int count0(char str[],int n){
    int cnt=-1;
    do{
        cnt++;
    }while(str[cnt]=='0');
    return cnt;
}

