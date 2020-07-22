#include "Prob1.h"

//The constructor
Prob1Random::Prob1Random( const char arrSize, unsigned char *rndseq){
    
    nset = arrSize;
    set = rndseq;
        
    const int size = 5;
        
    freq = new int [arrCount];

    for (int count = 0; count < size; count++){
            freq[count] = 0;
    }

    numRand = 0;
};

//Returns random number and set freq[] and int numRand
char Prob1Random::randFromSet(void){
    arrCount = rand()%5;

    numRand += 1; 

    freq[arrCount]++;


return set[arrCount];};


//The Destructor
Prob1Random::~Prob1Random(void){
    delete []freq;
};