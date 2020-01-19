#pragma once

#include <iostream>
#include "Data.h"

using std::string;

template <class T>
class Node
{
public:
	Node(T *record);

	T *getRecord();
	Node<T> *getpNext();

	void setRecord(T *record);
	void setpNext(Node<T> *pNext);

private:
	T *mRecord;
	Node<T> *mpNext;
};


//constructor 
template <class T>
Node<T>::Node(T *record)
{
	this->mRecord = record;
	this->mpNext = nullptr;
}


//setters and getters
template <class T>
T *Node<T>::getRecord()
{
	return this->mRecord;
}

template <class T>
Node<T> *Node<T>::getpNext()
{
	return this->mpNext;
}


template <class T>
void Node<T>::setRecord(T *record)
{
	this->mRecord = record;
}

template <class T>
void Node<T>::setpNext(Node<T> *pNext)
{
	this->mpNext = pNext;
}

