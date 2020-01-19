#pragma once

#include <iostream>
#include "Node.h"


template <class T>
class List
{
public:
	List();
	~List();

	List & operator= (const List<T>& copy);
	

	Node<T> *getpHead() const;
	void setpHead(Node<T> *pList);

	Node<T> *makeNode(T *student);
	void insert(T *student);


private:
	Node<T> *mpHead;
};



//constructor 
template <class T>
List<T>::List()
{
	this->mpHead = nullptr;
}


template <class T>
List<T>::~List()
{
	Node<T> *pTemp = this->mpHead;
	while (pTemp != nullptr) {
		Node<T> *next = pTemp->getpNext();
		delete pTemp;
		pTemp = next;
	}
	
	mpHead = nullptr;
}


template<class T>
List<T>& List<T>::operator= (const List<T>& copy)
{
	mpHead = nullptr;
	T *content;
	Node<T> *pCopy = copy.getpHead();

	while (pCopy != nullptr)
	{
		content = pCopy->getRecord();
		insert(content);

		pCopy = pCopy->getpNext();
	}

	return *this;
}



template <class T>
Node<T> *List<T>::getpHead() const 
{
	return this->mpHead;
}


template <class T>
void List<T>::setpHead(Node<T> *pList)
{
	this->mpHead = pList;
}


template <class T>
Node<T> *List<T>::makeNode(T *student)
{
	Node<T> *pTemp = new Node<T>(student);  

	return pTemp;

}

template <class T>
void List<T>::insert(T *student)
{
	Node<T> *pTemp = makeNode(student);
	
	//insert at front
	if (pTemp != nullptr)
	{
		pTemp->setpNext(mpHead);
		mpHead = pTemp;
	}

} 


