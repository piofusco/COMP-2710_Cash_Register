// Program:		Cash Register
// Name:		Michael Americo Pace
// Class:		COMP 2710
// Date: 		November 29, 2012
// Email: 		map0009@auburn.edu
//
// Description:	Class definition for class Register.
#ifndef REGISTER_H
#define REGISTER_H
#define TAX 0.07;
#define DISCOUNTPRICE 0.10;
#define SHIPPING 3.50;
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "CashSale.h"
#include "CheckSale.h"
#include "CreditCardSale.h"
using namespace std;

class Register
{
public:
	Register();

	// Itemizing - Function (1)
	void beginItemize();
	void addItems();
	void enterItemName();
	void enterPrice();
	float calculateTempSubtotal(vector<float> prices);
	char choseOption();
	
	// Function (2)
	char choseSale();
	float calculateTempDiscount();
	float calculateTempShipping();
	void handleSales(char selection);

	// Function (3)
	float calculateTempTax();

	// Function (4)
	char chosePayment();
	void handlePayment(char pick);
	void newCashSale(char type);
	void newCheckSale(char type);
	void newCreditCardSale(char type);

	// Function (5)	
	void printReceipts();

	vector<Sale *> saleslist;		// Holds every sale in register
	int numberOfSales;				// Total number of sales

	vector<string> itemNames;		// Temporary storage for each item in a sale
	int numberOfItems;				// Temproray storage of number of items in sale
	vector<float> itemPrices;		// Temporary storage of prices of items in a sale
	float tempSubtotal;				// Temporary subtotal of sale
};
#endif