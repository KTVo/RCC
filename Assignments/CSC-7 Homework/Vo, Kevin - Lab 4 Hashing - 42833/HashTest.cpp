/*
 * Name: Kevin Vo
 * Instructor: Dr. Lehr
 * Student ID: 2394221
 * Class: CSC-7 (42833)
 * Assignment: Lab 4 Hashing
 * Date: April 25, 2016
 * File: HashTest.cpp --- MAIN
 */

/*
 **************************************************************************
 *                                                                        *
 *           General Purpose Hash Function Algorithms Test                *
 *                                                                        *
 * Author: Arash Partow - 2002                                            *
 * URL: http://www.partow.net                                             *
 * URL: http://www.partow.net/programming/hashfunctions/index.html        *
 *                                                                        *
 * Copyright notice:                                                      *
 * Free use of the General Purpose Hash Function Algorithms Library is    *
 * permitted under the guidelines and in accordance with the most current *
 * version of the Common Public License.                                  *
 * http://www.opensource.org/licenses/cpl1.0.php                          *
 *                                                                        *
 **************************************************************************
*/


#include <iostream>
#include <string>
#include "GeneralHashFunctions.h"

int main(int argc, char* argv[])
{
   std::string key = "Then out spake brave Horatius, "
           "The Captain of the Gate: "
           "To every man upon this earth "
           "Death cometh soon or late. "
           "And how can man die better "
           "Than facing fearful odds, "
           "For the ashes of his fathers, "
           "And the temples of his gods.";

   std::cout << "General Purpose Hash Function Algorithms Test" << std::endl;
   std::cout << "By Arash Partow - 2002        " << std::endl;
   std::cout << "Key: "                          << key           << std::endl;
   std::cout << " 1. RS-Hash Function Value:   " << RSHash(key)   << std::endl;
   std::cout << " 2. JS-Hash Function Value:   " << JSHash(key)   << std::endl;
   std::cout << " 3. PJW-Hash Function Value:  " << PJWHash(key)  << std::endl;
   std::cout << " 4. ELF-Hash Function Value:  " << ELFHash(key)  << std::endl;
   std::cout << " 5. BKDR-Hash Function Value: " << BKDRHash(key) << std::endl;
   std::cout << " 6. SDBM-Hash Function Value: " << SDBMHash(key) << std::endl;
   std::cout << " 7. DJB-Hash Function Value:  " << DJBHash(key)  << std::endl;
   std::cout << " 8. DEK-Hash Function Value:  " << DEKHash(key)  << std::endl;
   std::cout << " 9. FNV-Hash Function Value:  " << FNVHash(key)  << std::endl;
   std::cout << "10. BP-Hash Function Value:   " << BPHash(key)   << std::endl;
   std::cout << "11. AP-Hash Function Value:   " << APHash(key)   << std::endl;

   return true;
}
