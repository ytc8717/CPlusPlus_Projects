#include "JollyBanker.h"

using namespace std;

JollyBanker::JollyBanker()
{
}

bool JollyBanker::ReadFile()
{
	ifstream in("BankTransIn.txt");
	string readLine;
	if (!in)
	{
		cout << "Cannot Open File!" << endl;
	}

	while (!in.eof())
	{
		getline(in, readLine);
		if (readLine.empty())
		{
			break;
		}
		istringstream parseLine(readLine);
		char transactionType;
		parseLine >> transactionType;

		if (transactionType == 'O' || transactionType == 'o')
		{
			string lastName, firstName;
			int accountID;
			parseLine >> firstName >> lastName >> accountID;
			Transactions addToQueue(transactionType, firstName, lastName, accountID);
			transactionList.push(addToQueue);

		}
		else if (transactionType == 'W' || transactionType == 'w' || transactionType == 'D' || transactionType == 'd')
		{
			int accountID, fundID, amount;
			parseLine >> accountID >> amount;
			fundID = accountID % 10;
			accountID = accountID / 10;
			Transactions addToQueue(transactionType, accountID, fundID, amount);
			transactionList.push(addToQueue);
		}
		else if (transactionType == 'T' || transactionType == 't')
		{
			int accountID, fundID, amount, trasnferAccountID, transferFundID;
			parseLine >> accountID >> amount >> trasnferAccountID;
			fundID = accountID % 10;
			accountID = accountID / 10;
			transferFundID = trasnferAccountID % 10;
			trasnferAccountID = trasnferAccountID / 10;
			Transactions addToQueue(transactionType, accountID, fundID, amount, trasnferAccountID, transferFundID);
			transactionList.push(addToQueue);
		}
		else if (transactionType == 'H' || transactionType == 'h')
		{
			int accountID;
			parseLine >> accountID;
			Transactions addToQueue(transactionType, accountID);
			transactionList.push(addToQueue);
		}
		else
		{
			cout << "ERROR!" << endl;
		}
	}
	return false;
}

bool JollyBanker::ProcessTransaction()
{
	while (!transactionList.empty())
	{
		Transactions trans = transactionList.front();

		if (trans.getTransactionType() == 'O' || trans.getTransactionType() == 'o')
		{
			Account* account = new Account(trans.getFirstName(), trans.getLastName(), trans.getAccountID());
			accountList.insert(account);
		}
		else if (trans.getTransactionType() == 'D' || trans.getTransactionType() == 'd')
		{
			int accountNumber = trans.getAccountID();
			int fundNumber = trans.getFundID();
			int amountToAdd = trans.getAmount();
			Account* account;
			if (accountList.Retrieve(accountNumber, account))
			{
				account->Deposit(fundNumber, amountToAdd);
				account->RecordTrans(trans, fundNumber);
			}

		}
		else if (trans.getTransactionType() == 'W' || trans.getTransactionType() == 'w')
		{
			int accountNumber = trans.getAccountID();
			int fundNumber = trans.getFundID();
			int amountToSubtract = trans.getAmount();
			Account* account;
			if (accountList.Retrieve(accountNumber, account))
			{
				account->Withdraw(fundNumber, amountToSubtract, trans);
			}

		}
		else if (trans.getTransactionType() == 'T' || trans.getTransactionType() == 't')
		{
			int accountNumber = trans.getAccountID();
			int transferAcctNum = trans.getTransferAccountID();
			int fundNumber = trans.getFundID();
			int transferFundNum = trans.getTransferFundID();
			int amountToSub = trans.getAmount();
			Account* to, * from;
			if (accountList.Retrieve(accountNumber, to) && accountList.Retrieve(transferAcctNum, from))
			{
				if (to->Withdraw(fundNumber, amountToSub, trans))
				{
					from->Deposit(transferFundNum, amountToSub);
					from->RecordTrans(trans, transferFundNum);
				}
				else
				{
					cerr << "ERROR: Not Enought Funds to Transer  " << amountToSub << " " << "from " << from->getAccountID() << fundNumber << " to " << to->getAccountID() << transferFundNum << endl;
					Transactions addToHistory('T', accountNumber, fundNumber, amountToSub, transferAcctNum, transferFundNum, "(Failed)");
					from->RecordTrans(addToHistory, transferFundNum);
				}
			}

		}
		else if (trans.getTransactionType() == 'H' || trans.getTransactionType() == 'h')
		{
			if (trans.getAccountID() >= 10000 && trans.getAccountID() <= 99999)
			{
				Account* account;
				int fundNumPrt = trans.getAccountID() % 10;
				int acctNumSearch = trans.getAccountID() / 10;
				if (accountList.Retrieve(acctNumSearch, account))
				{
					account->PrintFundHistory(fundNumPrt);
					cout << endl;
				}
			}
			else if (trans.getAccountID() >= 1000 && trans.getAccountID() <= 9999)
			{
				Account* account;
				int acctNumSearch = trans.getAccountID();
				if (accountList.Retrieve(acctNumSearch, account))
				{
					account->PrintHistory();
					cout << endl;
				}
			}
		}
		transactionList.pop();
	}
	return true;
}

void JollyBanker::PrintResults()
{
	cout << endl;
	cout << "Processing Done. Final Balances" << endl;
	accountList.Display();
}
