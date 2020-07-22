/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Instructor: Dr. Lehr
 * Assignment: Lab 7 Merkle Tree
 * Course: CSC-7 (42833)
 * File: PJWHash.h
 * Created on June 5, 2016, 7:12 PM
 */

#ifndef PJWHASH_H
#define	PJWHASH_H

#include <string>

typedef unsigned int (*HashFunction)(const std::string&);

unsigned int PJWHash (const std::string& str);

#endif	/* PJWHASH_H */

