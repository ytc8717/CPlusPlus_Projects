#include "BSTree.h"
#include <iostream>
using namespace std;

BSTree::BSTree()
{
	root = nullptr;
}

BSTree::~BSTree()
{
	Empty();
}

bool BSTree::insert(Account* insert)
{
	int insertAccID = insert->getAccountID();
	if (insertAccID < 1000 || insertAccID > 9999)
	{
		cerr << "ERROR: Account number not valid" << endl;
		return false;
	}

	if (root == NULL)
	{
		root = new Node;
		root->pAcct = insert;
		root->left = NULL;
		root->right = NULL;
		return true;
	}
	else
	{
		Node* pNode = root;
		RecursiveInsert(pNode, insert);
	}
	return false;
}

bool BSTree::Retrieve(const int& accountID, Account*& account) const
{
	Node* pNode = root;
	bool search = false;

	while (!search)
	{
		if (pNode != NULL && accountID == pNode->pAcct->getAccountID())
		{
			search = true;
			account = pNode->pAcct;
			return search;
		}
		else if (pNode != NULL && accountID > pNode->pAcct->getAccountID())
		{
			pNode = pNode->right;
		}
		else if (pNode != NULL && accountID < pNode->pAcct->getAccountID())
		{
			pNode = pNode->left;
		}
		else
		{
			search = true;
		}
	}
	cerr << "ERROR: Account " << accountID << " not found. Transferal refused." << endl;
	return false;
}

bool BSTree::Display() const
{
	if (root != NULL)
	{
		Print(root);
	}
	return false;
}

void BSTree::Empty()
{
	delete root;
	root = NULL;
}

bool BSTree::isEmpty() const
{
	if (root->left == NULL && root->right == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BSTree::RecursiveInsert(Node* pNode, Account* insert)
{
	if (insert->getAccountID() > pNode->pAcct->getAccountID())
	{
		if (pNode->right == NULL)
		{
			Node* insInTree = new Node();
			insInTree->pAcct = insert;
			insInTree->left = NULL;
			insInTree->right = NULL;
			pNode->right = insInTree;
			return true;
		}
		else
		{
			return RecursiveInsert(pNode->right, insert);
		}

	}
	else if (insert->getAccountID() < pNode->pAcct->getAccountID())
	{
		if (pNode->left == NULL)
		{
			Node* insInTree = new Node();
			insInTree->pAcct = insert;
			insInTree->left = NULL;
			insInTree->right = NULL;
			pNode->left = insInTree;
			return true;
		}
		else
		{
			return RecursiveInsert(pNode->left, insert);
		}

	}
	else
	{
		cerr << "ERROR: Account " << insert->getAccountID() << " is already opened. Transaction refused." << endl;
		return false;
	}
}

void BSTree::Print(Node* ptr) const
{
	if (ptr != NULL)
	{
		Print(ptr->left);
		cout << ptr->pAcct->getFirstName() << " " << ptr->pAcct->getLastName()
			<< " Account ID: " << ptr->pAcct->getAccountID() << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << "   " << ptr->pAcct->getFundName(i) << ": $" << ptr->pAcct->getBalance(i) << endl;
		}
		cout << endl;
		Print(ptr->right);
	}
}
