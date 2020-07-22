/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Problem: Gaddis Problem 6.4
 * Description: Determines which region has the fewest accidents reported     
 * Created on May 10, 2012, 10:32 AM
 */

#include <cstdlib>
#include <iostream>

int N, S, E, W, C;

using namespace std;

int getNumAccidents();
void findLowest();

int main(int argc, char** argv) {
    
    cout<<"This program will store and determine the lowest reported automobile"
        <<" accidents that occurred in majors cities within each region.\n\n";    

    getNumAccidents();
    findLowest();
    
    return 0;
}

int getNumAccidents(){
    cout<<"How many accident were reported within the past year in the northern"
        <<" region? ";
    cin>>N;
    
    cout<<"How many accident were reported within the past year in the southern"
        <<" region? ";
    cin>>S;
    
    cout<<"How many accident were reported within the past year in the eastern"
        <<" region? ";
    cin>>E;
    
    cout<<"How many accident were reported within the past year in the western"
        <<" region? ";
    cin>>W;
    
    cout<<"How many accident were reported within the past year in the central"
        <<" region? ";
    cin>>C;  
    
    if (N<0||S<0||E<0||C<0||W<0){
        cout<<"Input Validation: Do not accept an accident number that is less "
            <<"than 0.\n";
        exit (0);
    }
}

void findLowest(){
    
    
    if (N<S && N<E && N<W && N<C){
        cout<<"The region NORTH has the smallest amount recorded with a total "
            <<"of "<<N<<" accidents.\n";    
    }
    else if (S<N && S<E && S<W && N<C){
    cout<<"The region SOUTH has the smallest amount recorded with a total "
            <<"of "<<S<<" accidents.\n";    
    }
    else if (E<S&&E<N&&E<W&&E<C){
    cout<<"The region EAST has the smallest amount recorded with a total "
            <<"of "<<E<<" accidents.\n";  
    }
    else if (W<S&&W<N&&W<E&&W<C){
    cout<<"The region WEST has the smallest amount recorded with a total "
            <<"of "<<W<<" accidents.\n"; 
    }
    else if (C<S&&C<N&&C<W&&C<E){
        cout<<"The region CENTRAL has the smallest amount recorded with a total "
            <<"of "<<C<<" accidents.\n"; 
    }
        
}


