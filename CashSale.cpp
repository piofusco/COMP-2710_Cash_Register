// Program:		Cash Register
// Name:		Michael Americo Pace
// Class:		COMP 2710
// Date: 		November 29, 2012
// Email: 		map0009@auburn.edu
//
// Description:	This class is the implementation of a cash sale. It is a child of Sale.
//				Takes in amount of cash to make payment and calculates proper change from
//				total amount of sale.
// Compile instructions: 	g++ CashSale.cpp -o lab4
#include "CashSale.h"

// Function:	Parameterless constructor for CashSale
// Input:		vector<string> inventory, vector<float> pricelist
// Description:	Creates a cash sale. Copies inventory to descriptions and pricelist to
//				prices. Initializes total amount and taxes to zero. Sets type to the back of
//				pricelist before popping it. Calculate subtotal.
CashSale::CashSale(vector<string> & inventory, vector<float> & pricelist) 
{
	descriptions.swap(inventory);
	prices.swap(pricelist);
	totalamount = 0;
	tax = 0;
	setType(prices.back());
	prices.pop_back();
	calculateSubtotal(prices);
}

// Function:	process_payment
// Input:		cashreceived
// Description:	Virtual function from ancestor Sale specific for CashSale. User inputs
//				amount of cash given. Calculates change based on type of sale. This
//				information is added to receipt.
void CashSale::process_payment()
{
	//user input amount of cash and depending on type of sale determine change
	cout << "Amount received: $";
	cin >> cashreceived;
	switch (getType())
	{
		case REGULAR:	calculateTax();
						setChangeGiven(cashreceived - getTotal()); 
						cout << endl << "Change: $" << getChangeGiven() << endl;
						break;
		case DISCOUNT:	calculateDiscount();
						calculateTax();
						setChangeGiven(cashreceived - getTotal()); 
						cout << endl << "Change: $" << getChangeGiven() << endl;
						break;
		case MAILORDER:	calculateShipping(prices.size());
						calculateTax();
						setChangeGiven(cashreceived - getTotal()); 
						cout << endl << "Change: $" << getChangeGiven() << endl;
						break;
	}	
	formatReceipt();
}

// Function:	print_sale
// Description:	This function exists strictly to obey directions. Calls print_payment.
void CashSale::print_sale()
{
	print_payment();
}

// Function:	print_payment
// Description:	Adds CASH notation, amount received and change given to the end of receipt. Prints out receipt.
void CashSale::print_payment()
{
	string tempReceipt = receipt;
	ostringstream oss(ostringstream::out);
	oss.precision(2);
	oss << "\nCASH";
	oss << "\nAmount received:\t$ " << fixed << getCashReceived();
	oss << "\nChange:\t$ " << fixed << getChangeGiven(); 
	tempReceipt += oss.str(); 
	cout << tempReceipt;
}

// Function:	setCashReceived
// Input:		float cashin
// Description:	Sets cash received to float cashin.
void CashSale::setCashReceived(float cashin)
{
	cashreceived = cashin;
}

// Function:	getCashReceived
// Output:		float cashreceived
// Description:	Returns cashreceived from sale.
float CashSale::getCashReceived()
{
	return cashreceived;
}

// Function:	setChangeGiven
// Input:		float change
// Description:	Sets changegiven to float change.
void CashSale::setChangeGiven(float change)
{
	changegiven = change;
}

// Function:	getChangeGiven
// Output:		float
// Description:	Returns changegiven from sale.
float CashSale::getChangeGiven()
{
	return changegiven;
}