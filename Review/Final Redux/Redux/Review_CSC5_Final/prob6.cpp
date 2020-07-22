//Purpose: Display Numbers in Cols & Rows then display it's total Sum

#include <iostream>
using namespace std;

void prob6(){
    const int sz = 5;   //Holds value for both Dimension of table
    int rndNum[sz][sz]; //Holds values for table
    int sumCol[sz] = {0};   //Stores the sum for each column
    int sumRow[sz] = {0};   //Stores the sum for each row
    
    //Counters for sumRow
    int cntCol = 0,
        cntRow = 0;
    
    //Counters for sumCol
    int cntCol2 = 0,
        cntRow2 = 0;
    
    //Assign random Integers for 2D-Array (the table)
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < sz; j++)
            rndNum[i][j] = rand()%10;
     
    //Calculate the sumRow & sumCol
    while(cntCol < sz){
        sumRow[cntCol] += rndNum[cntCol][cntRow++];
        
        sumCol[cntRow2] += rndNum[cntCol2++][cntRow2];
        
        //Calculation to allow traversal of rndNum[col][row] and Ints from it
        //to be stored
        if(cntRow == sz){
            cntCol++;
            cntRow = 0;
            
            cntRow2++;
            cntCol2 = 0;
            
        }
    }; 
    
    //reset count for row to display sum of row in table
    cntRow = 0;
    
    cout<<"\n--- Table ---\n";
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            cout<<rndNum[i][j]<<"  ";
        
            if(j != 0 && j%(sz-1) == 0)
                cout<<sumRow[cntRow++];
            
        }
        
        cout<<endl;
    }
    
    //Displays the sum for each table
    for(int i = 0; i < sz; i++)
        cout<<sumCol[i]<<" ";
}