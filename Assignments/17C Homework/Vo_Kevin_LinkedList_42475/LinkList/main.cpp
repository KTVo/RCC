//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Assignment LinkedList
 * Created on February 22, 2018 8:40 PM
 * Purpose:  Linked List Version 1 - Procedures with ADT
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here
#include "Link.h"

//Global Constants Only, No Global Variables

//Function Prototypes Here
Link *fillLst(int);         //Fill a linked list, count backwards
void  prntLst(Link *);      //Print each data element in the list
void  destLst(Link *);      //Destroy the list/deallocate
Link * endLst(Link *);      //Find the end of the list
void   addLst(Link *,int);  //Add data at the end of the list
int   findLst(Link *,int);  //Determine what link contains the data
Link * fndLst(Link *,int);  //Determine address of link that contains the data
int    cntLst(Link *);      //How many elements are in the list
void deleteByVal(Link *, int);
void insertBeforeVal(Link *, int, int);
void insertAfterVal(Link *, int, int);
Link *addFirst(Link*, int);


//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare a pointer to the linked list and data to test in link creation
    Link *lnkList;
    int numList=8,valAdd=42,valFnd1=5,valFnd2=2222;
    int delValue = 2; //holds value to be deleted by deleteByValue(Link *, int)
    int inValFirst = 1111;
    int inValAfter = 2222;
    int inValBefore = 3333;
    int findVal = 4;
    
    //Fill the linked list
    lnkList=fillLst(numList);
    
    //Print the entire list
    prntLst(lnkList);
    
    //Add a value to the end of the list
    addLst(lnkList,valAdd);
    
    //Print the entire list after adding to it
    prntLst(lnkList);
    
    cout<<"\nDeleting value 2\n\n";
    deleteByVal(lnkList, delValue);
    
    //Print the entire list after adding to it
    prntLst(lnkList);
    
    cout<<"\nInserting value "<<inValBefore<<" before "<<findVal<<endl<<endl;
    insertBeforeVal(lnkList, findVal, inValBefore);
    
    //Print the entire list after adding to it
    prntLst(lnkList);
    
    cout<<"\nInserting value "<<inValAfter<<" after "<<findVal<<endl<<endl;
    insertAfterVal(lnkList, findVal, inValAfter);
    
    //Print the entire list after adding to it
    prntLst(lnkList);
    
    cout<<"\nAdding "<<inValFirst<<" at the beginning of the Linked List\n";
    lnkList=addFirst(lnkList, inValFirst);
    
    //Print the entire list after adding to it
    prntLst(lnkList);
    
    //Find some values in the List
    cout<<valFnd1<<" is found at link    "<<findLst(lnkList,valFnd1)<<endl;
    cout<<valFnd1<<" is from the address where data = "
            <<fndLst(lnkList,valFnd1)->data<<endl;
    cout<<valFnd2<<" is found at link   "<<findLst(lnkList,valFnd2)<<endl;
    cout<<"The number of elements in the list = "<<cntLst(lnkList)<<endl;
    
    cout<<endl<<"Deleting Linked List...\n\n";
    //Deallocate memory for the Linked List
    destLst(lnkList);
    
    const int incSize = 8;
    cout<<"Constructing a new Linked List with "<<incSize<<" values...\n\n";
    
    //Fill the linked list
    lnkList=fillLst(incSize);
    
    //Print the entire list after adding to it
    prntLst(lnkList);
    
    cout<<"Inserting value 8989 BEFORE and AFTER 2 and DELETING value 5...\n";
    insertBeforeVal(lnkList, 2, 8989);
    insertAfterVal(lnkList, 2, 8989);
    deleteByVal(lnkList, 5);
    
    //Print the entire list after adding to it
    prntLst(lnkList);
    
    destLst(lnkList);
    //Exit
    return 0;
}


