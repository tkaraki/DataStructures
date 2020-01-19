/*******************************************************************************                                        *
 * Date:  2/11/2019                                                                     *
 *                                                                             *
 * Description: FITBIT Data
 ******************************************************************************/


#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>  
#include <string.h>
#include <stdlib.h> 


typedef enum sleep{ NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3} Sleep;


typedef struct fitbit {
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;


int readFile(FitbitData data[1440]);

void sleepRange(FitbitData data [1440], int *start, int *end);
int stepsMax(FitbitData data[1440]);
unsigned int heartrateAverage(FitbitData data[1440]);
unsigned int stepsTotal(FitbitData data[1440]);
unsigned int floorsTotal(FitbitData data[1440]);
double distanceTotal(FitbitData data[1440]);
double caloriesTotal(FitbitData data[1440]);

int printFile(FitbitData data[1440], double calories, double distance, int floors, int steps, int stepsMx, int heartrateAvrg, int start, int end);


#endif