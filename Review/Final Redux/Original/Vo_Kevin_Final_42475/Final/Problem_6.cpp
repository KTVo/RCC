/* 
 * File:   Problem_6.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Final
 * Created on May 31, 2018, 8:31 AM
 */

#include <iostream>

using namespace std;

 
//constant global variables
const int sizeVert = 7;     //Stores constant max number of vertices
const int maxValInt = 2147483647;   //Constant max cap for Integer data type
  
void prim(int[][sizeVert]);
int calMinDist(int[], bool[]);
int showMinSpanTree(int[], int, int [][sizeVert]);
int dijkstra(int [][sizeVert], int, int);
int minVal(int[], bool []);

void prob6(){
    cout<<endl;
    cout<<"*********************************************"<<endl;
    cout<<"*         Problem 6 - Weighted Graph        *"<<endl;
    cout<<"*********************************************"<<endl;
    
        enum dest {SFO, ORD, JFK, DFW, MIA, LAX, BOS};
    
    //graph input
                     
   int graph[sizeVert][sizeVert] = {
       
        /*SFO   ORD   JFK    DFW  MIA   LAX   BOS*/ 
        {0   , 1847, 0   , 1463, 0   , 338 , 2703},  //SFO
        {1847, 0   , 741 , 801 , 0   , 0   , 866 },  //ORD
        {0   , 741 , 0   , 0   , 1091, 0   , 188 },  //JFK
        {1463, 801 , 0   , 0   , 1122, 1234, 0   },  //DFW
        {0   , 0   , 1091, 1122, 0   , 2341, 1257},  //MIA
        {338 , 0   , 0   , 1234, 2341   , 0   , 0},  //LAX
        {2703, 866 , 188   , 0 , 1257, 0   , 0   }   //BOS
           
    };
    

    //Displays shortest distance from BOS to LAX
    cout<<"\nShortest Distance from BOS to LAX = "
        <<dijkstra(graph, BOS, LAX)<<endl;
 
    cout<<endl;
 
    //Displays minimum spanning tree with weighted value
    cout<<"\nMinimum Spanning Tree:";
    cout<<"\n-----------------------\n";
    prim(graph);
}

//Finds vertex with min. distance
int calMinDist(int arrDist[], bool isShortest[]){
    
   int min = maxValInt, minIndx;
  
   for(int i = 0; i < sizeVert; i++)
        if(isShortest[i] == false && arrDist[i] <= min)
         min = arrDist[i], minIndx = i;
  
   return minIndx;
}
  

  
//Uses dijkstra's algorithm to find shortest distance
int dijkstra(int graph[sizeVert][sizeVert], int start, int end){
     int arrDist[sizeVert]; //Holds the distances between start and end
  
     bool isShortest[sizeVert];
  
    for (int i = 0; i < sizeVert; i++)
        arrDist[i] = maxValInt, isShortest[i] = false;
  
    //assigning distance of vertex as itself
    arrDist[start] = 0;
  
    //searches for shortest distance
    for(int i = 0; i < sizeVert - 1; i++){
        int newMinDist = calMinDist(arrDist, isShortest);
  
        isShortest[newMinDist] = true;
  
        for (int cVert = 0; cVert < sizeVert; cVert++)
            if(!isShortest[cVert] && graph[newMinDist][cVert] && arrDist[newMinDist] 
               != maxValInt && arrDist[newMinDist]+graph[newMinDist][cVert] 
                    < arrDist[cVert])
                arrDist[cVert] = arrDist[newMinDist] + graph[newMinDist][cVert];
     }
  
     //returns the shortest distance between 2 vertices
     return arrDist[end];
}
  
//Selects new vertex
int minVal(int arrVal[], bool vertStat[]){
   // Initialize min value
   int min = maxValInt, min_index;
 
   for (int v = 0; v < sizeVert; v++)
     if (vertStat[v] == false && arrVal[v] < min)
         min = arrVal[v], min_index = v;
 
   return min_index;
}
 
//Displays results or minimum spanning tree
int showMinSpanTree(int parent[], int n, int graph[sizeVert][sizeVert]){
    const string airportNames[sizeVert] = {"SFO", "ORD", "JFK", "DFW", 
                                          "MIA", "LAX", "BOS"};
    cout<<"   Edge    \tWeight"<<endl;
    int weighted = 0;
    for (int i = 1; i < sizeVert; i++){
        int temp = graph[i][parent[i]];
        weighted += temp;
        cout<<airportNames[parent[i]]<<" - "<<airportNames[i]<<" -->\t"
                <<temp<<endl;
    }
    cout<<"\nWeighted = "<<weighted<<endl;
}
 
//Using prim to find the minimum spanning tree of graph
void prim(int graph[sizeVert][sizeVert]){
    int parent[sizeVert];
    int val[sizeVert];
    bool vertStat[sizeVert];

    for(int i = 0; i < sizeVert; i++)
        val[i] = maxValInt, vertStat[i] = false;

    val[0] = 0;
    parent[0]--; //The root of min. spanning tree

    for(int count = 0; count < sizeVert-1; count++){
        int newMin = minVal(val, vertStat);
 
        //set used vertices
        vertStat[newMin] = true;
 
        for (int cVert = 0; cVert < sizeVert; cVert++)
            if (graph[newMin][cVert] && vertStat[cVert] == false && 
                    graph[newMin][cVert] <  val[cVert])
                parent[cVert] = newMin, val[cVert] = graph[newMin][cVert];
     }
 
     //Shows minimum spanning tree
     showMinSpanTree(parent, sizeVert, graph);
}
 