#include "Transactions.h"



Transactions::Transactions(char type, string firstName, string lastName, int accountID)
{
	this->transactionType = type;
	this->firstName = firstName;
	this->lastName = lastName;
	this->accountID = accountID;
}

Transactions::Transactions(char type, int accountID, int fundID, int amount)
{
	this->transactionType = type;
	this->accountID = accountID;
	this->fundID = fundID;
	this->amount = amount;
}

Transactions::Transactions(char type, int accountID, int fundID, int amount, int transferAccountID, int transferFundID)
{
	this->transactionType = type;
	this->accountID = accountID;
	this->fundID = fundID;
	this->amount = amount;
	this->transferAccountID = transferAccountID;
	this->transferFundID = transferFundID;
}

Transactions::Transactions(char type, int accountID)
{
	this->transactionType = type;
	this->accountID = accountID;
}

Transactions::Transactions(char type, int accountID, int fundID)
{
	this->transactionType = type;
	this->accountID = accountID;
	this->fundID = fundID;
}

Transactions::Transactions(char type, int accountID, int fundID, int amount, int transferAccountID, int transferFundID, string failString)
{
	this->transactionType = type;
	this->accountID = accountID;
	this->fundID = fundID;
	this->amount = amount;
	this->transferAccountID = transferAccountID;
	this->transferFundID = transferFundID;
}

Transactions::Transactions(char type, int accountID, int fundID, string fail, int amount)
{
	this->transactionType = type;
	this->accountID = accountID;
	this->fundID = fundID;
	this->amount = amount;
	this->fail = fail;
}

bool Transactions::isFailed()
{
	if (fail.empty())
	{
		return true;
	}
	return false;
}

char Transactions::getTransactionType() const
{
	return transactionType;
}

string Transactions::getFirstName() const
{
	return firstName;
}

string Transactions::getLastName() const
{
	return lastName;
}

int Transactions::getAccountID() const
{
	return accountID;
}

int Transactions::getFundID() const
{
	return fundID;
}

int Transactions::getTransferAccountID() const
{
	return transferAccountID;
}

int Transactions::getTransferFundID() const
{
	return transferFundID;
}

int Transactions::getAmount() const
{
	return amount;
}

ostream& operator<<(ostream& out, const Transactions& trans)
{
	if (trans.fail.empty())
	{
		if (trans.getTransactionType() == 'D' || trans.getTransactionType() == 'd' || trans.getTransactionType() == 'W' || trans.getTransactionType() == 'w')
		{
			out << " " << trans.getTransactionType() << " " << trans.getAccountID() << trans.getFundID() << " " << trans.getAmount();
		}
		else if (trans.getTransactionType() == 'T' || trans.getTransactionType() == 't')
		{
			out << " " << trans.getTransactionType() << " " << trans.getAccountID() << trans.getFundID() << " " << trans.getAmount() << " " << trans.getTransferAccountID() << trans.getTransferFundID();
		}
		else
		{

		}
	}
	else
	{
		if (trans.getTransactionType() == 'D' || trans.getTransactionType() == 'd' || trans.getTransactionType() == 'W' || trans.getTransactionType() == 'w')
		{
			out << " " << trans.getTransactionType() << " " << trans.getAccountID() << trans.getFundID() << " " << trans.getAmount() << " (FAILED)";
		}
		else if (trans.getTransactionType() == 'T' || trans.getTransactionType() == 't')
		{
			out << " " << trans.getTransactionType() << " " << trans.getAccountID() << trans.getFundID() << " " << trans.getAmount() << " " << trans.getTransferAccountID() << trans.getTransferFundID() << "(FAILED)";
		}
		else
		{

		}

	}
	return out << endl;
}
