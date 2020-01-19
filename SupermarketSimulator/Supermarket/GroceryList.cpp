#include "GroceryList.h"

//Constructor
GroceryList::GroceryList(int n) 
{
	pHead = nullptr;
	customerList(n);
}


GroceryList::~GroceryList()
{
	node* temp = this->pHead;
	while (temp != nullptr) {
		node* next = temp->mpNext;
		delete temp;
		temp = next;
	}
	
}

//creates a node to be inserted into list
node* GroceryList::makeNode(string itemName)
{
	node *pMem = new node;
	pMem->mitem= itemName;
	pMem->mpNext = nullptr;

	return pMem;
}

//inserts items at front
void GroceryList::insert(string itemName)
{
	node *pMem = makeNode(itemName);

	if (pHead == nullptr)
	{
		pHead = pMem;
	}

	else
	{
		pMem->mpNext = pHead;
		pHead = pMem;
	}
}

//create list for each customer
void GroceryList::customerList(int itemNumber)
{
	int count = 0;

	//insert items

	while (count != itemNumber)
	{
		insert(itemExamples[count]);
		count++;
	}
	
	
}

void GroceryList::printList()
{
	node *pTraverse = this->pHead;

	while (pTraverse != nullptr)
	{
		cout << pTraverse->mitem << " ";

		pTraverse = pTraverse->mpNext;
	}

}