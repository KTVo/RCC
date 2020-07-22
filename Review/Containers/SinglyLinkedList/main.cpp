#include <iostream>

using namespace std;

#include "Link.h"

int main(){
    Link<int> l;
    
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    
    l.showList();
  
    l.removeByIndex(2);
    
    l.showList();
    
    l.insertByIndex(69, 3);
    
    l.showList();
    
    l.insertLast(44);
    
    l.showList();
    
    l.insert(99);
    
    l.showList();
    
    cout<<endl<<"-----------------------------------------------------"<<endl;
    
    Link<string> ls;
    
    ls.insert("Water");
    ls.insert("Coke");
    ls.insert("Sprite");
    ls.insert("Mountain Dew");
    ls.insert("Fanta Orange");
    ls.insert("Hi-C");
    
    ls.showList();
  
    ls.removeByIndex(3);
    
    ls.showList();
    
    ls.insertByIndex("Apple Juice", 3);
    
    ls.showList();
    
    ls.insertLast("Grape Juice");
    
    ls.showList();
    
    ls.insert("Orange Juice");
    
    ls.showList();
    
    ls.removeByVal("Mountain Dew");
    
    ls.showList();
return 0;}