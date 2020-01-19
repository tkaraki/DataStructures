#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "ExercisePlan.h"
#include "DietPlan.h"



using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

//Wrapper class for ExercisePlan and DietPlan classes
class FitnessAppWrapper
{
public:

	//constructor
	FitnessAppWrapper();

	//destructor
	~FitnessAppWrapper();

	//menu drivers
	void runApplication(); // main application manager
	int displayMenu(); //menu options

	//Diet menu functions
	void loadDailyDietPlan(fstream &dietPlanFile, DietPlan &plan);//read a daily plan from file to object
	void loadWeeklyDietPlan(fstream &dietPlanFile, DietPlan weeklyPlan[]);//read weekly plan from file to array
	void storeDailyDietPlan(fstream &dietPlanFile, DietPlan &plan);//write daily plan to file
	void storeWeeklyDietPlan(fstream &dietPlanFile);//write weekly plan to file
	void displayDailyDietPlan(DietPlan &day) const;//print daily plan
	void displayWeeklyDietPlan() const;//print weekly plan
	int editDietPlan();//edit plan
	
	//Exercise menu functions
	void loadDailyExercisePlan(fstream &exercisePlanFile, ExercisePlan &plan);//read a daily plan from file to object
	void loadWeeklyExercisePlan(fstream &exercisePlanFile, ExercisePlan weeklyPlan[]);//read weekly plan from file to array
	void storeDailyExercisePlan(fstream &exercisePlanFile, ExercisePlan &plan);//write daily plan to Diet
	void storeWeeklyExercisePlan(fstream &exercisePlanFile);//write weekly plan to file
	void displayDailyExercisePlan(ExercisePlan &day) const;//print daily plan
	void displayWeeklyExercisePlan() const;//print weekly plan
	int editExercisePlan();//edit plan
	

private: 
	DietPlan *dietPlanptr; 
	ExercisePlan *exercisePlanptr;
	fstream dietPlanFile;
	fstream exercisePlanFile;
	
};
