#ifndef BASE_H 
#define BASE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Usage 1: static make function can only be used here, NOT outside like main.cpp
//so static function diff from static function of class
static int n;
static int function();
void function_set(int n1); 

class Base
{
	public:
		Base();
		int getVariable(); 
		static void baseFunction();
			//return n; }
};

#endif
