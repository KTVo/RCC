/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 10, 2012, 7:44 PM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
    //Testing Character Strings
    char name1[]="Mark";
    char name2[]="mark";
    if(strcmp(name1,name2)>0){
        cout<<name2<<"<"<<name1<<endl;
    }
    if(strcmp(name1,name2)<0){
        cout<<name1<<"<"<<name2<<endl;
    }
    if(strcmp(name1,name2)==0){
        cout<<name1<<"=="<<name2<<endl;
    }
    return 0;
}

