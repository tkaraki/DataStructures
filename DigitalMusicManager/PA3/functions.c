#include "header.h"

void load(Node** list) {


	//Open File and Read 
	FILE* infile = NULL; 
	infile = fopen("musicPlayList.csv", "r");

	char line[100];
	char tempDuration[50];
	Record data;

	if (infile != NULL) {
		while (fgets(line, 100, infile) != NULL) {

			if (line[0] == '\"') {
				
				int i = 0, j = 0;
				char first[20], last[20];
				char finalNAME[30];
				strcpy(first, strtok(line, ","));
				strcpy(last, strtok(NULL, ","));
				while (last[j+1] != '\"') {
					finalNAME[j] = last[j + 1];
					j++;
				}
				finalNAME[j] = ' ';
				while (first[i + 1] != '\0') {
					finalNAME[j + 1] = first[i + 1];
					i++;
					j++;
				}
				finalNAME[j+1] = '\0';
				strcpy(data.artist, finalNAME);
				strcpy(data.album, strtok(NULL, ","));
				strcpy(data.title, strtok(NULL, ","));
				strcpy(data.genre, strtok(NULL, ","));
				strcpy(tempDuration, strtok(NULL, ","));
				(data.playcount = atoi(strtok(NULL, ",")));
				(data.rating = atoi(strtok(NULL, "\0")));
				(data.length.minutes = atoi(strtok(tempDuration, ":")));
				(data.length.seconds = atoi(strtok(NULL, "\0")));


			}

			else {
				strcpy(data.artist, strtok(line, ","));
				strcpy(data.album, strtok(NULL, ","));
				strcpy(data.title, strtok(NULL, ","));
				strcpy(data.genre, strtok(NULL, ","));
				strcpy(tempDuration, strtok(NULL, ","));
				(data.playcount = atoi(strtok(NULL, ",")));
				(data.rating = atoi(strtok(NULL, "\0")));
				(data.length.minutes = atoi(strtok(tempDuration, ":")));
				(data.length.seconds = atoi(strtok(NULL, "\0")));
			}

			//Insert into List

			insertAtFront(list, data);

		}
	}

	fclose(infile);

}

int isEmpty(Node *pList)
{
	return (pList == NULL);
}

void initList(Node **pList)
{
	*pList = NULL;

}

Node *makeNode(Record newdata)
{
	Node *pMem = NULL;

	pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		pMem->data = newdata;
		pMem->pLink = NULL;
		pMem->pPrev = NULL;
	}

	return pMem;
}

void insertAtFront(Node **pList, Record newData)
{
	Node *pMem = NULL;

	pMem = makeNode(newData);
	
	if (pMem != NULL)
	{
		pMem->pLink = *pList;// connect the link of the new Node to the front of list
		if (!isEmpty(*pList))
		{
			(*pList)->pPrev = pMem;
		}

		*pList = pMem;
	}

}

void displayALL(Node* pList) {
	printf("--------\n ");
	if (pList != NULL) {
		printf("Artist: %s\n ", pList->data.artist);
		printf("Album: %s\n ", pList->data.album);
		printf("Title: %s\n ", pList->data.title);
		printf("Genre: %s\n ", pList->data.genre);
		printf("Duration: %d:%d \n ", pList->data.length.minutes, pList->data.length.seconds);
		printf("Playcount: %d\n ", pList->data.playcount);
		printf("Rating: %d\n ", pList->data.rating);
		displayALL(pList->pLink);
	}

}

