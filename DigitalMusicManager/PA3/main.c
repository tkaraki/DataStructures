#include "header.h"

int main() {


	Node *pHead;
	initList(&pHead);

	//Print Menu
	int selection;
	int menu = 1;
	
	do {
		printf("\n\n ---------------\n      Menu      \n ---------------\n(1)   Load\n(2)   Store\n(3)   Display\n(4)   Insert\n(5)   Delete\n(6)   Edit\n(7)   Sort\n(8)   Rate\n(9)   Play\n(10)  Shuffle\n(11)  Exit\n");
		printf("\nEnter the corresponding number:");
		scanf_s("%d", &selection);
		char c = getchar();
		
		
		switch (selection) {
	case 1:
		load(&pHead);
		printf("\nPlaylist Loaded\n");
		break;

	case 2:
		store(pHead);
		printf("\nPlaylist Stored\n");
		break;

	case 3:
		printf("\nDisplay\n");
		display(pHead);
		break;
	case 4:
		printf("\nInsert\n");
		Record dataNEW = createRecord();
		insert(&pHead,dataNEW);
		break;
	case 5:
		printf("\nDelete\n");
		Node *deletion= searchForDelete(&pHead);
		delete(&pHead, deletion);
		break;
	case 6:
		printf("\nEdit\n");
		edit(&pHead);
		break;
	case 7:
		printf("\nSort\n");
		sort(pHead);
		break;
	case 8:
		printf("\nRate Tracks\n\n");
		rate(&pHead);
		break;
	case 9:
		printf("\nPlay Tracks\n\n");
		play(&pHead);
		break;
	case 10:
		printf("\nShuffle\n");
		shuffle(pHead);
		break;
	case 11:
		printf("\n Menu Closed.\n");
		store(pHead);
		menu = 0;
		break;
	default:
		printf("\nInvalid Selection.Try again.\n");
		break;
	}

	} while (menu==1);


	
	
	return 0;
}