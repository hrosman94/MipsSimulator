#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
#include <string> 

using namespace std;

void RF_read(string [], string, int &, int &);
void in_ALU(string, int);  
void inFetchALU(vector <string>, int &); 
void in_ALU2(int); 
void in_Mem(int [], int, int, string);  
void writeBack(int [], int, int); 
void printArry(); 

#endif