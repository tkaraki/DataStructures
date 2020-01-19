#include "DietPlan.h"


//constructor 
DietPlan::DietPlan(int GoalDiet, string NameDiet, string DateDiet) {
	setGoalDiet(GoalDiet);
	mNameDiet = NameDiet;
	mDateDiet = DateDiet;
}

//copy constructor
DietPlan::DietPlan(const DietPlan &plan) {
	mGoalDiet = plan.getGoalDiet();
	mNameDiet = plan.getNameDiet();
	mDateDiet = plan.getDateDiet();
}

//destructor
DietPlan::~DietPlan(){}

//assignment operator
DietPlan & DietPlan::operator= (const DietPlan &rhs) {
	if (this != &rhs)
	{
		mGoalDiet = rhs.getGoalDiet();
		mNameDiet = rhs.getNameDiet();
		mDateDiet = rhs.getDateDiet();
	}

	return *this;

}



//setters and getters
void DietPlan::setGoalDiet(int newGoal) {
	
	// data validation
	if (newGoal < 0)
	{
		mGoalDiet = 0;
	}
	else
	{
		mGoalDiet = newGoal;
	}
}

void DietPlan::setNameDiet(string newName) {
	mNameDiet = newName;
}

void DietPlan::setDateDiet(string newDate) {
	mDateDiet = newDate;
}

int DietPlan::getGoalDiet() const {
	return mGoalDiet;
}

string DietPlan::getNameDiet() const {
	return mNameDiet;
}

string DietPlan::getDateDiet() const {
	return mDateDiet;
}



//change goal in plan
void DietPlan::editGoal() {

	cout << "Do you want to change the diet calories goal?" << endl;
	cout << " \t1. Yes" << endl << " \t2. No" << endl;
	int selection = 0;

	//input validation
	do {
		cout << "Enter the corresponding number:";
		cin >> selection;

		if ((selection > 2) || (selection < 1))
		{
			cout << "Invalid selection. Try again." << endl;
		}

	} while ((selection > 2) || (selection < 1));

	//change goal
	if (selection == 1) {

		int newGoal = 0;
		int oldGoal = getGoalDiet();

	//input validation
	do {
		cout << "Enter new goal:";
		cin >> newGoal;

		if (newGoal < 0)
		{
			cout << "Calories cannot be negative. Try again." << endl;
		}

	} while (newGoal < 0);

	//confirm change
	setGoalDiet(newGoal);
	cout << "Diet plan calories goal changed from " << oldGoal << " to " << newGoal << endl;
	}
	
	else {
		cout << "No changes made." << endl;
	}

}

//change date in plan
void DietPlan::editDate() {
	
	cout << "Do you want to change the diet plan date?" << endl;
	cout << " \t1. Yes" << endl << " \t2. No" << endl;
	int selection = 0;

	//input validation
	do {
		cout << "Enter the corresponding number:";
		cin >> selection;

		if ((selection > 2) || (selection < 1))
		{
			cout << "Invalid selection. Try again." << endl;
		}

	} while ((selection > 2) || (selection < 1));

	//change date
	if (selection == 1) {
		int day = 0, month = 0, year = 0;

		//input validation
		do {
			cout << "Enter new day:";
			cin >> day;

			if ((day < 0) || (day > 31))
			{
				cout << "Invalid day. Try again." << endl;
			}

		} while ((day < 0) || (day > 31));

		//input validation
		do {
			cout << "Enter new month:";
			cin >> month;

			if ((month < 0) || (month > 12))
			{
				cout << "Invalid month. Try again." << endl;
			}

		} while ((month < 0) || (month > 12));

		//input validation
		do {
			cout << "Enter new year:";
			cin >> year;

			if ((year < 0) || (year > 2070))
			{
				cout << "Year must be less than 2070, since you'll be dead by then. Try again." << endl;
			}

		} while ((year < 0) || (year > 2070));

		//confirm change
		string newDate = std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
		cout << "Exercise plan date changed from " << getDateDiet() << " to " << newDate << endl;
		setDateDiet(newDate);
	}

	else {
		cout << "No changes made." << endl;
	}
	
}

//change plan name
void DietPlan::editName() {

	cout << "Do you want to change the diet plan name?" << endl;
	cout << " \t1. Yes" << endl << " \t2. No" << endl;
	int selection = 0;

	//input validation
	do {
		cout << "Enter the corresponding number:";
		cin >> selection;

		if ((selection > 2) || (selection < 1))
		{
			cout << "Invalid selection. Try again." << endl;
		}

	} while ((selection > 2) || (selection < 1));

	//change name
	if (selection == 1) {

		char newName [100];

		//input 
		cout << "Enter new plan name:";
		cin >> newName;

		//confirm change
		cout << "Diet plan name changed from " << getGoalDiet() << " to " << newName << endl;
		setNameDiet(newName);
	}

	else {
		cout << "No changes made." << endl;
	}
	

}




//overloaded operators

//prints plan
std::ostream &operator<< (std::ostream &lhs, const DietPlan &rhs)
{
	lhs << "Name: " << rhs.getNameDiet() << endl
		<< "Goal: " << rhs.getGoalDiet() << endl
		<< "Date: " << rhs.getDateDiet();

	return lhs;
}

//writes plan to file
std::fstream &operator<< (std::fstream &lhs, const DietPlan &rhs) {

	lhs << rhs.getNameDiet() << endl
		<< rhs.getGoalDiet() << endl
		<< rhs.getDateDiet() << endl << endl;

	return lhs;

}

//reads plan from file
std::fstream &operator>> (std::fstream &lhs, DietPlan &rhs)
{
	string name, date, emptyLine;
	int goal;

	getline(lhs, name);
	rhs.setNameDiet(name);

	lhs >> goal;
	rhs.setGoalDiet(goal);

	getline(lhs, emptyLine);

	getline(lhs, date);
	rhs.setDateDiet(date);

	getline(lhs, emptyLine);

	return lhs;
}