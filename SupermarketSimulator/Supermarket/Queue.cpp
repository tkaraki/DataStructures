#include "Queue.h"

Queue::Queue()
{
	this->pHead = this->pTail = nullptr;
}

//copied this from lecture codes
bool Queue::enqueue(Data *newData, int noOfItems)
{
	QueueNode *pMem = new QueueNode(newData, noOfItems);
	bool success = false;

	if (pMem != nullptr)
	{
		// allocated space
		success = true;
		if (this->pHead == nullptr)
		{
			// empty queue
			this->pHead = pMem;
			this->pTail = pMem;
		}
		else
		{
			// non empty queue
			this->pTail->setNextPtr(pMem);
			this->pTail = pMem;
		}
	}
	return success;
}

// also copied this from class codes
bool Queue::dequeue()
{
	bool success = false;;
	QueueNode *pTemp = nullptr;

	if (this->pTail == this->pHead)
	{
		// we have one node
		pTemp = this->pHead;
		this->pHead = this->pTail = nullptr;
		delete pTemp;
		success = true;
	}
	else
	{
		// more than 1 node in queue
		pTemp = this->pHead;
		this->pHead = this->pHead->getNextPtr();
		delete pTemp;
		success = true;
	}

	return success;
}

void Queue::printQueue()
{
	if (this->pHead == nullptr)
	{
		cout << "*** Empty Lane ***" << endl<<endl;
	}
	else {
		QueueNode *pTraverse = this->pHead;

	
		while (pTraverse != nullptr)
	
		{
		cout<<"Customer Number:" << pTraverse->getData()->getCustomerNumber() <<endl;
		cout << "Service Time:" << pTraverse->getData()->getServiceTime() <<endl;
		cout << "Grocery List:"; pTraverse->getList()->printList(); cout << endl;
		cout << "Total Time:" << pTraverse->getData()->getTotalTime()<<endl;
		cout << "-------------------------------" << endl;
		
		pTraverse = pTraverse->getNextPtr();
	
		}
	}
	
}

bool Queue::isEmpty()
{
	if (this->pHead == nullptr)
		return true;
	else
		return false;
}

int Queue::getpHeadServTime()
{
	if (pHead != nullptr)
	{
		return this->pHead->getData()->getServiceTime();
	}

	else
		return 0;
}

int Queue::getpHeadCustNum()
{
	if (pHead != nullptr)
	{
		return this->pHead->getData()->getCustomerNumber();
	}

	else
		return 0;
}

int Queue::getpHeadTotalTime()
{
	if (pHead != nullptr)
	{
		return this->pHead->getData()->getTotalTime(); 
	}

	else
		return 0;
}
