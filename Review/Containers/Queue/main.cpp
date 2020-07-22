#include <iostream>
#include <cstdlib>

using namespace std;

class Queue{
    private:
        struct Node{
            int data;
            Node* prev;
        }
        *tail, *head;

        int cntNode;
        
    public:
        Queue();
        ~Queue();
        void push(int);
        void displayAll();
        int getValue();
        void pop();
        int getCntNode() const {return cntNode;}
};

Queue::Queue(){
    head = NULL;
    tail = NULL;
    cntNode = 0;

}

Queue::~Queue(){
    delete[] tail;
    delete[] head;
}

void Queue::pop(){
    tail = tail->prev;
}

int Queue::getValue(){
    return tail->data;
}

void Queue::push(int inVal){
    
    Node *temp = new Node;
    temp->data = inVal;
    temp->prev = NULL;
    
    if(tail == NULL)
        tail = temp;
    else
        head->prev = temp;
    
    head = temp;
    
    cntNode++;
}

void Queue::displayAll(){   
    if(tail != NULL){
        
        Node *temp = tail;

        cout<<endl<<endl;

        cout<<"Queue: ";
        
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->prev;
        };

        cout<<endl<<endl;
    }else 
        cout<<"\nQueue is EMPTY.\n";
    
}

int main(int argc, char** argv) {
    Queue q;
    
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    
    q.displayAll();
    
    for(int i = 0; i < q.getCntNode(); i++){
        cout<<q.getValue()<<endl;
        q.pop();
    }
    q.displayAll();
    
    return 0;
}

