#include "Header.h"

int main() {

	FitbitData data[1440];
	int filereader=readFile(data);

	if (filereader == 0) {
		
		printf_s("File Read\n");

		double calories, distance;
		int floors, steps, stepsMx, heartrateAvrg; 
		int start=0, end=0;

		calories=caloriesTotal(data);
		distance = distanceTotal(data);
		floors=floorsTotal(data);
		steps=stepsTotal(data);
		stepsMx=stepsMax(data);
		heartrateAvrg=heartrateAverage(data);
		sleepRange(data, &start, &end);
		
		int fileCopier= printFile(data, calories, distance, floors, steps, stepsMx, heartrateAvrg, start, end);

		if (fileCopier == 1) {
			printf_s("File Copied\n");
		}

		else if (fileCopier == 0) {
			printf_s("File Not Copied");
		}

	}
	
	else {
		printf_s("File Not Read");
	}

	

	return 0;
}