void display(Node *pList)
{
	int selection;
	printf("1.    Print all records.\n2.    Print all records that match an artist.\n ");
	printf("Select an option and enter the corresponding number:   ");
	scanf("%d", &selection);
	char c = getchar();

	if (selection==1 || selection==2){ 
	if (selection == 1) {
		displayALL(pList);
	}

	else {
		char artist[20];
		printf("Make sure your input matches the name in the file exactly. Include capital letters, spaces...\n");
		printf("Enter the artist:");
		fgets(artist, 19, stdin);
		artist[strlen(artist) - 1] = '\0'; 
		/*printf("\nEnter the artist: ");
		scanf("%s", artist);*/

		//Search for artist
		Node *pPrev = NULL, *pCur = pList;
		int success = 0;
		while (pCur != NULL)
		{
			// did we find the artist?
			if (strcmp(artist, pCur->data.artist) == 0)
			{
				printf("--------\n ");
				printf("Artist: %s\n ", pCur->data.artist);
				printf("Album: %s\n ", pCur->data.album);
				printf("Title: %s\n ", pCur->data.title);
				printf("Genre: %s\n ", pCur->data.genre);
				printf("Duration: %d:%d \n ", pCur->data.length.minutes, pCur->data.length.seconds);
				printf("Playcount: %d\n ", pCur->data.playcount);
				printf("Rating: %d\n ", pCur->data.rating);

				success = 1;
			}

				pPrev = pCur;
				pCur = pCur->pLink;
			
		}
		if (success!=1) 
			printf("Artist could not be found.");

	}
		

	}
	
	else 
		printf("Invalid selection.");
	
}

void store(Node *pList)
{
	FILE *outfile = NULL;
	outfile = fopen("musicPlayList.csv", "w");

	Node *pCur = pList;

	
	while (pCur != NULL)
	{
		fprintf(outfile,"--------\n");
		fprintf(outfile,"Artist: %s\n ", pCur->data.artist);
		fprintf(outfile, "Album: %s\n ", pCur->data.album);
		fprintf(outfile, "Title: %s\n ", pCur->data.title);
		fprintf(outfile, "Genre: %s\n ", pCur->data.genre);
		fprintf(outfile, "Duration: %d:%d \n ", pCur->data.length.minutes, pCur->data.length.seconds);
		fprintf(outfile, "Playcount: %d\n ", pCur->data.playcount);
		fprintf(outfile, "Rating: %d\n ", pCur->data.rating);
		pCur= pCur->pLink;
	}

	fclose(outfile);
}

void edit(Node **pList)
{
	char artis[20];
	char alteration[20];
	int attribute = 0;
	int chooseTrack; 
	printf("Make sure your input matches the name in the file exactly. Include capital letters, spaces...\n");
	printf("Enter the artist you would like to edit:");
	fgets(artis,19,stdin);
	artis[strlen(artis) - 1] = '\0';
	

	//Search for artist
	Node *pPrev = NULL, *pCur = *pList;
	int success = 0;
	while (pCur != NULL)
	{
		// find the artist and song
		if (strcmp(artis, pCur->data.artist)==0)
		{
			printf("Is this the track you are looking for?\n Track:");
			printf("%s\n ", pCur->data.title);
			
			printf("  1-Yes \n   2-No \n ");
			printf("Enter the corresponding number:");
			scanf("%d", &chooseTrack);
			if (chooseTrack == 1) {
				success = 1;
				break;
			}
			

		}
		
			pPrev = pCur;
			pCur = pCur->pLink;
	}

	//Edit Artist
	int rate;
	if (success == 1) {
		//attributes that should be altered by a user
		printf("\n1-Artist \n2-Album \n3-Title \n4-Genre \n5-Rating\n ");
		printf("Enter the corresponding number of the attribute to be altered:");
		scanf("%d", &attribute);
		char c = getchar();

		printf("Enter your alteration:");
		switch (attribute) {
		case 1:
			fgets(alteration, 20, stdin);
			alteration[strlen(alteration) - 1] = '\0';
			strcpy(pCur->data.artist, alteration);
			break;

		case 2:
			fgets(alteration, 20, stdin);
			alteration[strlen(alteration) - 1] = '\0';
			strcpy(pCur->data.album, alteration);
			break;

		case 3:
			fgets(alteration, 20, stdin);
			alteration[strlen(alteration) - 1] = '\0';
			strcpy(pCur->data.title, alteration);
			break;
		case 4:
			fgets(alteration, 20, stdin);
			alteration[strlen(alteration) - 1] = '\0';
			strcpy(pCur->data.genre, alteration);
			break;
		case 5:
			scanf("%d", &rate);
			pCur->data.rating = rate;
			break;
		default:
			printf("\nInvalid Selection.Try again.\n");
			break;

		}
	}

	else
		printf("Selection could not be found."); //track not found
	
}

