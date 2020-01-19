#include "Header.h"

int readFile(FitbitData data[1440]) {


	//Open File and Read 
	FILE* infile = NULL;
	infile = fopen("FitbitData.csv", "r");
	int success = 1;

	char line[100];
	char target[10];

	if (infile != NULL) {

		success = 0;
		//get patient name
		fgets(line, 100, infile);
		strtok(line, ",");
		strcpy(target, strtok(NULL, ","));

		//skip second line
		fgets(line, 100, infile);

		//start reading data
		int i = 0;
		char *nullChecker = NULL;
		char tempPATIENT[10];
		char tempTIME[10];
		

		while (fgets(line, 100, infile) != NULL) {
		
			//check for valid patient and minute 
			strcpy(tempPATIENT, strtok(line, ",")); 
			strcpy(tempTIME, strtok(NULL, ","));
		
			if ((strcmp(tempPATIENT, target) == 0) && (strcmp(tempTIME, data[i-1].minute)!=0)) {
				strcpy(data[i].patient, tempPATIENT);
				strcpy(data[i].minute, tempTIME);

				//check for NULL values and copy
				
				//calories
				nullChecker = strtok(NULL, ",");
				if (nullChecker != '\0')
				{
					data[i].calories = (atof(nullChecker));
				}

				
				//distance
				nullChecker = strtok(NULL, ",");
				if (nullChecker != '\0')
				{
					data[i].distance = (atof(nullChecker));
				}
			
				//floors
				nullChecker = strtok(NULL, ",");
				if (nullChecker != '\0')
				{
					data[i].floors = (atoi(nullChecker));
				}
				else { data[i].floors = 0; }//Replace with 0 instead of NULL

				//heartrate
				nullChecker = strtok(NULL, ",");
				if (nullChecker != '\0')
				{
					data[i].heartRate = (atoi(nullChecker));
				}
				else { data[i].heartRate = 0; }//Replace with 0 instead of NULL

				//steps
				nullChecker = strtok(NULL, ",");
				if (nullChecker != '\0')
				{
					data[i].steps = (atoi(nullChecker));
				}
				else { data[i].steps = 0; }//Replace with 0 instead of NULL

				//sleeplevel
				nullChecker = strtok(NULL, ",");
				if (nullChecker != '\0')
				{
					data[i].sleepLevel = (atoi(nullChecker));
				}
				else { data[i].sleepLevel = 0; }//Replace with 0 instead of NULL


				i++;


				}


			}
			

		}


	fclose(infile);
	return success;

	}

	double caloriesTotal(FitbitData data[1440]) {

		double caloriesTot = 0.0;
		
		for (int i = 0; i < 1440; i++)
		{
			caloriesTot += data[i].calories;
		}

		return caloriesTot;
	}

	double distanceTotal(FitbitData data[1440]) {

		double distanceTot = 0.0;

		for (int i = 0; i < 1440; i++)
		{
			distanceTot += data[i].distance;
		}

		return distanceTot;
	}

	unsigned int floorsTotal(FitbitData data[1440]) {

		unsigned int floorsTot = 0;

		for (int i = 0; i < 1440; i++)
		{
			floorsTot += data[i].floors;
		}

		return floorsTot;
	}

	unsigned int stepsTotal(FitbitData data[1440]) {

		unsigned int stepsTot = 0;

		for (int i = 0; i < 1440; i++)
		{
			stepsTot += data[i].steps;
		}

		return stepsTot;
	}

	unsigned int heartrateAverage(FitbitData data[1440]) {

		int heartrateTot = 0;
		int count=0;
		
		for (int i = 0; i < 1440; i++)
		{
				heartrateTot += data[i].heartRate;
				count++;
			
		}

		unsigned int avrg = heartrateTot /count;

		return avrg;
	}

	unsigned int stepsMax(FitbitData data[1440]) {

		unsigned int maxSteps = 0;

		for (int i = 0; i < 1440; i++)
		{
			if (data[i].steps >= maxSteps)
			{
				maxSteps = data[i].steps;
			}
		}

		return maxSteps;
	}

	void sleepRange(FitbitData data [1440], int *start, int *end) {

		int finalSum=0;
		int count = 0;
		int sum = 0;

		for (int i = 0; i < 1440; i++) {
			if (data[i].sleepLevel > 1)
			{
				count = i;
				while (data[count].sleepLevel > 1)
				{
					sum += data[count].sleepLevel;
					count++;
				}
				if (sum > finalSum)
				{
					*start = i;
					*end = count;
					sum = finalSum;
				}

			}
			sum = 0;
		}

		//printf("%d %d", start, end);
		
	}

	int printFile(FitbitData data[1440], double calories, double distance, int floors, int steps, int stepsMx, int heartrateAvrg, int start, int end) {
		
		FILE *outfile = NULL;
		outfile = fopen("Results.csv", "w");
		int success = 0;

		if (outfile != NULL) {
			success = 1;
			fprintf(outfile, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
		    fprintf(outfile, "%lf, %lf, %d, %d, %d, %d, %s:%s \n", calories, distance, floors, steps, heartrateAvrg, stepsMx, data[start].minute, data[end].minute);

			for (int i = 0; i < 1440; i++) {
				fprintf(outfile, "%s, %s, %lf, %lf, %d, %d, %d, %d \n", data[i].patient, data[i].minute, data[i].calories, data[i].distance, data[i].floors, data[i].heartRate, data[i].steps, data[i].sleepLevel);
			}
		}

		else {
			printf("File Not Copied.");
		}
		
		
		fclose(outfile);
		return success;
	}