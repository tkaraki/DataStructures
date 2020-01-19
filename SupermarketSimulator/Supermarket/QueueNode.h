#pragma once

#include <iostream>
#include <string>

#include "Data.h"
#include "GroceryList.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class QueueNode
{
public:
	//constructor and destructor
	QueueNode(Data *nData, int noOfItems);
	~QueueNode();

	//setters and getters
	void setData(Data *newData);
	void setGroceryList(GroceryList* groceryList);
	void setNextPtr(QueueNode *pNewNext);

	Data * getData() const;
	GroceryList* getList() const;
	QueueNode * getNextPtr() const;


private:
	Data *mpData;
	GroceryList *mList;
	QueueNode *mpNext;
	
};
