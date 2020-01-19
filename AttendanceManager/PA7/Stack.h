#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

using std::string;
using std::to_string;
using std::cout;
using std::endl;

class Stack
{
public:

	//constructor 
	Stack();

	void push(string date);
	void pop();
	string peek() const;
	bool isEmpty();
	string getDate();
	string printDates() const;
	void addDates();
	void reorderStack(int m);
	void locateDate(string m);
	int getpHead();

private:
	string date[50];
	int head;

};

