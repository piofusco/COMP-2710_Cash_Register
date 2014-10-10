// Program:		Cash Register
// Name:		Michael Americo Pace
// Class:		COMP 2710
// Date: 		November 29, 2012
// Email: 		map0009@auburn.edu
//
// Description:	This class is the implementation of a sale. It is the ancestor class to CashSale,
//				CheckSale and CreditCardSale. Sale has the ability to calculate a subtotal, a discount, taxes and shipping.
// Compile instructions: 	g++ Sale.cpp -o lab4
#include "Sale.h"

// Function:	parameterless constructor for Sales
Sale::Sale() 
{
	subtotal = 0;
	totalamount = 0;
	tax = 0;
	type = NULL;
	receipt = "";					
}

// Function:	process_payment
// Description:	Virtual function to be defined by children of Sales
void Sale::process_payment() {}

// Function:	print_sale
// Description:	Class to be redefined by child classes.
void Sale::print_sale()	{print_payment();}

// Function:	print_payment
// Description: Virtual function to be defined by children of Sales
void Sale::print_payment() {}

// Function:	formartReceipt
// Description:	Depending on type of sale, will format initial parts of receipt. This includes subtotals, taxes,
//				discounts, shipping and total amounts. All information is written to string receipt.
void Sale::formatReceipt()
{
	ostringstream oss(ostringstream::out);
	int N = descriptions.size();
	oss.precision(2);
	for(int i = 0; i < N ;i++)
	{
		oss << "\n" << i + 1 << ". " << descriptions.at(i) << "\t$ " << fixed << prices.at(i);
	}  
	string test = oss.str();
	oss << "\n   Sub-Total:\t$ " << fixed << getSubtotal();
	switch (getType())	
	{
		case REGULAR:
			oss << "\n   Tax:\t$ " << fixed << calculateTax();
			oss << "\n   Total amount:\t$ " << fixed << getTotal();
	  		break;
		case DISCOUNT:
			oss << "\n   Discount:\t$ " << calculateDiscount();
			oss << "\n   Sub-Total:\t$ " << getSubtotal();
			oss << "\n   Tax:\t$ " << calculateTax();		
			oss << "\n   Total amount:\t$ " << getTotal();
			break; 
		case MAILORDER:
			oss << "\n   Shipping and handling:\t$ " << calculateShipping(prices.size());
			oss << "\n   Sub-Total:\t$ " << getSubtotal();
			oss << "\n   Tax:\t$ " << calculateTax();
			oss << "\n   Total amount:\t$ " << getTotal();
			break;
	} 
	receipt = oss.str();  
}

// Function:	calculateSubtotal
// Input:		vector<float> pricelist
// Output:		subtotal
// Description:	Takes list of prices of every item in sale and sums them to return subtotal.
float Sale::calculateSubtotal(vector<float> pricelist)
{
	float new_subtotal = 0;
	vector<float>::iterator i;
	for(i = pricelist.begin(); i < pricelist.end(); i++)
	{
		new_subtotal += (*i);
	}
	setSubtotal(new_subtotal);
	return subtotal;
}

// Function:	setSubtotal
// Input:		float newsub
// Description:	Sets subtotal of sale to newsub.
void Sale::setSubtotal(float newsub)
{
	subtotal = newsub;
}

// Function:	getSubtotal
// Output:		float subtotal
// Description:	Returns float subtotal
float Sale::getSubtotal()
{
	return subtotal;
}

// Function:	calculateDiscount
// Input:		float sub
// Output:		float discount
// Description:	Calculates a rounded discount from subtotal.
float Sale::calculateDiscount()
{
	float discount = subtotal * DISCOUNTPRICE; 
	// Update new subtotal
	subtotal = subtotal - discount;
	return floorf(discount * 100 + 0.5) / 100;
}

// Function:	calculateShipping
// Input:		int num_items
// Output:		float shipping
// Description:	Multiplies the number of items in a sale by 3.50. Rounds this number to 2 decimal places
float Sale::calculateShipping(int num_items)
{
	float sandh = num_items * SHIPPING; 
	// Update new subtotal
	subtotal = sandh + subtotal;
	return floorf(sandh * 100 + 0.5) / 100;
}

// Function:	calculateTax
// Input:		float sub
// Output:		float tax
// Description:	Takes subtotal and calculates a round 7% tax.
float Sale::calculateTax()
{
	float tax = subtotal * TAX;
	// Update new total
	totalamount = tax + subtotal; 
	return floorf(tax * 100 + 0.5) / 100;
}

// Function:	setTax
// Input:		float newtax
// Description:	Sets tax member variable to float new tax.
void Sale::setTax(float newtax)
{
	tax = newtax;
}

// Function:	getTotal
// Output:		float total
// Description:	Returns total amount of sale.
float Sale::getTotal()
{
	return totalamount;
}

// Function:	setTotal
// Input:		float newtotal
// Description:	Sets total to float newtotal.
void Sale::setTotal(float newtotal)
{
	totalamount = newtotal;
}

// Function:	getDescription
// Output:		Prints out each item in sale.
// Description:	Iterates from vector "items" and prints out each to a new line.
void Sale::getDescriptions()
{		
	vector<string>::iterator s;
	for(s = descriptions.begin(); s < descriptions.end(); s++)
	{
		cout << (*s) << endl;
	}
	cout << endl << "END OF ITEMS" << endl;
}

// Function:	setDescrptions
// Input:		vector<string> inventory
// Description:	Sets values in vector "items" to values in vector "inventory"
void Sale::setDescriptions(vector<string> inventory)
{
	descriptions.swap(inventory);
}

// Function:	getPrices
// Output:		Prints out each prices of item in sale.
// Description:	Iterates from vector "prices" and prints out each on to a new line.
void Sale::getPrices()
{
	vector<float>::iterator s;
	for(s = prices.begin(); s < prices.end(); s++)
	{
		cout << (*s) << endl;
	}
	cout << endl << "END OF ITEMS" << endl;
}

// Function:	setPrices
// Input:		vector<float> prices
// Description: Iterates through vector "newprices" and updates each value in vector "prices".
void Sale::setPrices(vector<float> newprices)
{
	prices.swap(newprices);
}

// Function:	getType
// Output:		int type
// Description:	Returns type of sale.
int Sale::getType()
{
	return type;
}

// Function:	setType
// Input:		int salestype
// Description:	Sets type of sale to int salestype.
void Sale::setType(int salestype)
{
	type = salestype;
}