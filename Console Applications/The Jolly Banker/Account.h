#pragma once
#include "Fund.h"
#include "Transactions.h"
#include <vector>
#include <iostream>

using namespace std;

// set constants
const int MONEY_MARKET = 0;
const int PRIME_MONEY_MARKET = 1;
const int LONG_TERM_BOND = 2;
const int SHORT_TERM_BOND = 3;
const int FUND_MAX = 10;

class Account
{
	// operator overload
	friend ostream& operator<<(ostream& out, Account& account);
public:
	// constructors
	Account();
	Account(string firstName, string lastName, int accountID);
	//~Account();

	// functions
	void Deposit(int fundID, int amount);
	bool Withdraw(int fundID, int amount, Transactions trans);

	// record transaction
	void RecordTrans(Transactions trans, int fundID);

	// function deal with similar accounts
	void WidthFromSimilarAcct(int primaryFund, int secondaryFund, int amount);

	// display history
	void PrintHistory();
	void PrintFundHistory(int fundID);

	// display error msg
	void error(int amount, string firstName, string lastName, int fundID);

	// getter and setter
	int getAccountID() const;
	int getBalance(int fundID)const;
	string getFundName(int fundID);
	string getFirstName() const;
	string getLastName()const;
	void setFundID(int fundID);

private:
	string firstName, lastName;
	int accountID;
	int fundId;
	// array of 10 funds
	Fund arrayFund[FUND_MAX];
};

