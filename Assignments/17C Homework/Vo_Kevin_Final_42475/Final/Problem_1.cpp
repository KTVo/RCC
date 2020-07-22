/* 
 * File:   Problem_1.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Final
 * Created on May 31, 2018, 8:31 AM
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

#include "Problem_1.h"
#include "Problem_5.h"
using namespace std;

string generateStr(const int, bool);


void prob1(BinaryTree &tree, Hash &table){
    
    const int size = 512;
    string inital;
    
    cout<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"*            Problem 1 - Hashing            *"<<endl;
    cout<<"*********************************************"<<endl;
   
    
    //Fill in hash table (linked list array) with random initials
    for(int i = 0; i < size; i++){
        string temp = generateStr(3, true);
        
        if(i == 0)
            table.setRndVal(temp);
  
  
        table.insert(temp);
        tree.insert(temp);
    }
 
    table.displayCollisions();
    
}

//Displays the results of the collision by counting the linked list "chain"
void Hash::displayCollisions(){

    int c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, 
            c8 = 0, c9 = 0, c10 = 0;
    
    for(int i = 0; i < tableSize; i++){
        int countLinkedList = countChain(i);
        
        if(countLinkedList == 0)
            c0++;
        else if(countLinkedList == 1)
            c1++;
        else if(countLinkedList == 2)
            c2++;
        else if(countLinkedList == 3)
            c3++;
        else if(countLinkedList == 4)
            c4++;
        else if(countLinkedList == 5)
            c5++;
        else if(countLinkedList == 6)
            c6++;
        else if(countLinkedList == 7)
            c7++;
        else if(countLinkedList == 8)
            c8++;
        else if(countLinkedList == 9)
            c9++;
        else if(countLinkedList == 10)
            c10++;
        
    }
    
    cout<<endl;
    cout<<"Number of NO Elements = "<<c0<<endl;
    cout<<"Number of 1 Elements = "<<c1<<endl;
    cout<<"Number of 2 Elements = "<<c2<<endl;
    cout<<"Number of 3 Elements = "<<c3<<endl;
    cout<<"Number of 4 Elements = "<<c4<<endl;
    cout<<"Number of 5 Elements = "<<c5<<endl;
    cout<<"Number of 6 Elements = "<<c6<<endl;
    cout<<"Number of 7 Elements = "<<c7<<endl;
    cout<<"Number of 8 Elements = "<<c8<<endl;
    cout<<"Number of 9 Elements = "<<c8<<endl;
    cout<<"Number of 10 Elements = "<<c10<<endl;
    cout<<endl;
    
}
string generateStr(const int lengthString, bool isInitial){
    
    //Char array of possible characters
    const char letters[] = {'A','B','C','D','E','F','G','H','I','J','K','L',
                    'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    //Stores the number of elements in char[] letters
    int lengthStr = sizeof(letters);
    
    //Allocate memory for random strings
    char* rndKey = new char[lengthString+1];
    int rndSize;
    //Assigning ascii values into key
    for(int i = 0; i < lengthString; i++){
          
        rndKey[i] = letters[rand()%lengthStr];
    
    }
    
    rndKey[lengthString] = '\0';
    //Display key
    //string temp = (rndKey)
    
    string temp = rndKey;
    
    //deallocate memory
    delete[] rndKey;
    return temp;
}


Hash::Hash(){
    numItem = 0;
    cmpH = 0;
    eqH = 0;
    incrH = 0;
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new Item;
        HashTable[i]->initial = "empty";
        HashTable[i]->next = NULL;
    }
        
        
}

/* 2 -> ABC
 * 3 -> DEF
 * 4 -> GHI
 * 5 -> JKL
 * 6 -> MNO
 * 7 -> PQRS
 * 8 -> TUV
 * 9 -> WXYZ
 */
