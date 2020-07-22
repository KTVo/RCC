/* 
 * File:   main.cpp
 * Author: Kevin
 * Problem: Gaddis Problem 6.10
 * Description: Determines the test scores' average
 * Created on May 11, 2012, 1:45 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void getScore(float &);
float calcAverage(float, float, float, float, float);
float findLowest(float, float, float, float, float);
int main(int argc, char** argv) {
   float val1, val2, val3, val4, val5, mainVal, totalAVG;
   int caller;
   
   cout << "This program will calculate the average of all the test scores ";
   cout << "combined,\nthen drops the lowest test score. \n\n";
   
   for (caller=0;caller<=4;caller++){
   
       getScore(mainVal);
       
   }
       totalAVG = calcAverage(val1, val2, val3, val4, val5);

       cout << "The average test score is " << totalAVG << endl;
    return 0;
}

void getScore(float &testScore)
   {

      cout<<"Please enter in the test score of one of the tests: ";
      cin>>testScore;

      if (testScore <0 || testScore > 100){
    cout<<"Input Validation: Do not accept test scores lower than 0 or higher than 100.\n";
    exit (0);
    }
      
   }


    float calcAverage(float score1, float score2, float score3, float score4, float score5)
    {float lowest, AVG;
      lowest=findLowest(score1, score2, score3, score4, score5);
      
      AVG=((score1+score2+score3+score4+score5)-lowest)/4;
       
       return AVG;
    }



    float findLowest(float tS1,float tS2,float tS3,
        float tS4,float tS5)
    {float lowest;
    
    if (tS1<tS2&&tS1<tS3&&tS1<tS4&&tS1<tS5){
        lowest = tS1;
    }
    if (tS2<tS1&&tS2<tS3&&tS2<tS4&&tS2<tS5){
        lowest = tS2;
    }
    if (tS3<tS1&&tS3<tS2&&tS3<tS4&&tS3<tS5){
        lowest = tS3;
    }
    if (tS4<tS2&&tS4<tS3&&tS4<tS1&&tS4<tS5){
        lowest = tS4;
    }
    if (tS5<tS2&&tS5<tS3&&tS5<tS4&&tS5<tS1){
        lowest = tS5;
    return lowest;}
}
