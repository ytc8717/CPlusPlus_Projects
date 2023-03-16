#pragma once
#include<queue>
#include"BSTree.h"
#include"Transactions.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
class JollyBanker
{
public:
	// constructor
	JollyBanker();
	//~JollyBanker();

	// read transaction info from file
	bool ReadFile();

	// execute transactions
	bool ProcessTransaction();

	// display the results
	void PrintResults();

private:
	// queue structure list
	queue<Transactions> transactionList;
	BSTree accountList;
};

