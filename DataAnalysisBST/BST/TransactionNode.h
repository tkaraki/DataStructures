#pragma once

#include <iostream>
#include "Node.h"

class TransactionNode: public Node
{
public:

	//constructor & destructor 
	TransactionNode(string data, int units);
	~TransactionNode();

	//setters & getters
	int getUnits();
	void setUnits(int units);

	//overridden function
	void printData();

private:
	int mUnits;
};

