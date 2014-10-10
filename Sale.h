// Program:		Cash Register
// Name:		Michael Americo Pace
// Class:		COMP 2710
// Date: 		November 29, 2012
// Email: 		map0009@auburn.edu
//
// Description:	Class definition for class Sale.
#ifndef SALE_H
#define SALE_H
#define TAX 0.07;
#define DISCOUNTPRICE 0.10;
#define SHIPPING 3.50;
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
using namespace std;
enum sale_type{REGULAR, DISCOUNT, MAILORDER};
class Sale
{
public:
	Sale();

	vector<string> descriptions;	// List of item descriptions
	vector<float> prices;			// List of item prices
	int type;						// Member variable for sales type
	float tax;						// Member variable for tax
	float subtotal;					// Member variable for subtotal
	float totalamount;				// Member variable for total amount
	string receipt;					// Stores all above information of sale, including pa

	virtual void process_payment();
	void print_sale();
	virtual void print_payment();
	void formatReceipt();

	// Getters and setters
	float calculateSubtotal(vector<float> prices);
	void setSubtotal(float newsub);
	float getSubtotal();
	float calculateDiscount();
	float calculateShipping(int num_items);
	float calculateTax();
	void setTax(float newtax);
	float getTotal();
	void setTotal(float newtotal);
	void getDescriptions();
	void setDescriptions(vector<string> inventory);
	void getPrices();
	void setPrices(vector<float> prices);
	int getType();
	void setType(int salestype);
};
#endif