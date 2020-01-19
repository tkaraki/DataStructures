/*******************************************************************************                                          *
 * Date:  2/9/2019                                                                     *
 *                                                                             *
 * Description: Digital Music Manager  
 ******************************************************************************/


#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>  
#include <time.h>	
#include <stdlib.h> 
#include <string.h>
#include <windows.h>


typedef struct duration {
	int seconds;
	int minutes;
}Duration;

typedef struct record {
	char artist[100];
	char album[100];
	char title[100];
	char genre[100];
	Duration length;
	int playcount;
	int rating;
}Record;

typedef struct node
{
	Record data;
	struct node *pLink;
	struct node *pPrev;
} Node;

//Doubly Linked List
Node *makeNode(Record data);
void insertAtFront(Node **pList, Record newItem);
int isEmpty(Node *pList);
void initList(Node **pList);

//Menu Functions 
void load(Node** list);
void store(Node *pList);
void display(Node *pList);
void displayALL(Node* pList);
void insert(Node** pList, Record data);
Record createRecord();
void delete(Node **pList, Node *removeThis);
Node *searchForDelete(Node **pList);
void edit(Node **pList);
void rate(Node **pList);
void playALL(Node* pList);
void play(Node **pList);
void shuffle(Node *pList);
void shuffleALL(Node* pList, int n);
void sort(Node *pList);
void swap(Node *p1, Node *p2);
void sortArtist(Node *pList);
void sortAlbum(Node *pList);
void sortRate(Node *pList);
void sortPlay(Node *pList);


#endif