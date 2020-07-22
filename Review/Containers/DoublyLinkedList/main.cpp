/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dangerouspirate
 *
 * Created on June 21, 2018, 8:57 PM
 */
#include <iostream>
#include <cstdlib>

using namespace std;

class DoublyLink{
    private:
        struct Node{
            int data;
            Node* prev;
            Node* next;
        }
        *head, *tail;
    
    public:
        DoublyLink() {head = NULL; tail = NULL;}
        void insertFront(int);
        void insertBack(int);
        void displayInOrder();
        void displayReverse();
        void removeByValue(int);
        
};


void DoublyLink::insertFront(int inVal){
    if(head == NULL){
        head = new Node;
        head->data = inVal;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }else{
        Node *temp = new Node;
        temp->data = inVal;
        temp->next = head;
        temp->prev = NULL; 
        head->prev = temp;
        head = temp;
        
    }
}

void DoublyLink::insertBack(int inVal){
    if(head == NULL){
        head = new Node;
        head->data = inVal;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }else{
        Node *temp = new Node;
        temp->data = inVal;
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        
    }
}

void DoublyLink::displayInOrder(){
    
    Node* temp = head;
    cout<<endl;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    };
    cout<<endl;
}

void DoublyLink::displayReverse(){
    
    Node* temp = tail;
    
    cout<<endl;
    
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    };
    
    cout<<endl;
}

void DoublyLink::removeByValue(int inVal){
    Node* temp = head;
    
    while(head != NULL){
        if(inVal == temp->data){
            return;
        }
        temp = temp->next;
    }
}


int main(int argc, char** argv) {
    
    DoublyLink d;
    
    d.insertFront(1);
    d.insertFront(2); //is head
    d.insertBack(0);
    d.insertBack(-1);
    d.insertBack(-2);//is tail
    
    d.displayInOrder();
    d.displayReverse();

    return 0;
}

