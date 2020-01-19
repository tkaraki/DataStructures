#pragma once

#include <iostream>
#include <fstream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::string;

class ExercisePlan
{
public:

	//constructor 
	ExercisePlan(int GoalExercise = 0, string NameExercise = "", string DateExercise = "");

	//copy constructor
	ExercisePlan(const ExercisePlan &plan);

	//destructor
	~ExercisePlan();

	//assignment operator
	ExercisePlan & operator= (const ExercisePlan &rhs);

	//setters and getters
	void setGoalExercise(int newGoal);
	void setNameExercise(string newName);
	void setDateExercise(string newDate);
	int getGoalExercise() const;
	string getNameExercise() const;
	string getDateExercise() const;

	//change plan attributes
	void editGoal();
	void editDate();
	void editName();

private:
	int mGoalExercise;
	string mNameExercise;
	string mDateExercise;
};

//overloaded stream operators
//prints plan
std::ostream & operator<< (std::ostream &lhs, const ExercisePlan &rhs);
//writes plan to file
std::fstream & operator<< (std::fstream &lhs, const ExercisePlan &rhs);
//reads plan from file
std::fstream & operator>> (std::fstream &lhs, ExercisePlan &rhs);