void rate(Node **pList){

	char artist[20];
	int rate = 0;
	int chooseTrack;
	printf("Make sure your input matches the name in the file exactly. Include capital letters, spaces...\n");
	printf("Enter the artist of the track you would like to rate:");
	fgets(artist, 19, stdin);
	artist[strlen(artist) - 1] = '\0';

	//Search for artist
	Node *pPrev = NULL, *pCur = *pList;
	int success = 0;
	while (pCur != NULL)
	{
		// did we find the artist?
		if (strcmp(artist, pCur->data.artist) == 0)
		{
			printf("Is this the track you are looking for?\n Track:");
			printf("%s\n ", pCur->data.title);

			printf("  1-Yes \n   2-No \n ");
			printf("Enter the corresponding number:"); 
			
			scanf("%d", &chooseTrack);
			if (chooseTrack == 1) {
				success = 1;
				break;
			}


		}

		pPrev = pCur;
		pCur = pCur->pLink;
	}

	//Edit Artist
	if (success == 1) {
		int choice=0;
		do {
			printf("Enter a number between 1 and 5 to rate this track:\n");
			scanf("%d", &rate);
			
			if (rate > 0 && rate < 6) {
				pCur->data.rating = rate;
				choice = 1;
				printf("Rating Changed");
			}
			
			else 
				printf("Invalid Rating.Try again.\n");
		} while (choice == 0);
		

		}
	else 
		printf("Selection could not be found.");
}

void play(Node **pList) {
	
	char userTrack[20];
	int chooseTrack;
	printf("Make sure your input matches the name in the file exactly. Include capital letters, spaces...\n");
	printf("Enter the name of the track you would like to play:");
	fgets(userTrack, 19, stdin);
	userTrack[strlen(userTrack) - 1] = '\0';
	

	//Search for track
	Node *pPrev = NULL, *pCur = *pList;
	int success = 0;
	while (pCur != NULL)
	{
		// did we find the track?
		if (strcmp(userTrack, pCur->data.title) == 0)
		{
			printf("Is this the track you are looking for?\n");
			printf(" Artist:%s\n Track:%s\n ", pCur->data.artist, pCur->data.title);
			printf("Enter the corresponding number:\n");
			printf("1-Yes \n2-No \n ");
			scanf("%d", &chooseTrack);
			if (chooseTrack == 1) {
				success = 1;
				break;
			}


		}

		pPrev = pCur;
		pCur = pCur->pLink;
	}

	//Play Tracks
	if (success == 1) {
		
		playALL(pCur);
	}
	else
		printf("Selection could not be found.");
}

void insert(Node** pList, Record data) {


	if (data.length.minutes< 0 || data.length.seconds>60 || data.length.seconds<0)
	{
		printf("Invalid Data not inserted. Minutes and seconds must be greater than 0. Seconds must be less than 60.\n");
	}
	
	if (data.playcount <0) { 
		printf("Invalid Data not inserted. Number of times played must be greater than 0.\n"); 
	}

	if (data.rating<0 || data.rating>6) {
		printf("Invalid Data not inserted. Rating must be between 1 and 5.\n");
	}
	else { insertAtFront(pList, data);}

		

}

Record createRecord() {


	char artistNEW[50], titleNEW[50], genreNEW[50], albumNEW[50];
	int mins, secs, plays, rate;
	Record data;

	printf("Enter the name of the artist:");
	fgets(artistNEW, 50, stdin);
	strcpy(data.artist, strtok(artistNEW, "\n"));

	printf("Enter the name of the album:");
	fgets(albumNEW, 50, stdin);
	strcpy(data.album, strtok(albumNEW, "\n"));

	printf("Enter the title of the track:");
	fgets(titleNEW, 50, stdin);
	strcpy(data.title, strtok(titleNEW, "\n"));

	printf("Enter the genre:");
	fgets(genreNEW, 50, stdin);
	strcpy(data.genre, strtok(genreNEW, "\n"));

	int isTimeValid = 0, isPlayValid = 0, isRateValid = 0;
	do {

		printf("Enter the minutes:");
		scanf("%d", &mins);
		printf("Enter the seconds:");
		scanf("%d", &secs);

		if (mins >= 0 && secs < 60 && secs >= 0)
		{
			isTimeValid = 1;
			data.length.minutes = mins;
			data.length.seconds = secs;
		}
		else {
			printf("Invalid Input. Minutes and seconds must be greater than 0. Seconds must be less than 60.\n");
		}
	} while (isTimeValid == 0);


	do {

		printf("Enter the number of times played:");
		scanf("%d", &plays);

		if (plays >= 0) {
			data.playcount = plays;
			isPlayValid = 1;
		}
		else { printf("Invalid Input. Number of times played must be greater than 0.\n"); }

	} while (isPlayValid == 0);


	do {

		printf("Enter a rating between 1 and 5:");
		scanf("%d", &rate);

		if (rate > 0 && rate < 6) {
			data.rating = rate;
			isRateValid = 1;
		}
		else { printf("Invalid Input. Rating must be between 1 and 5.\n"); }

	} while (isRateValid == 0);

	return data;

}

