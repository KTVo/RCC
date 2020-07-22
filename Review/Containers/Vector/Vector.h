/* 
 * File:   Vector.h
 * Author: Kevin
 *
 * Created on June 22, 2018, 5:04 PM
 */

#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class Vector{
private:
    T *arr;
    int cIndx;
    int size;
public:
    Vector();
    ~Vector();
    void insert(T);
    void adv_Insert(T);
    void deleteVal(T);
    void deleteIndx(int);
    T getValue(int);
    int get_num_filled() const {return cIndx;}
    void displayAll();
};

template <class T>
//Constructor
Vector<T>::Vector(){
    size = 10;
    arr = new T[size];
    cIndx = 0;
}

template <class T>
//Destructor
Vector<T>::~Vector(){
    delete[] arr;
}

template <class T>
//Inserts value onto the vector
void Vector<T>::insert(T inVal){
    
    if(cIndx < size){
        arr[cIndx++] = inVal;
    }else{
        T *temp = new T[++size];
        for(int i = 0; i < size - 1; i++)
            temp[i] = arr[i];
        temp[cIndx++] = inVal;
        
        delete[] arr;
        
        arr = new int[size];
        
        for(int i = 0; i < size; i++)
            arr[i] = temp[i];
        
        delete[] temp;
    }
}

template <class T>
//Inserts value onto the vector
void Vector<T>::adv_Insert(T inVal){
    
    if(cIndx < size){
        arr[cIndx++] = inVal;
    }else{
        size *= 2;
        T *temp = new T[size];
        for(int i = 0; i < size - 1; i++)
            temp[i] = arr[i];
        temp[cIndx++] = inVal;
        
        delete[] arr;
        
        arr = new int[size];
        
        for(int i = 0; i < size; i++)
            arr[i] = temp[i];
        
        delete[] temp;
    }
}

template <class T>
//Returns a value within index
T Vector<T>::getValue(int indx){

    if(indx > size - 1){
        cout<<"\nError: Index has exceeded the Vector's size of "<<size<<endl;
    }else{
        return arr[indx];
    }
    return 0;
}

template <class T>
//Deletes a value on vector
void Vector<T>::deleteVal(T inVal){
    int cntIndx = 0;
    for(int i = 0; i < size; i++)
        if(inVal == arr[i]){
            cIndx--;
            T *temp = new T[--size];
            for(int j = 0; j < size; j++){
                if(j == i)
                    cntIndx++;
                    temp[j] = arr[cntIndx++];
            }
            
            delete[] arr;
            arr = temp;
            cout<<"\n* Value "<<inVal<<" deleted. *"<<endl;
            break;
        }
    
}

template <class T>
//Deletes a value by index
void Vector<T>::deleteIndx(int indx){
    if(indx <= size){
        T *temp = new T[--size];

        int cntNewIndx = 0;

        for(int i = 0; i < size; i++){
            if(i == indx)
                cntNewIndx++;

            temp[i] = arr[cntNewIndx++];
        }

        delete[] arr;

        arr = temp;

        cIndx--;
        
        cout<<"\n* Index "<<indx<<" deleted. *"<<endl;
    }else
        cout<<"\nIndex to be deleted is out of bound.\n";
}


template <class T>
//Displays entire vector
void Vector<T>::displayAll(){
    for(int i = 0; i < cIndx; i++){
        cout<<arr[i];
        if(i < cIndx - 1)
            cout<<", ";
    }
    cout<<endl;
}


#endif /* VECTOR_H */

