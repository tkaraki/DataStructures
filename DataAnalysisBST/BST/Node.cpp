
#include "Node.h"

Node::Node(string data, Node *pLeft, Node *pRight)
{
	mData = data;
	mpLeft = pLeft;
	mpRight = pRight;
}

Node::~Node()
{
	//?
}


string Node::getData()
{
	return mData;
}

Node*& Node::getLeftPtr()
{
	return mpLeft;
}

Node*& Node::getRightPtr()
{
	return mpRight;
}

void Node::setData(string data)
{
	mData = data;
}

void Node::setLeftPtr(Node* pNewLeft)
{
	this->mpLeft = pNewLeft;
}

void Node::setRightPtr(Node* pNewRight)
{
	this->mpRight = pNewRight;
}