Node *searchForDelete(Node **pList) {

	char userTrack[20];
	int chooseTrack;
	printf("Make sure your input matches the name in the file exactly. Include capital letters, spaces...\n");
	printf("Enter the name of the track you would like to play:");
	fgets(userTrack, 19, stdin);
	userTrack[strlen(userTrack) - 1] = '\0';


	//Search for track
	Node *pPrev = NULL, *pCur = *pList;
	Node *removal=NULL;
	int success = 0;
	while (pCur != NULL)
	{
		// did we find the track?
		if (strcmp(userTrack, pCur->data.title) == 0)
		{
			printf("Is this the track you are looking for?\n");
			printf(" Artist:%s\n Track:%s\n ", pCur->data.artist, pCur->data.title);
			printf("Enter the corresponding number:\n");
			printf("1-Yes \n2-No \n ");
			scanf("%d", &chooseTrack);
			if (chooseTrack == 1) {
				success = 1;
				removal = pCur;
				break;
			}


		}

		pPrev = pCur;
		pCur = pCur->pLink;
	}

	//Play Tracks
	if (success == 1) {
		return removal;
	}
	else
		printf("Selection could not be found.");
	return removal;


}

void delete(Node **pList,Node *removeThis)
{
	//this was copied from the class code files
	Node *pPrev = NULL, *pCur = *pList;
	int success = 0;

	while (success != 1 && pCur != NULL && removeThis!=NULL)
	{
		// did we find the item to delete?
		if (pCur == removeThis)
		{
			// found the item
			success = 1;
			printf("Track Deleted.");

			//...more code required
			if (pPrev != NULL) // we're not deleting first item
			{
				pPrev->pLink = pCur->pLink;
			}
			else // deleting the first item
			{
				*pList = pCur->pLink;
			}

			// once we find node, we connect rest of lists,
			// and we free the node
			//free(pTemp);
			free(pCur);
		}
		else // didn't find item yet
		{
			// advance to next node
			pPrev = pCur;
			pCur = pCur->pLink;
		}

	}

	if (success!=1)
	printf("Track not  deleted.");

}

void playALL(Node* pList) {
	printf("Now Playing:\n "); 
	
	if (pList != NULL) {
		printf("-------------------------\n ");
		printf("Artist: %s\n ", pList->data.artist);
		printf("Album: %s\n ", pList->data.album);
		printf("Title: %s\n ", pList->data.title);
		printf("Genre: %s\n ", pList->data.genre);
		printf("Duration: %d:%d \n ", pList->data.length.minutes, pList->data.length.seconds);
		printf("Playcount: %d\n ", pList->data.playcount);
		printf("Rating: %d\n ", pList->data.rating);
		printf("-------------------------\n ");
		Sleep(3000);
		system("CLS");

		playALL(pList->pLink);
	}

}

void shuffle(Node *pList) {

		//find number of songs in list
	    int count=0;  
		Node* pCur = pList;  
		while (pCur!= NULL)
		{
			count++;
			pCur = pCur->pLink;
		}
		
		//make an array of positions 
		int arrayofpositions[50];
		for (int i = 0; i < count; i++) {
			arrayofpositions[i] = i;
		}
		
		//shuffle the positions
		srand(time(NULL));
		for (int j = count-1; j>0; j--)
		{
			int m = rand() % (j + 1);

			int temp = arrayofpositions[m];
			arrayofpositions[m] = arrayofpositions[j];
			arrayofpositions[j] = temp;
		}

		//play the songs
		for (int m = 0; m < count; m++) {
			shuffleALL(pList, arrayofpositions[m]);
		}
		

	}

