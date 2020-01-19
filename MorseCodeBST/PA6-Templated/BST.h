#pragma once

#include "BSTNode.h"

#include <iostream>
#include <string>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::string;

using std::cin;
using std::cout;
using std::endl;


template<class T1, class T2>
class BST
{
public:
	BST();
	~BST();
	void insert(BSTNode<T1,T2> *pTree, T1 englishText, T2 morseCode);
	T2 search(T1 englishText);
	void print();
	void convertText();
	void convertTextHelper(T2 line);

private:
	BSTNode<T1,T2> *pRoot;
	void printHelper(BSTNode<T1, T2> *pTree);
	bool searchHelper(BSTNode<T1, T2> *pTree, T1 englishText, T2 *returnThis);
	void destructorHelper(BSTNode<T1, T2> *pTree);
};


template <class T1,class T2>
BST<T1,T2>::BST()
{
	this->pRoot = nullptr;

	T1 english;
	T2 morse;

	ifstream infile;
	infile.open("morseCode.txt");
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			infile >> english >> morse;
			insert(this->pRoot, english, morse);

		}

		infile.close();
	}
	else cout << "Unable to open file";

}

template <class T1, class T2>
BST<T1, T2>::~BST()
{
	destructorHelper(this->pRoot);
}

template <class T1, class T2>
void BST<T1, T2>::destructorHelper(BSTNode<T1,T2> *pTree)
{
	if (pTree != nullptr)
	{
		destructorHelper(pTree->getLeftPtr());
		destructorHelper(pTree->getRightPtr());
		delete pTree;
	}
}

template <class T1, class T2>
void BST<T1, T2>::insert(BSTNode<T1,T2> *pTree, T1 englishText, T2 morseCode)
{
	if (pTree == nullptr) // empty tree
	{
		this->pRoot = new BSTNode<T1, T2>(englishText, morseCode);
	}
	else //  nonempty tree
	{
		if (englishText < pTree->getEnglish()) //left
		{
			if (pTree->getLeftPtr() != nullptr)
			{
				//recursive
				insert(pTree->getLeftPtr(), englishText, morseCode);
			}
			else
			{
				//insert
				pTree->setLeftPtr(new BSTNode<T1,T2>(englishText, morseCode));
			}
		}
		else if (englishText > pTree->getEnglish()) //right
		{
			if (pTree->getRightPtr() != nullptr)
			{
				//recursive
				insert(pTree->getRightPtr(), englishText, morseCode);
			}
			else
			{
				// insert
				pTree->setRightPtr(new BSTNode<T1, T2>(englishText, morseCode));
			}
		}

	}
}

template <class T1, class T2>
T2 BST<T1, T2>::search(T1 englishText)
{
	T2 returnThis="";
	bool isFound = searchHelper(this->pRoot, englishText, &returnThis);

	if (isFound == true)
	{
		return returnThis;
	}

	else
		cout << "Character Not Found" << endl;;
	return returnThis;

}

template <class T1, class T2>
bool BST<T1, T2>::searchHelper(BSTNode<T1,T2> *pTree, T1 englishText, T2 *returnThis)
{

	//english character found 
	if (englishText == pTree->getEnglish())
	{
		*returnThis = pTree->getMorse();
		return true;
	}

	////traverse tree recursively
	  //left
	else if (englishText < pTree->getEnglish())
	{
		//not found
		if (pTree->getLeftPtr() == NULL)
			return false;

		else
			//recursive 
			return searchHelper(pTree->getLeftPtr(), englishText, returnThis);

	}
	//right
	else if (englishText > pTree->getEnglish()) {

		if (pTree->getRightPtr() == NULL)
			return false;

		else
			return searchHelper(pTree->getRightPtr(), englishText, returnThis);

	}

	return false;
}

template <class T1, class T2>
void BST<T1, T2>::print() {
	cout << "Morse Code by ASCII value:" << endl;
	printHelper(this->pRoot);
}

template <class T1, class T2>
void BST<T1, T2>::printHelper(BSTNode<T1,T2> *pTree)
{
	if (pTree != nullptr)
	{
		printHelper(pTree->getLeftPtr());
		cout << pTree->getEnglish() << " : " << pTree->getMorse() << endl;
		printHelper(pTree->getRightPtr());
	}

}

template <class T1, class T2>
void BST<T1, T2>::convertText()
{
	T2 line1;
	T2 line2;
	T2 line3;

	ifstream infile;
	infile.open("convert.txt");
	if (infile.is_open())
	{
		getline(infile, line1);
		getline(infile, line2);
		getline(infile, line3);
		cout << line1 << endl << line2 << endl << line3 << endl << endl;

		convertTextHelper(line1);//prints morse code of each line
		convertTextHelper(line2);
		convertTextHelper(line3);

		infile.close();

	}
	else cout << "Unable to open file";

}

template <class T1, class T2>
void BST<T1, T2>::convertTextHelper(T2 line)
{
	//convert input line to uppercase
	for (int i = 0; i < line.length(); i++)
	{
		line[i] = toupper(line[i]);
	}

	//print out morse code by comparing each character
	T1 c;
	for (int i = 0; i < line.length(); i++)
	{
		c = line[i];

		switch (c)
		{
		case (' '): cout << "   ";
			break;
		default: cout << search(c) << " ";
		}
	}

	cout << endl;
}