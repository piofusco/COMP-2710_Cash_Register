// Program:		Cash Register
// Name:		Michael Americo Pace
// Class:		COMP 2710
// Date: 		November 29, 2012
// Email: 		map0009@auburn.edu
//
// Description:	This class is the implementation of a real cash register. This class has the ability to
//				create new sales of three types (regular, discount or mail-order) and can take payments in
//				the form of (cash, check or credit card).
// Compile instructions: 	g++ Register.cpp -o lab4
#include "Register.h"

	// Function: parameterless construction for Register
	Register::Register()
	{
		numberOfSales = 0;
		numberOfItems = 0;
		tempSubtotal = 0;
	}

	// Function:	beginItemize
	// Output:		prompts user for payment or sales AND type of sales
	// Description: Greets user. Handles users choice of payment/sales. 
	void Register::beginItemize()
	{
		cout << "\n\n\t***********************************************************************************" << endl;		
		cout << "\t|				Welcome to Great Buy!		  	          |" << endl;
		cout << "\t***********************************************************************************" << endl;
		numberOfSales++;
		cout << "Enter payment(p) or print sales(s): ";
		switch (choseOption())
		{	// Enter payment
			case 'p':	addItems();
						cout << "Enter type of Sale: regular(r), discount(d) or mail-order(m): ";
						handleSales(choseSale());
						break;
			// Print sales
			case 's':	printReceipts();
						break;
		}
	}

	// Function:	printReceipts
	// Description:	Prints every the receipt of every sale in vector saleslist.
	void Register::printReceipts()
	{
		vector<Sale*>::iterator s;
		int i = 0;
		for(s = saleslist.begin(); s < saleslist.end(); s++,i++)
		{
			cout << endl << "Sales #" << (i + 1) << ":" << endl;
			(*s)->print_sale();
		}
		cout << endl << "END" << endl;
	}

	// Function:	handleSales
	// Input:		char selection
	// Description:	Handles different types of sales options. Takes char selection and directs register to prompt
	//				for desired type of sale. Stores type of sale as last item in vector "items".
	void Register::handleSales(char selection)
	{
		switch (selection)
		{	// Regular
			case 'r':	cout << "Tax: $" << calculateTempTax() << endl << endl;
						cout << "Total amount: $" << tempSubtotal << endl << endl;
						itemPrices.push_back(REGULAR);
						break;
			// Discount
			case 'd':	cout << "Discount: $" << calculateTempDiscount() << endl << endl;
						cout << "Subtotal: $" << tempSubtotal << endl << endl;
						cout << "Tax: $" << calculateTempTax() << endl << endl;
						cout << "Total amount: $" << tempSubtotal << endl << endl;
						itemPrices.push_back(DISCOUNT);			
						break;
			// Mail-order
			case 'm':	cout << "Shipping and handling: $" << calculateTempShipping() << endl << endl;
						cout << "Subtotal: $" << tempSubtotal << endl << endl;
						cout << "Tax: $" << calculateTempTax() << endl << endl;
						cout << "Total amount: $" << tempSubtotal << endl << endl;
						itemPrices.push_back(MAILORDER);
						break;
		}
		cout << "Enter type of payment, cash(c), check(k) or credit card (d): ";
		handlePayment(chosePayment());
	}

	// Function:	handlePayment
	// Input:		char pick
	// Description: Handles different types of payment options. Takes char pick and directs register to prompt
	//				for desired type of payment.
	void Register::handlePayment(char pick)
	{
		switch	(pick)
		{	// Cash
			case 'c':	newCashSale(pick);
						break;
			// Check
			case 'k':	newCheckSale(pick);
						break;
			// Credit Card
			case 'd':	newCreditCardSale(pick);
						break;
		}
	}

	// Function: newSale
	// Input: char type
	// Description: Creates a new CashSale. Calls process payment and adds to vector saleslist.
	void Register::newCashSale(char type)
	{
		CashSale *temp = new CashSale(itemNames, itemPrices);
		temp->process_payment();
		saleslist.push_back(temp);
	}

	// Function: newSale
	// Input: char type
	// Description: Creates a new CheckSale. Calls process payment and adds to vector saleslist.
	void Register::newCheckSale(char type)
	{
		CheckSale *temp = new CheckSale(itemNames, itemPrices);
		temp->process_payment();
		saleslist.push_back(temp);
	}

	// Function: newSale
	// Input: char type
	// Description: Creates a new CreditCardSale. Calls process payment and adds to vector saleslist.
	void Register::newCreditCardSale(char type)
	{
		CreditCardSale *temp = new CreditCardSale(itemNames, itemPrices);
		temp->process_payment();	
		saleslist.push_back(temp);
	}

	// Function:	addItems
	// Input:		item names and prices
	// Output:		tempSubtotal
	// Description:	Prompts user to continually itemize until a * is encountered. Will then cease prompting for item names
	//				and print out a calculated sub-total of all items.
	void Register::addItems()
	{
		// Set numberOfItems to zero - new Sale object has begun
		numberOfItems = 0;
		// Clear both temporary vectors - new Sale object has begun
		itemNames.clear();
		itemPrices.clear();
		string itemName = "";
		float itemPrice = 0;
		while(true)
		{
			cout << "Enter item: ";
			while( getchar() != '\n')
			{
				continue;
			}
			getline(cin, itemName, '\n');
			if(itemName == "*")
			{
				// Stop itemization
				break;
			}
			numberOfItems++;
			cout << "Enter amount: $";
			itemPrice = 0;
			cin >> itemPrice;
			itemNames.push_back(itemName);
			itemPrices.push_back(itemPrice);	
		}
		tempSubtotal = calculateTempSubtotal(itemPrices);
		// Round numb to two decimal places
		cout.precision(2);
		cout << "Sub-total: $" << fixed << tempSubtotal << endl;
	}

	// Function:	calculateTempSubTotal
	// Output:		float subtotal
	// Description: Iterates through the prices of every item in current sale and sums each to generate a subtotal.
	float Register::calculateTempSubtotal(vector<float> prices)
	{
		float sub = 0;
		for(int i = 0; i < numberOfItems; i++)
		{
			sub+= prices.at(i);
		}
		return sub;
	}

	// Function:	choseOption
	// Description: Determines whether user response is valid: 's' or 'p'. Used for option selection.
	char Register::choseOption()
	{
		string option;
		while(true)
		{
			option = "";
			cin >> option;
			if(option.length() >= 1 && option != "s" && option != "p")
			{
				cout << "Invalid response. Please type only a single character: 's' or 'p'." << endl;
				cout << "Enter reponse: ";
			}
			else if(option == "s" || option == "p")
			{
				return option.at(0);
			}
		}
	}

	// Function:	choseSale	
	// Description: Determines whether user response is valid: 'r' 'd' or 'm'. Used for Sale selection.
	char Register::choseSale()
	{
		string sale;
		while(true)
		{
			sale = "";
			cin >> sale;
			if(sale.length() >= 1 && sale != "r" && sale != "d" && sale != "m")
			{
				cout << "Invalid response. Please type only a single character: 'r' 'd' or 'm'." << endl;
				cout << "Enter reponse: ";
			}
			else if(sale == "r" || sale == "d" || sale == "m")
			{
				return sale.at(0);
			}
		}
	}

	// Function:	calculateDiscount
	// Output:		float discount
	// Description: Calculates discount from subtotal: subtotal * .10. Subtracts this from subtotal and rounds
	//				to the nearest cents. Also, updates tempSubtotal to subtract this discount.
	float Register::calculateTempDiscount()
	{
		float discount = tempSubtotal * DISCOUNTPRICE; 
		// Update new subtotal
		tempSubtotal = tempSubtotal - (floorf(discount * 100 + 0.5) / (100));
		return floorf(discount * 100 + 0.5) / 100;
	}

	// Function:	calculateTempTax
	// Output:		float tax
	// Description:	Calculates the tax from subtotal: subtotal * .07. Rounds to nearest cents. Also, updates 
	//				tempSubtotal to contain this tax.
	float Register::calculateTempTax()
	{
		float tax = tempSubtotal * TAX; 
		tempSubtotal = tempSubtotal + (floorf(tax * 100 + 0.5) / (100));
		return floorf(tax * 100 + 0.5) / 100;
	}

	// Function:	calculateTempShipping
	// Output:		float shipping
	// Description:	Calculates the price for shipping: number of items * 3.50. Also, updates tempSubtotal to 
	//				contain this cost
	float Register::calculateTempShipping()
	{
		float sandh = numberOfItems * SHIPPING;
		// Update tempSubtotal
		tempSubtotal = tempSubtotal + floorf((sandh * 100 + 0.5) / (100)); 
		return floorf(sandh * 100 + 0.5) / 100;
	}

	// Function:	chosePayment
	// Description: Determines whether user response is valid: 'c' 'k' or 'd'. Used for payment selection.
	char Register::chosePayment()
	{
		string payment;
		while(true)
		{
			payment = "";
			cin >> payment;
			if(payment.length() >= 1 && payment != "c" && payment != "k" && payment != "d")
			{
				cout << "Invalid response. Please type only a single character: 'c' 'k' or 'd'." << endl;
				cout << "Enter reponse: ";
			}
			else if(payment == "c" || payment == "k" || payment == "d")
			{
				return payment.at(0);
			}
		}
	}