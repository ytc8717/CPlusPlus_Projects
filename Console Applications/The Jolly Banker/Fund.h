#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Transactions.h"
#include <ostream>

using namespace std;

class Fund
{
public:
	// constructor
	Fund();
	//~Fund();

	// functions
	bool addAmount(int amountIn);
	bool subtractAmount(int amountOut);
	bool balanceCheck(int amountOut);

	// record transactions
	bool recordTransaction(Transactions trans);

	// display history
	void printHistoryOfFund();
	void printHistory();

	// getter and setter
	void setName(string name);
	int getBalance() const;
	string getName() const;

private:
	string fundName;
	int balance = 0;
	// vector to store transaction history
	vector<Transactions> history;
};

