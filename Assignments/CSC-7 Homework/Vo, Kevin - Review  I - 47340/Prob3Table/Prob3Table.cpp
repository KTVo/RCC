#include "Prob3Table.h"

Prob3Table::Prob3Table(char * txtFile, int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    grandTotal = 0;
    
    rowSum = new int [rows];
    colSum = new int [cols];
    table = new int [rows*cols];
    
    for(int i = 0; i < rows; i++)
        rowSum[i] = 0;
    for(int i = 0; i < cols; i++)
        colSum[i] = 0;
    for(int i = 0; i < (rows*cols); i++)
        table[i] = 0;

    ifstream streamOP;
    
    streamOP.open(txtFile);
 
    char tChar; //stores characters from .txt
    string storeChar = "";  //takes tChar as a string to be converted to integer
    int counter = 0; //Counts the number of space
    int counterSpace = 0; //counts every potential space
    
    while(!streamOP.eof()){
        streamOP >> tChar;
        storeChar += tChar;
        counterSpace++;

        //resets the string after every 3 iterations to ensure integers are correct since they're all 3 digits
        if(counterSpace == 3){
            counterSpace = 0;
            int tInt = atoi(storeChar.c_str()); //converts string to integer
            table[counter] = tInt;
            storeChar = ""; //resets the string so next number can be stored into it to keep its value after conversion
            counter++;
        }
        
     
    }
    
    streamOP.close();   //Closes the text file once info as been extracted
    
    calcTable(); //

}

void Prob3Table::calcTable(){
    int n = 0,  //index for rowSum[]
        m = 0;  //identifies when a row is over
    int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5; //use to match elements by its column
    int l = 0; //index for colSum[] of first 6 elements
    
    
    for(int i = 0; i < rows*cols; i++){
        
        if(i % cols == 0 && i != 0)
            n++;
        
        rowSum[n] += table[i];

        if(m == 6){
            a+=6;
            b+=6;
            c+=6;
            d+=6;
            e+=6;
            f+=6;
            m = 0;
        }    

        //identifies elements by its column in order to find the sum for each column
        if(i >= 0 && i <= 5){
            colSum[l] = table[i];
            l++;
        }else if(i == a){
            colSum[0] += table[i];  
        }else if(i == b){
            colSum[1] += table[i];
        }else if(i == c){
            colSum[2] += table[i];
        }else if(i == d){
            colSum[3] += table[i];
        }else if(i == e){
            colSum[4] += table[i];
        }else if(i == f){
            colSum[5] += table[i];
        }
        m++;

    }
    
    for(int k = 0; k < 5; k++)
        grandTotal += rowSum[k];
                
    
}