int Hash::phoneHash(string init, bool isInsert){
    eqH++;
    int hashVal = 0;
    int temp;
    stringstream ss;
    
    cmpH++;
    for(int i = 0; i < 3; i++){
        cmpH+=3;
        if(init[i] == 'A' || init[i] == 'B' || init[i] == 'C'){
            temp = 2;
        }else if(init[i] == 'D' || init[i] == 'E' || init[i] == 'F'){
            cmpH+=3;
            temp = 3;
        }else if(init[i] == 'G' || init[i] == 'H' || init[i] == 'I'){
            cmpH+=6;
            temp = 4;
        }else if(init[i] == 'J' || init[i] == 'K' || init[i] == 'L'){
            cmpH+=9;
            temp = 5;
        }else if(init[i] == 'M' || init[i] == 'N' || init[i] == 'O'){
            cmpH+=12;
            temp = 6;
        }else if(init[i] == 'P' || init[i] == 'Q' || init[i] == 'R' || init[i] == 'S'){
            cmpH+=16;
            temp = 7;
        }else if(init[i] == 'T' || init[i] == 'U' || init[i] == 'V'){
            cmpH+=19;
            temp = 8;
        }else if(init[i] == 'W' || init[i] == 'X' || init[i] == 'Y' || init[i] == 'Z'){
            cmpH+=21;
            temp = 9;
        }
        
        
        eqH++;
        ss << "" << temp;
        
        if(isInsert == true){
            cmpH = 0;
            eqH = 0;
        }
    }
    ss >> hashVal;
return hashVal;}


void Hash::insert(string initial){
    numItem++;
    int index = phoneHash(initial, true) % 512; //get an integer index from hash with name as the key
    
    //Check if that index of the Hash Table array is empty
    if(HashTable[index]->initial == "empty"){
        //if it is then go ahead an assign the values accordingly
        HashTable[index]->initial = initial;
    }else{
        
        
        //if not then create a pointer pointing to the index of the array for CHAINING
        Item *ptrHashTable = HashTable[index];
        Item *n = new Item; //Creating new Item to store info if HashTable[index] is filled already
        
        //Assign values to the new node
        n->initial = initial;
        n->next = NULL;

        //Traverse until you reach the end of this chain
        while(ptrHashTable->next != NULL){
            ptrHashTable = ptrHashTable->next;

        };

        //Have the last Item on that chain point to our newest item
        ptrHashTable->next = n;
        
    }
}

//Counts the number of BUCKETS in an index; index + chain(s)
int Hash::countChain(int index){
    Item *ptr = HashTable[index];
    int counter = 0;
    
    if(HashTable[index]->initial == "empty"){
        return counter;
    }
    while(ptr != NULL){
        counter++;
        ptr = ptr->next;
    };
return counter;}


//Prints out entire hash table
void Hash::printTable(){
    int numOfItems = 0;
    for(int i = 0; i < tableSize; i++)
        numOfItems += countChain(i);    //Gets total number of in items in a chain
    cout<<"Number of Items in the Hash Table: "<<numOfItems;
    cout<<"\n--------------------------------\n";
    for(int i = 0; i < tableSize; i++){
        cout<<"*[ "<<i<<" ]* -> ";
        cout<<"{ "<<HashTable[i]->initial<<" }";
        if(HashTable[i]->initial != "empty"){
            Item *ptr = HashTable[i];
            while(ptr != NULL){
                cout<<" --> [ "<<ptr->initial<<" ]";
                ptr = ptr->next;
            };
        }
        cout<<endl;
    }
}


//Prints only one bucket
void Hash::printItem(int index){
    cout<<"HashTable[ "<<index<<" ]->name = "<<HashTable[index]->initial<<endl;
    
    //if(HashTable[index]->name != "empty")
    //    cout<<"HashTable[ "<<index<<" ]->initial = "<<HashTable[index]->initial<<endl;
    if(countChain(index) > 1){
        Item *ptr = HashTable[index];
        cout<<"\t\t\t\t";
        while(ptr != NULL){
            cout<<" --> [ "<<ptr->initial<<" ]";
            ptr = ptr->next;
            
        };
    }
}

void Hash::hashFoundItem(const string key){
    eqH+=2;
    int index = phoneHash(key, false) % 512;
    
    cmpH++;
    if(HashTable[index]->initial == "empty")
        cout<<"\nNOT FOUND in HASH\n";
    else
        cout<<"\nFOUND in HASH\n";
    
}

void Hash::getOpStatHash(){
    cout<<"Operations for Hash";
    cout<<"\n-------------------\n";

    cout<<"Number of Compare Operations: "<<cmpH<<endl;
    cout<<"Number of Arithmetic (+, -, /, *, =) Operations: "<<eqH<<endl;
    cout<<"Number of Increment Operations: "<<incrH<<endl;
    cout<<"Total Numbers of Operations: "<<cmpH+eqH+incrH<<endl;
}
