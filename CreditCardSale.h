// Program:		Cash Register
// Name:		Michael Americo Pace
// Class:		COMP 2710
// Date: 		November 29, 2012
// Email: 		map0009@auburn.edu
//
// Description:	Class definition for class CreditCardSale.
#ifndef CREDITCARDSALE_H
#define CREDITCARDSALE_H
#include "Sale.h"
class CreditCardSale : public Sale
{
public:
	CreditCardSale(vector<string> inventory, vector<float> pricelist);

	string name;		// Member variable for name on card
	string expiration;	// Member variable for expiration date on card
	string cardnumber;	// Member variable for card number

	void process_payment();
	void print_sale();
	void print_payment();

	// Getter and setters
	void setName(string);
	string getName();
	void setExpiration(string);
	string getExpiration();
	void setCardNumber(string);
	string getCardNumber();	
};
#endif