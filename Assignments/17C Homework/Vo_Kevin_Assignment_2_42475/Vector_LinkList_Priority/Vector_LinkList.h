/* 
 * File:   Vector_LinkedList.h
 * Author: Kevin Vo
 * Assignment: Assignment 2
 * Purpose: Single linked list initially sorted but transforms to a priority on request
 * Course: CSC-17C (42475)
 * Created on March 27, 2018, 1:59 PM
 */

#ifndef VECTOR_LINKLIST_H
#define VECTOR_LINKLIST_H
#include <cstdlib>
#include "Link.h"

template<class T>
class LinkList{
    private:
        Link<T> *front;
        int *count;
    public:
        int *getCount(){ return count;}
        //Constructor
        LinkList(){
            front = NULL;
        }
        //Destructor
        ~LinkList(){
            while(front != NULL){
                Link<T> *temp = front;
                front = front->linkPtr;
                delete temp;
            }
            delete front;
        }
        
        
        
        Link<T> *fillList(T inVal){
            Link<T> *next = new Link<T>;
            next->data = inVal;
            next->linkPtr = NULL;
            
        return next;}
        
        
        void push(T inVal){
            if(front == NULL){
                front = fillList(inVal);
                
            }
            else{
                Link<T> *temp = fillList(inVal);
                temp->linkPtr = front;
                front = temp;
            }
            //Sorts after added every new value
            bubbleSort();
        }
        
        void pushNoSort(T inVal){
            if(front == NULL){
                front = fillList(inVal);
                
            }
            else{
                Link<T> *temp = fillList(inVal);
                temp->linkPtr = front;
                front = temp;
            }
        }
        
        void pop(){
            std::cout<<"Popped: "<<endLst(front)->data<<"\n";
            deleteElemAt(cntLst());
        }
        
        //000000001111111112222222222333333333344444444445555555555666666666677777777778
        //345678901234567890123456789012345678901234567890123456789012345678901234567890
        //Function Print the entire contents of the linked list
        //Input -> front  The address to the front of the allocated list.
        //Output-> Display the entire linked list.
        void prntLst(){
            Link<T> *next=front;           //Create a pointer to the list
            std::cout<<"\nThe Beginning of the List"<<std::endl;
            while(next!=NULL){
            std::cout<<next->data<<std::endl; //Print the contents of the link
            next=next->linkPtr;     //Go to the next link in the list
        };         //Loop until reaching the end
            std::cout<<"The End of the List"<<std::endl<<std::endl;
        }
        
        //000000001111111112222222222333333333344444444445555555555666666666677777777778
        //345678901234567890123456789012345678901234567890123456789012345678901234567890
        //Function Deallocate the entire list from the front to the end.
        //Input -> front  The address to the front of the allocated list.
        //Output-> Deallocate and return a NULL for the linked list pointer.
        void  destLst(){
            while(front!=NULL){
                Link<T> *temp=front->linkPtr;   //Point to the next link in the list
                delete front;                //Delete the front of the list
                front=temp;                  //Swap the front
            };
        }
        
        
        //000000001111111112222222222333333333344444444445555555555666666666677777777778
        //345678901234567890123456789012345678901234567890123456789012345678901234567890
        //Function Find the address of the last link in the list
        //Input -> front  The address to the front of the allocated list.
        //Output-> The address of the last link in the list
        Link<T> *endLst(Link<T> *front){
            Link<T> *temp=front,*next; //Declare pointers used to step through the list
        
            while(temp!=NULL){
                next=temp;          //Point to the current link with a swap
                temp=temp->linkPtr; //Point to the next link
            };     //Your done when you hit the end
        return next;}
        
        //000000001111111112222222222333333333344444444445555555555666666666677777777778
        //345678901234567890123456789012345678901234567890123456789012345678901234567890
        //Function Add a link and data to the end of the list
        //Input -> front  The address to the front of the allocated list.
        //         data   Data to embed at the last link in the list
        void   addLst(T data){
            Link<T> *last=endLst(front);  //Find the last link
            Link<T> *add=new Link<T>;        //Create the new link
            add->data=data;            //Add the data
            add->linkPtr=NULL;         //Set the pointer to NULL
            last->linkPtr=add;         //Point to the new end of the list
        }
        
        //000000001111111112222222222333333333344444444445555555555666666666677777777778
        //345678901234567890123456789012345678901234567890123456789012345678901234567890
        //Function Find the number of the link that matches the data
        //Input -> front  The address to the front of the allocated list.
        //Output-> The Link number from the front where the data is found
        int findLst(T value){
            int n=0;                //Initialize the counter
            Link<T> *temp=front;       //Prepare to traverse the Linked list
            
            while(temp!=NULL){
                n++;                //Increment the counter
                if(temp->data==value && n > 1)return n;//Return where the data is found
                temp=temp->linkPtr; //Move to the next link
            };     //End when reaching the end of the linked list
        return 0;               //Not found then return a 0;
        }
        
