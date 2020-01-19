#pragma once

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Node
{
public:

	//constructor & destructor
	Node(string data = "", Node *pLeft = nullptr, Node *pRight = nullptr);
	virtual ~Node();

	//setters & getters
	string getData();
	Node*& getLeftPtr();
	Node*& getRightPtr();

	void setData(string data);
	void setLeftPtr(Node* pNewLeft);
	void setRightPtr(Node* pNewRight);

	//pure virtual function
	virtual void printData() = 0;

protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;
};

