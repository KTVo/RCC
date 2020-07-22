/* 
 * File:   Problem_3.h
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Course: CSC-17C (42475)
 * Assignment: Final
 * Created on May 31, 2018, 8:31 AM
 */

#ifndef PROBLEM_3_H
#define PROBLEM_3_H

struct Clerk{
    bool serving;
    int timeBegin;
    int served;
    int time;
};

struct Service{

    int waitTime = 0;
    int totalCust = 0;
    bool waiting = true;
    bool avaliable = false;

};


#endif /* PROBLEM_3_H */

