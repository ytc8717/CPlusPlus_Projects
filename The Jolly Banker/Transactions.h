#pragma once
//#include <string>
#include <iostream>

using namespace std;

class Transactions
{

public:
	// constructor
	Transactions();
	//~Transactions();

	// constructors identify types of transaction
	Transactions(char type, string firstName, string lastName, int accountID);
	Transactions(char type, int accountID, int fundID, int amount);
	Transactions(char type, int accountID, int fundID, int amount, int transferAccountID, int transferFundID);
	Transactions(char type, int accountID);
	Transactions(char type, int accountID, int fundID);

	//These Construtors create a transaction that failed to process
	Transactions(char type, int accountID, int fundID, int amount, int transferAccountID, int transferFundID, string failString);
	Transactions(char type, int accountID, int fundID, string fail, int amount);

	// check if a transaction is fail 
	bool isFailed();

	// get the transaction type "O", "D", "W", "T", "H"
	char getTransactionType() const;

	// getter and setter
	string getFirstName() const;
	string getLastName() const;
	int getAccountID() const;
	int getFundID() const;
	int getTransferAccountID() const;
	int getTransferFundID() const;
	int getAmount() const;

	// operator overload
	friend ostream& operator<<(ostream& out, const Transactions& trans);

private:
	char transactionType = 'a';
	string firstName = "";
	string lastName = "";
	string fail = "";
	int accountID = 0, fundID = 0, transferAccountID = 0, transferFundID = 0, amount = 0;
};
