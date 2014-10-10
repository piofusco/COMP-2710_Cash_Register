// Program:		Cash Register
// Name:		Michael Americo Pace
// Class:		COMP 2710
// Date: 		November 29, 2012
// Email: 		map0009@auburn.edu
//
// Description:	This serves as the driver for the cash register. Creates a Register object and which then calls
//				beginItemize. Will continue to indefinitely.
// Compile instructions: 	g++ main.cpp -o lab4
#include <iostream>
#include <vector>
#include "Register.h"

using namespace std;

int main(int argc, char *argv[])
{
	Register r = Register();
	while(true)
	{
		r.beginItemize();
	}
	return 0;	
}