        //000000001111111112222222222333333333344444444445555555555666666666677777777778
        //345678901234567890123456789012345678901234567890123456789012345678901234567890
        //Function Find the address of the link that matches the data
        //Input -> front  The address to the front of the allocated list.
        //Output-> The Link address from the front where the data is found
        Link<T>  *fndLst(T value){
            Link<T> *temp=front;       //Set the cursor to move through the list
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
        int cntLst(){
            int n=0;            //Initialize the counter
            Link<T> *temp=front;   //Set the cursor to the front
            
            while(temp!=NULL){
                n++;            //Increment the counter
                temp=temp->linkPtr;//Move to the next link
            }; //Loop until the end is reached
            return n;           //Return the counter value
        }
        
        void deleteElemAt(int n){
        Link<T> *next=front;
        Link<T> *prev=NULL;
        
            if(n<=0||n>cntLst()){
                std::cout<<"\nIndex value has exceeded link list's size.\n\n";
                return;
            }    
            else if(n==1){
                front=next->linkPtr;
                delete next;
            }
            else{
                for(int i=0;i<n-2;i++){
                    next=next->linkPtr;
                }
                prev=next->linkPtr;
                next->linkPtr=prev->linkPtr;
                delete prev;
            }
        }
    
        void deleteByVal(T val){
            int location = findLst(val);
    
            if(location == 0){
                std::cout<<"\nNo such value present.\nNote: searched value must be != 0\n";
            }else{
    
                Link<T> *current = new Link<T>;
                Link<T> *previous = new Link<T>;
                current = front;
                for(int i = 1;i < location; i++){
                    previous = current;
                    current = current->linkPtr;
                }
                previous->linkPtr = current->linkPtr;
            }
        }
        
        
        void insertBeforeVal(T findVal, T inVal){
            int location = findLst(findVal);
  
            if(location == 0){
                std::cout<<"\nNo such value present.\nNote: searched value must be != 0\n";
            }else{
                Link<T> *next = front;
    
                //checks if list is empty
                if (front == NULL){
                    //allocates memory for a new node
                    Link<T> *newNode = new Link<T>;
 
                    //set value to the new node
                    newNode->data = inVal;
                    newNode->linkPtr = NULL;
        
                }else{//if list already has content
        
                    //allocates memory for a new node
                    Link<T> *newNode = new Link<T>;
        
                    newNode->data = inVal;
                    newNode->linkPtr = NULL;
 
                    Link<T> *ptr = front;
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
        
        
        void insertAfterVal(int findVal, int inVal){
            int location = findLst(findVal);
  
            if(location == 0){
                std::cout<<"\nNo such value present.\nNote: searched value must be != 0\n";
            }else{
                Link<T> *next = front;
    
                //checks if list is empty
                if (front == NULL){
                    //allocates memory for a new node
                    Link<T> *newNode = new Link<T>;
 
                   //set value to the new node
                    newNode->data = inVal;
                    newNode->linkPtr = NULL;
        
                }else{//if list already has content
        
                    //allocates memory for a new node
                    Link<T> *newNode = new Link<T>;
        
                    newNode->data = inVal;
                    newNode->linkPtr = NULL;
 
                    Link<T> *ptr = front;
                    int length = 0;
 
                    //finds the number of nodes on the list
                    while(ptr != NULL) {
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
        
        Link<T> *addFirst(T a){
            Link<T> *newNode;
            
            newNode = new Link<T>;
            newNode ->linkPtr = NULL;
            newNode ->data = a;
            newNode ->linkPtr = front;
            front = newNode;
            return front;           //Return the front pointer to the list
        
        }
        
        
        
        
        
        
        void swap(Link<T> *p, Link<T> *q){
            T temp;
            temp = p->data;
            p->data=q->data;
            q->data = temp;
        }
        

        
        //Sort 
        void bubbleSort(){
            Link<T> *next = front;
            Link<T> *qtr = NULL;
            int sorted = 0;
            do{
                sorted = 0;
                next = front;
    
                while(next->linkPtr != qtr){
                    if(next->data > next->linkPtr->data){
                        swap(next, next->linkPtr);
                        sorted = 1;
                    }
                    next = next->linkPtr;
                };
            
                qtr = next;
            }while(sorted);
        
        }
        
        void prepCounter(){
            int s = cntLst();
            int *temp = new int[s + 1];
            
            for(int i = 0; i < s + 1; i++)
                temp[i] = count[i];
            
            temp[s + 1] = 0;
            
            count = temp;
            delete[] temp;
        }
        
        //Set any value on the linked list to the beginning (as priority)
        void priority(int input, int index){
            deleteElemAt(index);
            this->front = addFirst(input);       
        }
        
       
        
        
        
    
};

#endif /* VECTOR_LINKLIST_H */