//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Create a linked list and fill with data
//Input  -> n      The number of elements in the list to create
//Output -> front  The address to the front of the allocated list.
Link *fillLst(int n){
    //Think of this part as the constructor
    Link *front=new Link;//Allocate a link at the front of the list
    front->data=n;       //Initialize with data
    front->linkPtr=NULL; //At the moment not pointing it to anything
    Link *next=front;    //Create a pointer to progress through the list

    
    while(--n>0){
       Link *temp=new Link; //Allocate a new link
       temp->data=n;        //Fill with data
       temp->linkPtr=NULL;  //Place at the end
       next->linkPtr=temp;  //Hook the new link to the end of the list
       next=temp;           //Move the pointer to the end
    };          //Continue till you count down to Zero
    //Exit by return the original link pointer
    return front;           //Return the front pointer to the list
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Print the entire contents of the linked list
//Input -> front  The address to the front of the allocated list.
//Output-> Display the entire linked list.
void  prntLst(Link *front){
    Link *next=front;           //Create a pointer to the list
    cout<<endl<<"The Beginning of the List"<<endl;
    while(next!=NULL){
        cout<<next->data<<endl; //Print the contents of the link
        next=next->linkPtr;     //Go to the next link in the list
    };         //Loop until reaching the end
    cout<<"The End of the List"<<endl<<endl;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Deallocate the entire list from the front to the end.
//Input -> front  The address to the front of the allocated list.
//Output-> Deallocate and return a NULL for the linked list pointer.
void  destLst(Link *front){
    while(front!=NULL){
       Link *temp=front->linkPtr;   //Point to the next link in the list
       delete front;                //Delete the front of the list
       front=temp;                  //Swap the front
    };
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the address of the last link in the list
//Input -> front  The address to the front of the allocated list.
//Output-> The address of the last link in the list
Link  *endLst(Link *front){
    Link *temp=front,*next; //Declare pointers used to step through the list
    while(temp!=NULL){
        next=temp;          //Point to the current link with a swap
        temp=temp->linkPtr; //Point to the next link
    };     //Your done when you hit the end
    return next;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Add a link and data to the end of the list
//Input -> front  The address to the front of the allocated list.
//         data   Data to embed at the last link in the list
void   addLst(Link *front,int data){
    Link *last=endLst(front);  //Find the last link
    Link *add=new Link;        //Create the new link
    add->data=data;            //Add the data
    add->linkPtr=NULL;         //Set the pointer to NULL
    last->linkPtr=add;         //Point to the new end of the list
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the number of the link that matches the data
//Input -> front  The address to the front of the allocated list.
//Output-> The Link number from the front where the data is found
int   findLst(Link *front,int value){
    int n=0;                //Initialize the counter
    Link *temp=front;       //Prepare to traverse the Linked list
    while(temp!=NULL){
        n++;                //Increment the counter
        if(temp->data==value)return n;//Return where the data is found
        temp=temp->linkPtr; //Move to the next link
    };     //End when reaching the end of the linked list
    return 0;               //Not found then return a 0;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the address of the link that matches the data
//Input -> front  The address to the front of the allocated list.
//Output-> The Link address from the front where the data is found
Link  *fndLst(Link *front,int value){
    Link *temp=front;       //Set the cursor to move through the list
    while(temp!=NULL){
        if(temp->data==value)return temp;  //Address of data match
        temp=temp->linkPtr;                //Next link in the list
    };                    //End of the list
    return NULL;                           //Not found
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//Function Find the number of links in the list
//Input -> front  The address to the front of the allocated list.
//Output-> The number of links in the list
int   cntLst(Link *front){
    int n=0;            //Initialize the counter
    Link *temp=front;   //Set the cursor to the front
    while(temp!=NULL){
        n++;            //Increment the counter
        temp=temp->linkPtr;//Move to the next link
    }; //Loop until the end is reached
    return n;           //Return the counter value
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

void deleteByVal(Link *front, int val){
    int location = findLst(front, val);
    
    if(location == 0){
        cout<<"\nNo such value present.\nNote: searched value must be != 0\n";
    }else{
    
        Link *current = new Link;
        Link *previous = new Link;
        current = front;
        for(int i = 1;i < location; i++){
        previous = current;
        current = current->linkPtr;
        }
        previous->linkPtr = current->linkPtr;
    }
}

void insertBeforeVal(Link *front, int findVal, int inVal){
    int location = findLst(front, findVal);
  
    if(location == 0){
        cout<<"\nNo such value present.\nNote: searched value must be != 0\n";
    }else{
        Link *next = front;
    
        //checks if list is empty
        if (front == NULL){
            //allocates memory for a new node
            Link* newNode = new Link;
 
            //set value to the new node
            newNode->data = inVal;
            newNode->linkPtr = NULL;
        
        }else{//if list already has content
        
            //allocates memory for a new node
            Link* newNode = new Link;
        
            newNode->data = inVal;
            newNode->linkPtr = NULL;
 
            Link* ptr = front;
            int length = 0;
 
            //finds the number of nodes on the list
            while (ptr != NULL) {
                length++;
                ptr = ptr->linkPtr;
            }
 
            //set to location to before the node of the found value
            int locBefore = location-1;
            ptr = front;
 
            //set pointer to the next node
            while(locBefore-- > 1){
                ptr = ptr->linkPtr;
            };
        
            //hook in new node
            newNode->linkPtr = ptr->linkPtr;
            ptr->linkPtr = newNode;
        }
    }
}


void insertAfterVal(Link *front, int findVal, int inVal){
    int location = findLst(front, findVal);
  
    if(location == 0){
        cout<<"\nNo such value present.\nNote: searched value must be != 0\n";
    }else{
        Link *next = front;
    
        //checks if list is empty
        if (front == NULL){
            //allocates memory for a new node
            Link* newNode = new Link;
 
            //set value to the new node
            newNode->data = inVal;
            newNode->linkPtr = NULL;
        
        }else{//if list already has content
        
            //allocates memory for a new node
            Link* newNode = new Link;
        
            newNode->data = inVal;
            newNode->linkPtr = NULL;
 
            Link* ptr = front;
            int length = 0;
 
            //finds the number of nodes on the list
            while (ptr != NULL) {
                length++;
                ptr = ptr->linkPtr;
            }
 
            //set to location to before the node of the found value
            int locBefore = location;
            ptr = front;
 
            //set pointer to the next node
            while(locBefore-- > 1){
                ptr = ptr->linkPtr;
            };
        
            //hook in new node
            newNode->linkPtr = ptr->linkPtr;
            ptr->linkPtr = newNode;
        }
    }
    
}

Link *addFirst(Link *front, int a){
    Link *newNode;
    newNode = new Link;
    newNode ->linkPtr = NULL;
    newNode ->data = a;
    newNode ->linkPtr = front;
    front = newNode;
    return front;           //Return the front pointer to the list
        
   
  
    }
    

