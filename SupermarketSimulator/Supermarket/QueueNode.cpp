#include "QueueNode.h"


//constructor and destructor
QueueNode::QueueNode(Data *nData, int noOfItems)
{
	this->mpData = nData;
	this->mList=new GroceryList(noOfItems); 
	this->mpNext = nullptr;
}

QueueNode::~QueueNode()
{
}


//setters and getters
void QueueNode::setData(Data *newData)
{
	this->mpData = newData;
}

void QueueNode::setGroceryList(GroceryList* groceryList)
{
	this->mList = groceryList;
}

void QueueNode::setNextPtr(QueueNode *pNewNext)
{
	this->mpNext = pNewNext;
}

Data * QueueNode::getData()  const 
{
	return this->mpData;
}

GroceryList * QueueNode::getList() const
{
	return this->mList;
}

QueueNode * QueueNode::getNextPtr() const
{
	return this->mpNext;
}