// Program:		Cash Register
// Name:		Michael Americo Pace
// Class:		COMP 2710
// Date: 		November 29, 2012
// Email: 		map0009@auburn.edu
//
// Description:	Class definition for class CheckSale.
#ifndef CHECKSALE_H
#define CHECKSALE_H
#include "Sale.h"
class CheckSale : public Sale
{
public:
	CheckSale(vector<string> inventory, vector<float> pricelist);

	string name;			// Member variable for name on check
	string driverslicense;	// Member variable for driver's license number

	void process_payment();
	void print_sale();
	void print_payment();
	void setCashReceived(float cashin);
	float getCashReceived();
	void setChangeGiven(float change);
	float getChangeGiven();

	//Getters and setters
	void setName(string newname);
	string getName();
	void setNumber(string newnumber);
	string getNumber();
};
#endif