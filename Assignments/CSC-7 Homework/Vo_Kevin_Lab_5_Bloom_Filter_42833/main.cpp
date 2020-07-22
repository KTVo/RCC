/*
 * Name: Kevin Vo
 * Instructor: Dr. Lehr
 * Student ID: 2394221
 * Class: CSC-7 (42833)
 * Assignment: Lab 5 Bloom Filter
 * Date: May 5, 2016
 * File: main.cpp
 */

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "GeneralHashFunctions.h"

void bloomPart1Intro();
bool *bloomPart1(unsigned int, unsigned int, bool[]);
void checkBloomPart1(bool[], int);

void bloomPart2Intro();

using namespace std;

int main(int argc, char* argv[])
{
  int choice;  
  do{  
    cout<<"\nBloom Filter Lab\n------------------------\n";
    cout<<"Enter 1 to view Part 1\nEnter 2 to view PART 2\n";
    cout<<"Enter any other number to exit.\n";
    cin>>choice;
    
    if(choice == 1)
        bloomPart1Intro();
    else if(choice == 2)
        bloomPart2Intro();
  }while(choice >= 1 && choice<=2);
   return true;
}

void bloomPart2Intro(){
    string key;
    cout<<"\n--- Bloom Filter Part 2 ---\n";
    cout<<"Instruction: Create a file with random inputs and use all 9 hashes this time.\n";

   int indexNum;

    string line;
    ifstream myfile ("randomInput.txt");
    if (myfile.is_open()){
        while ( getline (myfile,line) ){
            cout << line << '\n';
        }
        myfile.close();
    }
    
    else cout << "\nUnable to open file\n"; 
  
    key = line;
    cout<<endl<<endl;
    std::cout << "General Purpose Hash Function Algorithms Test" << std::endl;
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
    cout<<endl; 
    bool bitVectP2[15];
    unsigned int tempKey;
    //Set all the elements of the bit vector to false
    for(int i = 0; i < 15; i++) bitVectP2[i] = false;
    
    for(int i = 0; i < 15; i++){
        if(i == 0){ tempKey = RSHash(key) % 13; cout<<"RSHash Value: ";}
        else if(i==1){ tempKey = JSHash(key) % 13; cout<<"JSHash Value: ";}
        else if(i==2){ tempKey = PJWHash(key) % 13; cout<<"PJWHash Value: ";}
        else if(i==3){ tempKey = ELFHash(key) % 13; cout<<"ELFHash Value: ";}
        else if(i==4){ tempKey = BKDRHash(key) % 13; cout<<"BKDRHash Value: ";}
        else if(i==5){ tempKey = SDBMHash(key) % 13; cout<<"SDBMHash Value: ";}
        else if(i==6){ tempKey = DJBHash(key) % 13; cout<<"DJBHash Value: ";}
        else if(i==7){ tempKey = DEKHash(key) % 13; cout<<"DEKHash Value: ";}
        else if(i==8){ tempKey = FNVHash(key) % 13; cout<<"FNVHash Value: ";}

        
        if(i >= 0 && i < 9) cout<<tempKey<<endl;
        bitVectP2[tempKey] = true;
        
    }
    cout<<"\nPART 2'S Bit Vector: ";
    for(int x = 0; x < 15; x++){ cout<<bitVectP2[x]<<" ";}
    float expo = (-7.2);
    float e = 1 - pow(2.71828,expo);
    
    float collision = pow(e,11)*100;
    cout<<fixed<<setprecision(0)<<"\nFalse-Positive: "<<collision<<"%"<<endl;
    
}

void bloomPart1Intro(){
   std::string key;

    int inputCount = 0;
    bool bitVector[15];
    for (int i = 0; i < 15; i++){
        bitVector[i] = false;
       
    }

    cout<<"\n--- Bloom Filter Part 1 ---\n";;
    cout<<"How many different strings would you like to enter? ";
    cin>>inputCount;
    float numElement = (inputCount*(-0.13));

    for(int i = 0; i < inputCount; i++){
        for(int j = 0; j <= 15; j++){
            if(j == 0)cout<<"Bit Vector: ";
            else cout<<j<<"-> "<<bitVector[j]<<", ";
        }
        cout<<"\nEnter string # "<<i<<": ";
        cin>>key;
    
        unsigned int hashVal1 = RSHash(key) % 17;
        unsigned int hashVal2 = DJBHash(key) % 17;
        cout<<"RSHash = "<<hashVal1<<"\nDJBHash = "<<hashVal2<<endl;
        bloomPart1(hashVal1, hashVal2, bitVector);
    }

    checkBloomPart1(bitVector, inputCount);
         
    float expo = numElement;
    float e = 1 - pow(2.71828,expo);
    
    float collision = e*e*100;
    cout<<fixed<<setprecision(0)<<"\nFalse-Positive: "<<collision<<"%"<<endl;
}

bool *bloomPart1(unsigned int hashVal1, unsigned int hashVal2, bool bitVector[15]){

    bitVector[hashVal1] = true;
    bitVector[hashVal2] = true;

return bitVector;}

void checkBloomPart1(bool bitVector[], int inputCount){
    string testKey;
  
    cout<<"How many elements would you like to test for membership?";
    cout<<"\n*** Note entering \"0\" will terminate the program.\n";
    cout<<"User Input: ";
    cin>>inputCount;
    
    for(int i = 0; i < inputCount; i++){
        cout<<"Test an element for membership: ";
        cin>>testKey;

        for(int i = 0; i < 15; i++) cout<<i<<"-> "<<bitVector[i]<<", ";
        unsigned int checkHashVal1 = RSHash(testKey) % 17;
        unsigned int checkHashVal2 = FNVHash(testKey) % 17;

        cout<<"RSHash: "<<checkHashVal1<<" FNVHash: "<<checkHashVal2<<endl;
        cout<<"Is the element in the set? ";
        if(bitVector[checkHashVal1] == true || bitVector[checkHashVal2] == true)
            cout<<"MAYBE\n";
        else cout<<"NO\n";
    }
}