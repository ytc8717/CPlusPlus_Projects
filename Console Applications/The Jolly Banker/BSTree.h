#pragma once
#include <iostream>
#include "Account.h"

using namespace std;

class BSTree
{
public:
	// constructors
	BSTree();
	~BSTree();

	// insert to tree
	bool insert(Account* insert);

	// get info from tree
	bool Retrieve(const int& accountID, Account*& account)const;

	// display acct info
	bool Display()const;

	// empty tree
	void Empty();

	// check if empty
	bool isEmpty()const;

private:
	struct Node
	{
		Account* pAcct = NULL;
		Node* right = NULL;
		Node* left = NULL;
	};
	Node* root;
	bool RecursiveInsert(Node* pNode, Account* insert); // recursive insert
	void Print(Node*) const;//prints all account in the search
};

