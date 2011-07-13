#include "base.h"

//static int n;

int function() 
{
  return n; 
}
void function_set(int n1)
{ 
	n = n1; 
}

Base::Base ()
{}

int Base::getVariable()
{
	function();
}

void Base::baseFunction()
{}
