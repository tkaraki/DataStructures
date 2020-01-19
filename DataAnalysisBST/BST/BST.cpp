#include "BST.h"

BST::BST()
{
	this->pRoot = nullptr;
}

BST::~BST()
{
	destroyTree(this->pRoot);
}

void BST::destroyTree(Node *pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		delete pTree;
	}

	this->pRoot = nullptr;//??
} 



Node* BST::getpRoot()
{
	return this->pRoot;
}

void BST::setpRoot(Node* pRoot)
{
	this->pRoot = pRoot;
}


void BST::insert(string data, int units)
{
	insert(this->pRoot, data, units);
}

void BST::insert(Node*& pTree, string data, int units)
{
	TransactionNode *node = new TransactionNode(data, units);

	if (pTree == nullptr) // empty tree
	{
		this->pRoot = node;
	}
	else //  nonempty tree
	{
		TransactionNode* tempTreeNode; //temp Transaction node to call getUnits function
		tempTreeNode= (TransactionNode*) pTree;

		if (units < tempTreeNode->getUnits()) //left
		{
			if (pTree->getLeftPtr() != nullptr)
			{
				//recursive
				insert(pTree->getLeftPtr(), data, units);
			}
			else
			{
				//insert
				pTree->setLeftPtr(node);
			}
		}
		else if (units > tempTreeNode->getUnits()) //right
		{
			if (pTree->getRightPtr() != nullptr)
			{
				//recursive
				insert(pTree->getRightPtr(), data, units);
			}
			else
			{
				// insert
				pTree->setRightPtr(new TransactionNode(data, units));
			}
		}
	}
} 


void BST::inOrderTraversal() {
	cout << "BST Contents:" << endl;
	inOrderTraversal(this->pRoot);
}

void BST::inOrderTraversal(Node *&pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getLeftPtr());
		pTree->printData();
		inOrderTraversal(pTree->getRightPtr());
	}

}


TransactionNode& BST::findSmallest()
{
	TransactionNode* tempNode; //temp Node to store and return value
	tempNode = (TransactionNode*) this->pRoot;

	while (tempNode->getLeftPtr()!=nullptr) 
	{
		tempNode = (TransactionNode*) tempNode->getLeftPtr(); //get leftmost node in BST
	}


	return *tempNode;
}

TransactionNode& BST::findLargest()
{
	TransactionNode* tempNode; //temp Node to store and return value
	tempNode = (TransactionNode*)this->pRoot;

	while (tempNode->getRightPtr() != nullptr)
	{
		tempNode = (TransactionNode*)tempNode->getRightPtr(); //get rightmost node in BST
	}


	return *tempNode;
}