void shuffleALL(Node* pList,int n) {

	Node *current = pList;
	int success = 0;
	while (current != NULL)
	{//look for node position and print contents
		if (success == n) {
			printf("Now Playing:\n ");
			printf("-------------------------\n ");
		printf("Artist: %s\n ", current->data.artist);
		printf("Album: %s\n ", current->data.album);
		printf("Title: %s\n ", current->data.title);
		printf("Genre: %s\n ", current->data.genre);
		printf("Duration: %d:%d \n ", current->data.length.minutes, current->data.length.seconds);
		printf("Playcount: %d\n ", current->data.playcount);
		printf("Rating: %d\n ", current->data.rating);
		printf("-------------------------\n ");
		Sleep(3000);
		system("CLS");
		break;
		}
		else {
			//keep searching
			success++;
			current = current->pLink;
		}
	}
	

	
}

//sorting functions
void sort(Node *pList) {

	    
	    int selection;

		// check is list is empty
		if (pList == NULL) 
			return;
		//Sorting Menu
	    printf("Sorting Options:\n");
		printf("   (1)    Artist (A-Z)\n   (2)    Album title(A - Z)\n   (3)    Rating(1 - 5)\n   (4)    Times played(largest - smallest)\n");
		printf("Enter the corresponding number:");
		scanf("%d", &selection);

		switch (selection) {
		case 1:
			sortArtist(pList);
			printf("\n\nPlaylist Sorted by Artist.\n");
			displayALL(pList);
			break;

		case 2:
			sortAlbum(pList);
			printf("\n\nPlaylist Sorted by Album.\n");
			displayALL(pList);
			break;

		case 3:
			sortRate(pList);
			printf("\n\nPlaylist Sorted by Rating.\n");
			displayALL(pList);
			break;
		case 4:
			sortPlay(pList);
			printf("\n\nPlaylist Sorted by Plays.\n");
			displayALL(pList);
			break;
		default:
			printf("\nInvalid Selection.Try again.\n");
			break;

		}

}

void sortArtist(Node *pList) {
	
	Node *pCur, *pPrev = NULL;
	int success;

	do 
	{
		pCur = pList;
		success = 0;

			while (pCur->pLink != pPrev) {
				if (strcmp(pCur->data.artist, pCur->pLink->data.artist) > 0)//compare artists
				{
					swap(pCur, pCur->pLink);
					success = 1;
				}

				pCur = pCur->pLink;

			}
			pPrev = pCur;
	} while (success); //make sure we go through the list again until it doesnt have to do a swap 
	
}

void sortAlbum(Node *pList) {

	Node *pCur, *pPrev = NULL;
	int success;

	do
	{
		pCur = pList;
		success = 0;

		while (pCur->pLink != pPrev) {
			if (strcmp(pCur->data.album, pCur->pLink->data.album) > 0)
			{
				swap(pCur, pCur->pLink);
				success = 1;
			}

			pCur = pCur->pLink;

		}
		pPrev = pCur;
	} while (success);

}

void sortRate(Node *pList){

	Node *pCur, *pPrev = NULL;
	int success;

	do
	{
		pCur = pList;
		success = 0;

		while (pCur->pLink != pPrev) {
			if (pCur->data.rating > pCur->pLink->data.rating)
			{
				swap(pCur, pCur->pLink);
				success = 1;
			}

			pCur = pCur->pLink;

		}
		pPrev = pCur;
	} while (success);
}

void sortPlay(Node *pList){
	Node *pCur, *pPrev = NULL;
	int success;

	do
	{
		pCur = pList;
		success = 0;

		while (pCur->pLink != pPrev) {
			if (pCur->data.playcount < pCur->pLink->data.playcount)
			{
				swap(pCur, pCur->pLink);
				success = 1;
			}

			pCur = pCur->pLink;

		}
		pPrev = pCur;
	} while (success);
}

//swap contents of two arrays.
void swap(Node *p1, Node *p2) {
	Record temp;
	temp = p2->data;
	p2->data = p1->data;
	p1->data = temp;
}



