#pragma once

#include <iostream>
#include <fstream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::string;

class DietPlan
{
public:
	
	//constructor 
	DietPlan(int GoalDiet = 0, string NameDiet = "", string DateDiet = "");

	//copy constructor
	DietPlan(const DietPlan &plan); 

	//destructor
	~DietPlan();

	//assignment operator
	DietPlan & operator= (const DietPlan &rhs);

	//setters and getters
	void setGoalDiet(int newGoal);
	void setNameDiet(string newName);
	void setDateDiet(string newDate);
	int getGoalDiet() const;
	string getNameDiet() const;
	string getDateDiet() const;

	//change plan attributes
	void editGoal();
	void editDate();
	void editName();

private:
	int mGoalDiet;
	string mNameDiet;
	string mDateDiet;
};

//overloaded stream operators
//prints plan
std::ostream & operator<< (std::ostream &lhs, const DietPlan &rhs);
//writes plan to file
std::fstream & operator<< (std::fstream &lhs, const DietPlan &rhs);
//reads plan from file
std::fstream & operator>> (std::fstream &lhs, DietPlan &rhs);