#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

//I was unable to put this template in a different file without it failing
template<class T>
class Prob3Table{
    protected:
        int rows; //Number of rows in the table
        int cols; //Number of cols in the table
        T *rowSum; //RowSum array
        T *colSum; //ColSum array
        T *table; //Table array
        T grandTotal; //Grand total
        void calcTable(void); //Calculate all the sums
    public:
        Prob3Table(char *,int,int); //Constructor then Destructor
	~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
	const T *getTable(void){return table;};
	const T *getRowSum(void){return rowSum;};
	const T *getColSum(void){return colSum;};
	T getGrandTotal(void){return grandTotal;};
};

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
    protected:
	T *augTable; //Augmented Table with sums
    public:
	Prob3TableInherited(char *,int,int); //Constructor
	~Prob3TableInherited(){delete [] augTable;}; //Destructor
	const T *getAugTable(void){return augTable;}; 
};

//Calculate all the sums
template<class T>
void Prob3Table<T>::calcTable(void){
    for(int count = 0; count < rows; count++){
        for(int x = 0; x < cols; x++){
            rowSum[count] += table[count * cols + x];
        }
    }

    for(int x = 0; x < cols; x++){
        for(int y = 0; y < rows; y++){
            colSum[x] += table[y * cols + x];
        }
    }
}


//Constructor
template<class T>
Prob3Table<T>::Prob3Table(char *filename, int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    this->table = new T[rows*cols];
    this->rowSum = new T[rows];
    this->colSum = new T[cols];
    const int arrSize = 30;
  
    int numSet[arrSize] =   { 100,   101,   102,   103,   104,   105, 
                              106,   107,   108,   109,   110,   111, 
                              112,   113,   114,   115,   116,   117, 
                              118,   119,   120,   121,   122,   123, 
                              124,   125,   126,   127,   128,   131};

           for(int x = 0; x < rows; x++){
                for(int y = 0; y < cols; y++){
                    table[x * cols + y] = numSet[x * cols + y];
                }
            }
            
            grandTotal = 0;

        for(int x = 0; x < rows; x++){
            for(int y = 0; y < cols; y++){
                grandTotal += table [x*cols+y];
            }
        }

    this->calcTable();}

//Constructor
template<typename T>
Prob3TableInherited<T>::Prob3TableInherited(char *filename, int rows, int cols) 
: Prob3Table<T>::Prob3Table(filename, rows, cols){

    const T *table = this->getTable();
    const T *rowSum = this->getRowSum();
    const T *colSum = this->getColSum();

    augTable = new T[(rows+1)*(cols+1)];

    for(int x = 0; x < rows; x++){
        for(int y = 0; y < cols; y++){
            augTable[x * cols + y + x] = table[x * cols + y];
        }
    }

    for(int x = 0; x < rows + 1; ++x){
        augTable[(cols + 1) * x + cols] = rowSum[x];
    }

    for (int x = 0; x < cols + 1; ++x){
        augTable[((rows + 1) * cols) + x - 1] = colSum[x];
    }

    augTable[((rows + 1) * (cols + 1)) - 1] = 0;

    for (int x = 0; x < rows + 1; ++x){
        augTable[((rows + 1) * (cols + 1)) - 1] += rowSum[x];
    }
}

void prob3Main(){
    //Driver code
    cout<<"Entering problem number 3"<<endl;

    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    
    const int *naugT=tab.getTable();
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout<<naugT[i*cols+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
        {
            cout<<augT[i*(cols+1)+j]<<" ";
        }
        cout<<endl;
    }
    //Displays the grand total outside of the table
    cout<<"Grand Total = "<<tab.getGrandTotal()<<endl;
}