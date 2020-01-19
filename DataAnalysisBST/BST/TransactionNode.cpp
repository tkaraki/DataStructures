
#include "TransactionNode.h"

TransactionNode::TransactionNode(string data, int units)
{
	this->mData = data;
	this->mUnits = units;
}

TransactionNode::~TransactionNode()
{	
}


int TransactionNode::getUnits()
{
	return mUnits;
}


void TransactionNode::setUnits(int units)
{
	this->mUnits = units;
}


void TransactionNode::printData() 
{
	cout << "Data: " << this->getData() << endl;
	cout << "Units: " << this->getUnits() << endl;
	cout << endl;
}