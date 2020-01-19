#pragma once

#include <iostream>
#include "QueueNode.h"

using std::cin;
using std::cout;
using std::endl;

class Queue
{
public:
	Queue();
	bool enqueue(Data *newData, int noOfItems);
	bool dequeue();
	void printQueue();
	bool isEmpty();
	int getpHeadServTime();
	int getpHeadCustNum();
	int getpHeadTotalTime();

private:
	QueueNode *pHead;
	QueueNode *pTail;
};