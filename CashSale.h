// Program:		Cash Register
// Name:		Michael Americo Pace
// Class:		COMP 2710
// Date: 		November 29, 2012
// Email: 		map0009@auburn.edu
//
// Description:	Class definition for class CashSale.
#ifndef CASHSALE_H
#define CASHSALE_H
#include "Sale.h"
class CashSale : public Sale
{
public:
	CashSale(vector<string> & inventory, vector<float> & pricelist);

	float cashreceived;		// Member variable for amount of cash received for payment
	float changegiven;		// Member variable for amount of change given

	void process_payment();
	void print_sale();
	void print_payment();
	void setCashReceived(float cashin);
	float getCashReceived();
	void setChangeGiven(float change);
	float getChangeGiven();
};
#endif