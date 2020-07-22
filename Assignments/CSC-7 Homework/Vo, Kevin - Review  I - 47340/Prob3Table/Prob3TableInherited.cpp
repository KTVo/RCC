#include "Prob3TableInherited.h"

Prob3TableInherited :: Prob3TableInherited(char *txtfile, int rows, int cols) : Prob3Table(txtfile, rows, cols){
    const int numElem = 42;
    augTable = new int[numElem];
    int lastRowCounter = 0;      //table index
    int counterSumRow = 0;      //rowSum index
    int counterSumCol = 0;      //colSum index
    int rowBreakCount = 0;  //counter per row
    
    for(int i = 0; i < numElem; i++){
        //augTable[] accepts all data from table[] except the last row
        if(i < 35){
            rowBreakCount++;//it keeps track of when a row ends to add the sum for that row
            augTable[i] = table[lastRowCounter++];
            if(rowBreakCount == cols){
                augTable[++i] = rowSum[counterSumRow++]; //adds the sum of the row
                rowBreakCount = 0; //resets for detecting when next row is about to end
            }
        }
        //once augTable has accept all rows but the last it'll start accepting the sums of columns
        else
            augTable[i] = colSum [counterSumCol++];
    }
    //Takes the very last data as the grand total
    augTable[numElem-1] = grandTotal;
}