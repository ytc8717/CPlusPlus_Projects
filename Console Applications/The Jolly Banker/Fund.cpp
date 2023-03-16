#include "Fund.h"
#include <iostream>
#include <ostream>

using namespace std;

Fund::Fund()
{
	balance = 0;
}

bool Fund::addAmount(int amountIn)
{
	balance += amountIn;
	return true;
}

bool Fund::subtractAmount(int amountOut)
{
	balance -= amountOut;
	return true;
}

bool Fund::balanceCheck(int amountOut)
{
	if (balance >= amountOut)
	{
		return true;
	}
	return false;
}

bool Fund::recordTransaction(Transactions trans)
{
	history.push_back(trans);
	return true;
}

void Fund::printHistoryOfFund()
{
	for (int i = 0; i < history.size(); i++)
	{
		cout << history[i];
	}
}

void Fund::printHistory()
{
	if (history.size() == 0)
	{
		return;
	}
	else
	{
		cout << fundName << ": $" << balance << endl;
		for (int i = 0; i < history.size(); i++)
		{
			cout << history[i];
		}
	}
}

void Fund::setName(string name)
{
	this->fundName = name;
}

int Fund::getBalance() const
{
	return balance;
}

string Fund::getName() const
{
	return fundName;
}
