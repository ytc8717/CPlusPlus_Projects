#include "Account.h"

Account::Account(string firstName, string lastName, int accountID)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->accountID = accountID;
	string fundNames[] = { "Money Market", "Prime Money Market","Long-Term Bond", "Short-Term Bond",
		"500 Index Fund", "Capital Value Fund","Growth Equity Fund", "Growth Index Fund","Value Fund", "Value Stock Index" };
	for (int i = 0; i < 10; i++)
	{
		arrayFund[i].setName(fundNames[i]);
	}
}

void Account::Deposit(int fundID, int amount)
{
	arrayFund[fundID].addAmount(amount);
}

bool Account::Withdraw(int fundID, int amount, Transactions trans)
{
	if (fundID == MONEY_MARKET || fundID == PRIME_MONEY_MARKET || fundID == LONG_TERM_BOND || fundID == SHORT_TERM_BOND)
	{
		if (fundID == MONEY_MARKET || fundID == PRIME_MONEY_MARKET)
		{
			if (arrayFund[fundID].balanceCheck(amount))
			{
				arrayFund[fundID].subtractAmount(amount);
				arrayFund[fundID].recordTransaction(trans);
				return true;
			}
			else if (((arrayFund[MONEY_MARKET].getBalance() + arrayFund[PRIME_MONEY_MARKET].getBalance()) >= amount))
			{
				if (fundID == MONEY_MARKET)
				{
					WidthFromSimilarAcct(MONEY_MARKET, PRIME_MONEY_MARKET, amount);
				}
				else
				{
					WidthFromSimilarAcct(PRIME_MONEY_MARKET, MONEY_MARKET, amount);
				}
			}
			else
			{
				error(amount, getFirstName(), getLastName(), fundID);
				if (fundID == MONEY_MARKET)
				{
					WidthFromSimilarAcct(MONEY_MARKET, PRIME_MONEY_MARKET, amount);
				}
				else
				{
					WidthFromSimilarAcct(PRIME_MONEY_MARKET, MONEY_MARKET, amount);
				}
				return false;
			}
		}
		else if (fundID == LONG_TERM_BOND || fundID == SHORT_TERM_BOND)
		{
			if (arrayFund[fundID].balanceCheck(amount))
			{
				arrayFund[fundID].subtractAmount(amount);
				arrayFund[fundID].recordTransaction(trans);
				return true;
			}
			else if (((arrayFund[LONG_TERM_BOND].getBalance() + arrayFund[SHORT_TERM_BOND].getBalance()) >= amount))
			{
				if (fundID == LONG_TERM_BOND)
				{
					WidthFromSimilarAcct(LONG_TERM_BOND, SHORT_TERM_BOND, amount);
				}
				else
				{
					WidthFromSimilarAcct(SHORT_TERM_BOND, LONG_TERM_BOND, amount);
				}
			}
			else
			{
				error(amount, getFirstName(), getLastName(), fundID);
				if (fundID == LONG_TERM_BOND)
				{
					WidthFromSimilarAcct(LONG_TERM_BOND, SHORT_TERM_BOND, amount);
				}
				else
				{
					WidthFromSimilarAcct(SHORT_TERM_BOND, LONG_TERM_BOND, amount);
				}
				return false;
			}
		}
	}
	else
	{
		if (arrayFund[fundID].balanceCheck(amount))
		{
			arrayFund[fundID].subtractAmount(amount);
			arrayFund[fundID].recordTransaction(trans);
			return true;
		}
		else
		{
			error(amount, getFirstName(), getLastName(), fundID);
			return false;
		}
	}
	return false;
}

void Account::RecordTrans(Transactions trans, int fundID)
{
	arrayFund[fundID].recordTransaction(trans);
}

void Account::WidthFromSimilarAcct(int primaryFund, int secondaryFund, int amount)
{
	// check if overall two similar accounts has enough fund to withdraw
	if (((arrayFund[primaryFund].getBalance() + arrayFund[secondaryFund].getBalance()) >= amount))
	{
		int amtAvailable = arrayFund[primaryFund].getBalance();
		arrayFund[primaryFund].subtractAmount(amtAvailable);
		Transactions addHistory('W', getAccountID(), primaryFund, amtAvailable);
		arrayFund[primaryFund].recordTransaction(addHistory);
		amount = amount - amtAvailable;
		arrayFund[secondaryFund].subtractAmount(amount);
		Transactions addHistory2('W', getAccountID(), secondaryFund, amount);
		arrayFund[secondaryFund].recordTransaction(addHistory2);
	}
	else
	{
		int amtAvailable = arrayFund[primaryFund].getBalance();
		if (amtAvailable > amount)
		{
			arrayFund[primaryFund].subtractAmount(amtAvailable);
			Transactions addToHistory('W', getAccountID(), primaryFund, amtAvailable);
			arrayFund[primaryFund].recordTransaction(addToHistory);
			amount = amount - amtAvailable;
		}

		if (arrayFund[secondaryFund].balanceCheck(amount))
		{
			arrayFund[secondaryFund].subtractAmount(amount);
			Transactions addToHistory('W', getAccountID(), secondaryFund, amount);
			arrayFund[secondaryFund].recordTransaction(addToHistory);
		}
		else
		{
			cerr << "ERROR: Not Enought Funds to withdraw " << amount << " " << "from " << getFirstName() << " " << getLastName() << " " << getFundName(secondaryFund) << endl;
			Transactions addToHistory('W', getAccountID(), secondaryFund, "Failed", amount);
			arrayFund[secondaryFund].recordTransaction(addToHistory);
		}
	}
}

void Account::PrintHistory()
{
	cout << "Transaction History for " << firstName << " " << lastName << " " << "By Fund." << endl;
	for (int i = 0; i < 10; i++)
	{
		arrayFund[i].printHistory();
	}
}

void Account::PrintFundHistory(int fundID)
{
	cout << "Transaction History for " << firstName << " " << lastName << " " << getFundName(fundID) << " $" << getBalance(fundID) << endl;
	arrayFund[fundID].printHistoryOfFund();
}

void Account::error(int amount, string firstName, string lastName, int fundID)
{
	cerr << "ERROR: Not Enought Funds to withdraw " << amount << " " << "from " << firstName << " " << lastName << " " << getFundName(fundID) << endl;
	Transactions addHistory('W', getAccountID(), fundID, "Failed", amount);
	arrayFund[fundID].recordTransaction(addHistory);
}

int Account::getAccountID() const
{
	return accountID;
}

int Account::getBalance(int fundID) const
{
	return arrayFund[fundID].getBalance();
}

string Account::getFundName(int fundID)
{
	return arrayFund[fundID].getName();
}

string Account::getFirstName() const
{
	return firstName;
}

string Account::getLastName() const
{
	return lastName;
}

void Account::setFundID(int fundID)
{
	this->fundId = fundID;
}

ostream& operator<<(ostream& out, Account& account)
{
	out << account.getFirstName() << " " << account.getLastName() << " ID: " << account.getAccountID() << endl;
	for (int i = 0; i < 10; i++)
	{
		out << " " << account.getFundName(i) << " :$" << account.getBalance(i);
		out << endl;
	}

	return out;
}
