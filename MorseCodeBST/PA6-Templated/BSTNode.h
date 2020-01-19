#pragma once

#include <iostream>

using std::string;

template <class T1, class T2>
class BSTNode
{
public:
	BSTNode(T1 text, T2 code);
	BSTNode(BSTNode<T1,T2> &copy);

	T1 getEnglish();
	T2 getMorse();
	BSTNode<T1, T2> *getLeftPtr();
	BSTNode<T1, T2> *getRightPtr();

	void setEnglish(T1 text);
	void setMorse(T2 code);
	void setLeftPtr(BSTNode<T1, T2> *pNewLeft);
	void setRightPtr(BSTNode<T1, T2> *pNewRight);

private:
	T1 English;
	T2 Morse;
	BSTNode<T1, T2> *mpLeft;
	BSTNode<T1, T2> *mpRight;
};



template<class T1, class T2>
BSTNode<T1, T2>::BSTNode(T1 text, T2 code)
{
	English = text;
	Morse = code;
	mpLeft = nullptr;
	mpRight = nullptr;
}

template<class T1, class T2>
BSTNode<T1, T2>::BSTNode(BSTNode<T1,T2> &copy)
{
	// deep copy
	this->English = copy.English;
	this->Morse = copy.Morse;
	this->mpLeft = copy.mpLeft;
	this->mpRight = copy.mpRight;
}

template<class T1, class T2>
T1 BSTNode<T1, T2>::getEnglish()
{
	return this->English;
}

template<class T1, class T2>
T2 BSTNode<T1, T2>::getMorse()
{
	return this->Morse;
}

template<class T1, class T2>
BSTNode<T1, T2> *BSTNode<T1,T2>::getLeftPtr()
{
	return this->mpLeft;
}

template<class T1, class T2>
BSTNode<T1, T2> *BSTNode<T1, T2>::getRightPtr()
{
	return this->mpRight;
}

template<class T1, class T2>
void BSTNode<T1, T2>::setEnglish(T1 text)
{
	this->English = text;
}

template<class T1, class T2>
void BSTNode<T1, T2>::setMorse(T2 code)
{
	this->Morse = code;
}

template<class T1, class T2>
void BSTNode<T1, T2>::setLeftPtr(BSTNode<T1,T2> *pNewLeft)
{
	this->mpLeft = pNewLeft;
}

template<class T1, class T2>
void BSTNode<T1, T2>::setRightPtr(BSTNode<T1, T2> *pNewRight)
{
	this->mpRight = pNewRight;
}