#pragma once

#include <iostream>
#include <string>
using std::string;
using std::cout;


struct node
{
	string mitem;
	node *mpNext;
};

static string itemExamples[] = {"oranges", "apples", "milk","cereal","chocolate","coffee","juice","gum"};

class GroceryList
{
public:
	GroceryList(int n=0);//constructor for linked list
	~GroceryList();
	node* makeNode(string itemName);//creates node for list
	void insert(string itemName);//insert items into list
	void customerList(int itemNumber);//create list for each customers service time
	void printList();

private:
	node *pHead;
	
};