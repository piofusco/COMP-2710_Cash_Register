// Program:		Cash Register
// Name:		Michael Americo Pace
// Class:		COMP 2710
// Date: 		November 29, 2012
// Email: 		map0009@auburn.edu
//
// Description:	This class is the implementation of a credit card sale. It is a child of Sale.
//				Takes name, expiration and card number associated with credit card.
// Compile instructions: 	g++ CredCardSale.cpp -o lab4
#include "CreditCardSale.h"

// Function: Constructor for CreditCardSale
// Input:	vector<string> inventory, vector<float> pricelist
// Description:	Creates a credit card sale. Copies inventory to descriptions and pricelist to
//				prices. Initializes total amount and taxes to zero. Sets type to the back of
//				pricelist before popping it. Calculate subtotal.
CreditCardSale::CreditCardSale(vector<string> inventory, vector<float> pricelist) 
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
// Input:		string name, cardnumber, expiration
// Description: Virtual function from ancestor Sale specific for CheckSale. User inputs
//				name, expiration date and number on credit card. This information is added to receipt.
void CreditCardSale::process_payment()
{
	// Enter name, credit card number and expiration date
	cout << "Enter name on the credit card: ";
	while( getchar() != '\n' )
	{
		continue;
	}
	getline(cin, name, '\n');
	cout << "Enter credit card number: ";
	cin >> cardnumber;
	cout << "Enter expiration date: ";
	cin >> expiration;     
	formatReceipt();   
}

// Function:	print_sale
// Description:	This function exists strictly to obey directions. Calls print_payment.
void CreditCardSale::print_sale()
{	
	print_payment();
}

// Function:	print_payment
// Description: Adds CreditCard notation to receipt, this includes the name, expiration date
//				and card number associated with purchase. Prints out receipt.
void CreditCardSale::print_payment()
{
	string tempReceipt = receipt;
	ostringstream oss(ostringstream::out);
	oss << "\nCREDIT CARD\t" << name << " " << cardnumber << " " << expiration;
    oss << "\n";
	tempReceipt += oss.str(); 
	cout << tempReceipt;
}

// Function:	setName
// Input:		string newname
// Description: Sets name on credit card to newname.
void CreditCardSale::setName(string newname)
{
	name = newname;
}

// Function:	getName
// Output:		string name
// Description:	Returns name on credit card.
string CreditCardSale::getName()
{
	return name;
}

// Function:	setExpiration
// Input:		string newdate
// Description:	Sets date on credit card to newdate.
void CreditCardSale::setExpiration(string newdate)
{
	expiration = newdate;
}

// Function:	getExpiratioin
// Output:		string expiration
// Description:	Returns date on credit card.
string CreditCardSale::getExpiration()
{
	return expiration;
}

// Function:	setCardNumber
// Input:		string newnumber
// Description:	Sets credit card number to newnumber.
void CreditCardSale::setCardNumber(string newnumber)
{
	cardnumber = newnumber;
}

// Function:	getCardNumber
// Output:		string cardnumber
// Description:	Returns number on credit card.
string CreditCardSale::getCardNumber()
{
	return cardnumber;
}