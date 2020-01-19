#include "TestDMM.h"

void testInsert(void)
{
	Node *pHead= NULL; 
	
	Record d = {.artist="Katy Perry",.album = "Witness",.title = "Chained to the Rhythm",.genre ="pop", .length.minutes = 4, .length.seconds = 36,.playcount = -1,.rating = 6}; 
	
	insert(&pHead, d); // executing the function, with our test inputs

	// compare expected results to actual results?

		if (d.playcount == pHead->data.playcount)
		{
			printf("passed: the list contains the new node\n");
		}
		else
		{
			printf("failed: the list didn't create a node\n");

		}

}

void testDelete(void) {

	Node *pHead = NULL;
	Record d = { .artist = "Katy Perry",.album = "Witness",.title = "Chained to the Rhythm",.genre = "pop",.length.minutes = 4,.length.seconds = 36,.playcount = 3,.rating = 5 };

	insert(&pHead, d);
	Node *pCur = pHead;
	delete(&pHead, pCur);

	if (pHead==NULL)
	{
		printf("passed: the item was deleted\n");
	}
	else
	{
		printf("failed: the item wasnt deleted\n");

	}

}

void testShuffle(void) {
	Node *pHead = NULL; 
	Record d1 = { .artist = "SONG 1",.album = "Witness",.title = "Chained to the Rhythm",.genre = "pop",.length.minutes = 4,.length.seconds = 36,.playcount = 3,.rating = 5 };
    insert(&pHead, d1);

	Record d2 = { .artist = "SONG 2",.album = "Witness",.title = "Chained to the Rhythm",.genre = "pop",.length.minutes = 4,.length.seconds = 36,.playcount = 3,.rating = 5 };
	insert(&pHead, d2);

	Record d3 = { .artist = "SONG 3",.album = "Witness",.title = "Chained to the Rhythm",.genre = "pop",.length.minutes = 4,.length.seconds = 36,.playcount = 3,.rating = 5 };
	insert(&pHead, d3);

	shuffleALL(pHead, 2);

	shuffleALL(pHead, 0);

	shuffleALL(pHead, 1);

}