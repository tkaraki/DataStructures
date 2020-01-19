#include "ExercisePlan.h"


//constructor 
ExercisePlan::ExercisePlan(int GoalExercise, string NameExercise, string DateExercise) {
	setGoalExercise(GoalExercise);
	mNameExercise = NameExercise;
	mDateExercise = DateExercise;
}

//copy constructor
ExercisePlan::ExercisePlan(const ExercisePlan &plan) {
	mGoalExercise = plan.getGoalExercise();
	mNameExercise = plan.getNameExercise();
	mDateExercise = plan.getDateExercise();
}

//destructor
ExercisePlan::~ExercisePlan() {}

//assignment operator
ExercisePlan & ExercisePlan::operator= (const ExercisePlan &rhs) {
	if (this != &rhs)
	{
		mGoalExercise = rhs.getGoalExercise();
		mNameExercise = rhs.getNameExercise();
		mDateExercise = rhs.getDateExercise();
	}

	return *this;

}



//setters and getters
void ExercisePlan::setGoalExercise(int newGoal) {

	// data validation
	if (newGoal < 0)
	{
		mGoalExercise = 0;
	}
	else
	{
		mGoalExercise = newGoal;
	}
}

void ExercisePlan::setNameExercise(string newName) {
	mNameExercise = newName;
}

void ExercisePlan::setDateExercise(string newDate) {
	mDateExercise = newDate;
}

int ExercisePlan::getGoalExercise() const {
	return mGoalExercise;
}

string ExercisePlan::getNameExercise() const {
	return mNameExercise;
}

string ExercisePlan::getDateExercise() const {
	return mDateExercise;
}



//change goal in plan
void ExercisePlan::editGoal() {
	cout << "Do you want to change the exercise steps goal?" << endl;
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
		int oldGoal = getGoalExercise();

		//input validation
		do {
			cout << "Enter new goal:";
			cin >> newGoal;

			if (newGoal < 0)
			{
				cout << "Steps cannot be negative. Try again." << endl;
			}

		} while (newGoal < 0);

		//confirm change
		setGoalExercise(newGoal);
		cout << "Exercise plan steps goal changed from " << oldGoal << " to " << newGoal << endl;
	}

	else {
		cout << "No changes made." << endl;
	}
	
	
}

//change date in plan
void ExercisePlan::editDate() {
	cout << "Do you want to change the exercise plan date?" << endl;
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
		int day = 0, month=0, year=0;

	//input validation
	do {
		cout << "Enter new day:";
		cin >> day;

		if ((day < 0)||(day>31))
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
	string newDate = std::to_string(month) +"/" + std::to_string(day) +"/" + std::to_string(year);
	cout << "Exercise plan date changed from " << getDateExercise() << " to " << newDate << endl;
	setDateExercise(newDate);

	}
	
	else {
		cout << "No changes made." << endl;
	}
}

//change plan name
void ExercisePlan::editName(){
	cout << "Do you want to change the exercise plan name?" << endl;
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

		char newName[100];

	//input 
	cout << "Enter new plan name:";
	cin >> newName;

	//confirm change
	cout << "Exercise plan name changed from " << getNameExercise() << " to " << newName << endl;
	setNameExercise(newName);
	}

	else {
		cout << "No changes made."<<endl;
	}
	

}



//overloaded operators

//prints plan
std::ostream & operator<< (std::ostream &lhs, const ExercisePlan &rhs)
{
	lhs << "Name: " << rhs.getNameExercise() << endl 
		<< "Goal: " << rhs.getGoalExercise() << endl
		<< "Date: " << rhs.getDateExercise();

	return lhs;
}

//writes plan to file
std::fstream & operator<< (std::fstream &lhs, const ExercisePlan &rhs) {
	
	lhs << rhs.getNameExercise() << endl
		<< rhs.getGoalExercise() << endl
		<< rhs.getDateExercise() << endl << endl;

	return lhs;

}

//reads plan from file
std::fstream & operator>> (std::fstream &lhs, ExercisePlan &rhs)
{
	string name,date,emptyLine;
	int goal;

	getline(lhs, name);
	rhs.setNameExercise(name);

	lhs >> goal;
	rhs.setGoalExercise(goal);

	getline(lhs, emptyLine);

	getline(lhs, date);
	rhs.setDateExercise(date);
	
	getline(lhs, emptyLine);

	return lhs;
}
