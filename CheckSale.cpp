// Program:		Cash Register
// Name:		Michael Americo Pace
// Class:		COMP 2710
// Date: 		November 29, 2012
// Email: 		map0009@auburn.edu
//
// Description:	This class is the implementation of a check sale. It is a child of Sale.
//				Takes name and drivers license associated with check.
// Compile instructions: 	g++ CheckSale.cpp -o lab4
#include "CheckSale.h"

// Function: Parameterless constructor for CheckSale
// Input:	vector<string> inventory, vector<float> pricelist
// Description:	Creates a check sale. Copies inventory to descriptions and pricelist to
//				prices. Initializes total amount and taxes to zero. Sets type to the back of
//				pricelist before popping it. Calculate subtotal.
CheckSale::CheckSale(vector<string> inventory, vector<float> pricelist) 
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
// Input:		string name, driverslicense
// Description:	Virtual function from ancestor Sale specific for CheckSale. User inputs
//				name on check and drivers license number. This information is added to receipt.
void CheckSale::process_payment()
{
	cout << endl << "Enter name on the check: ";
	while( getchar() != '\n' )
	{
		continue;
	}
	getline(cin, name, '\n');
	cout << endl << "Enter driver's license number: ";
	cin >> driverslicense;
	formatReceipt();
}

// Function:	print_sale
// Description:	This function exists strictly to obey directions. Calls print_payment.
void CheckSale::print_sale()
{	
	print_payment();
}

// Function:	print_payment
// Description:	Adds Check notation to receipt, this includes the name and drivers license number
//				associated with sale. Prints out receipt.
void CheckSale::print_payment()
{
	string tempReceipt = receipt;
	ostringstream oss(ostringstream::out);
	oss << "\nCHECK\t" << getName() << " " << getNumber(); 
	tempReceipt += oss.str(); 
	cout << tempReceipt;
}

// Function:	setName
// Input:		string name
// Description:	Sets name on check to newname.
void CheckSale::setName(string newname)
{	
	name = newname;
}

// Function:	getName
// Description:	Gets name on check
string CheckSale::getName()
{
	return name;
}

// Function:	setNumber
// Input:		string newnumber
// Description:	Sets number on check to newnumber.
void CheckSale::setNumber(string newnumber)
{
	driverslicense = newnumber;
}

// Function:	getNumber
// Description:	Returns number on drivers license.
string CheckSale::getNumber()
{
	return driverslicense;
}