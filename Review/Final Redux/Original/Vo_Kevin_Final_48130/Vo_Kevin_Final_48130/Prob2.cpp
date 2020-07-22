#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <fstream>
#include <cctype>
#include <cstring>

using namespace std;
template<class T>
class Prob2Sort
{
    private:
	int *index; //Index that is utilized in the sort
    public:
	Prob2Sort(){index=NULL;}; //Constructor
	~Prob2Sort(){delete []index;}; //Destructor
	T * sortArray(const T*,int,int,bool);//Sorts a single column array
		
}; 

template <class T>
T* Prob2Sort<T>::sortArray(const T* val,int colSize, int colNum, bool order){
           
    //Declares format under a template and index as dyn array
    T format, *index = new T[colSize*colNum];

    //Assigns every array index to val[]        
    for(int x =0 ; x < colSize; x++){
        index[x] = val[x];
    }
  
    for(int x = 0; x < colSize - 1; x++){
        for(int y = x; y < colSize; y++){
            if(index[y][colNum-1] < index[x][colNum-1] && !order || 
                index[y][colNum-1] > index[x][colNum-1] && order){ 
                format = index[x];
                index[x] = index[y];
                index[y] = format;
            }
        }
    }

return index;} 

void prob2Main(){
    int arr = 0;
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort<string> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);    
    string ch2[10];
    while(getline(infile, ch2[arr])){cout<<ch2[arr]<<endl;arr++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    cout<<"Note: Enter 15 to change column 15.\n";
    int column;
    cin>>column;

    string *zc=rc.sortArray(ch2,10,column,ascending);

    for(int i=0;i<10;i++)
    {
        cout<<zc[i]<<endl;
    }
    cout<<endl;
}