#pragma once

#include "Node.h"
#include "TransactionNode.h"

class BST
{
public:
	BST();
	~BST();

	Node* getpRoot();
	void setpRoot(Node* pRoot);

	void insert(string data, int units);
	void inOrderTraversal();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();
	

private:
	Node *pRoot;
	void destroyTree(Node *pTree);
	void insert(Node*& pTree, string data, int units);
	void inOrderTraversal(Node *&pTree);

};