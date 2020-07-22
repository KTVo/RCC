/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Link.h
 * Author: dangerouspirate
 *
 * Created on June 21, 2018, 7:35 PM
 */

#ifndef LINK_H
#define LINK_H

template <class T>
class Link{
    private:
        struct Node{
            T data;       //Stores data
            Node* next;     //Points to the next Node
        }
        *head;
        
    public:
        //Constructor
        Link(){ head = NULL; }
        
        void insert(T);
        void showList();
        void removeByVal(T);
        int countNodes();
        void removeByIndex(int);
        void insertByIndex(T, int);
        void insertLast(T);
};


//Inserts Far Left
template <class T>
void Link<T>::insert(T inVal){
    if(head == NULL){
        head = new Node;
        head->data = inVal;
        head->next = NULL;
    }else{
        Node *temp = new Node;
        
        temp->data = inVal;
        temp->next = head;
        head = temp;
    }
}

//Displays entire linked list and number of nodes
template <class T>
void Link<T>::showList(){
    if(countNodes() > 0){
        Node *temp = head;

        cout<<endl;

        cout<<"Count = "<<countNodes()<<endl;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        };
    }else
        cout<<"\nEmpty\n";
    cout<<endl;
}

//Deletes one value on linked list
template <class T>
void Link<T>::removeByVal(T inVal){
    Node *temp = head;
    Node *prev;
    while(temp != NULL){
        prev = temp;
        
        if(inVal == head->data){
            head = head->next;
            return;
        }else if(temp->next->data == inVal){
            
            temp->next = temp->next->next;
            temp = prev;
            return;
        }
        temp = temp->next;
    };
}

//Returns the number of nodes
template <class T>
int Link<T>::countNodes(){
    int numNode = 0;
    Node *temp = head;
    while(temp != NULL){
        //numNode++;
        temp = temp->next;
        numNode++;
    };
return numNode;}

//Deletes Node by its numeric placement
template <class T>
void Link<T>::removeByIndex(int nNode){
    Node *temp = head;

    int maxNumNode = countNodes();
    
    if(nNode >= maxNumNode || nNode < 0){
        cout<<"\nError: Node's Place to be deleted is out of bound.\n";
    }else{
        
        if(nNode == 0){
            head = head->next;
            
        }else{
            for(int i = 0; i < nNode; i++){
                temp = temp->next;
            }

            temp->next = temp->next->next;
        }
    }
     
}

//Insert a value onto linked list anywhere
template <class T>
void Link<T>::insertByIndex(T inVal, int nNode){
    Node *temp;

    int maxNumNode = countNodes();
    
    if(nNode > maxNumNode || nNode < 0){
        cout<<"\nError: Node's Place to be inserted is out of bound.\n";
    }else{
        
        if(nNode == 0){
            temp = new Node;
            temp->data = inVal;
            temp->next = head;
            head = temp;
  
        }else{
            temp = head;
            for(int i = 0; i < nNode - 1; i++)
                temp = temp->next;
            
            Node* t = new Node;
            Node* t2 = temp->next;
            temp->next = t;
            t->data = inVal;
            t->next = t2;

           
        }
    }
}

//Insert value into far right
template <class T>
void Link<T>::insertLast(T inVal){
    insertByIndex(inVal, countNodes());
}

#endif /* LINK_H */

