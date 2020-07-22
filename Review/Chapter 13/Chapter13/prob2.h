#ifndef PROB2_H
#define PROB2_H

#include <iostream>

class Employee{
private:
    std::string name,               //Holds employee's name
                department,         //Hold department name
                position;           //Hold position title
    int idNumber;                   //Holds ID Number
    
public:
    //Constructor overloads
    Employee();
    Employee(std::string, std::string, std::string, int);
    Employee(std::string, int);
    

    //Mutators
    void setDep(std::string);

    void setPos(std::string);

    void setName(std::string);

    void setID(int);
    
    //Accessors
    std::string getDep() const {return department;}
    std::string getName() const {return name;}
    std::string getPos() const {return position;}
    int getID() const {return idNumber;}
    
};




#endif /* PROB2_H */

