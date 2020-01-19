#include "FitnessAppWrapper.h"

//constructor
FitnessAppWrapper::FitnessAppWrapper() {
	
	fstream dietPlanFile("dietPlans.txt");
	fstream exercisePlanFile("dietPlans.txt");
	dietPlanptr = new DietPlan[7];
	exercisePlanptr = new ExercisePlan[7];

}

//destructor
FitnessAppWrapper::~FitnessAppWrapper() {
	delete[] dietPlanptr;
	delete[] exercisePlanptr;
}


//*** Menu functions***

//run main application
void FitnessAppWrapper::runApplication() {
	bool isFinished = false;//exit menu condition 
	int choice=0, dayExercise = 0, dayDiet = 0;
	while (isFinished != true) {
		choice = displayMenu();
		switch (choice)
		{
		case 1: 
			loadWeeklyDietPlan(dietPlanFile, dietPlanptr);
			cout << " \t Succesfully Loaded Weekly Diet Plan" << endl;
			break;
		case 2:
			loadWeeklyExercisePlan(exercisePlanFile, exercisePlanptr);
			cout << " \t Succesfully Loaded Weekly Exercise Plan" << endl;
			break;
		case 3:
			storeWeeklyDietPlan(dietPlanFile);
			cout << " \t Succesfully Stored Weekly Diet Plan" << endl;
			break;
		case 4:
			storeWeeklyExercisePlan(exercisePlanFile);
			cout << " \t Succesfully Stored Weekly Exercise Plan" << endl;
			break;
		case 5:
			cout <<endl<< " \t Weekly Diet Plan:" << endl;
			displayWeeklyDietPlan();
			break;
		case 6:
			cout <<endl<< " \t Weekly Exercise Plan:" << endl;
			displayWeeklyExercisePlan();
			break;
		case 7:
			dayDiet = editDietPlan();
			dietPlanptr[dayDiet - 1].editDate();
			dietPlanptr[dayDiet - 1].editGoal();
			dietPlanptr[dayDiet - 1].editName();
			cout << endl << " \t Succesfully Edited Diet Plan Day:" << dayDiet << endl;
			displayDailyDietPlan(dietPlanptr[dayDiet - 1]);
			break;
		case 8:
			dayExercise = editExercisePlan();
			exercisePlanptr[dayExercise - 1].editDate();
			exercisePlanptr[dayExercise - 1].editGoal();
			exercisePlanptr[dayExercise - 1].editName();
			cout << endl<< " \t Succesfully Edited Exercise Plan Day:" << dayExercise <<endl;
			displayDailyExercisePlan(exercisePlanptr[dayExercise - 1]);
			break;
		case 9:
			storeWeeklyDietPlan(dietPlanFile);
			storeWeeklyExercisePlan(exercisePlanFile);
			cout << endl << " \t Succesfully Exited and Saved Basic Fitness Application." << endl;
			isFinished = true;
			exit(0); 
		default:
			cout << "Invalid selection." << endl;
			break;
		
		}

	}
}

//menu manager
int FitnessAppWrapper::displayMenu() {

	//output message

	cout <<endl<<endl<< "_______________________________________________" << endl;
	cout << "           Basic Fitness Application      " << endl << endl;
	cout << "  Enter a selection from the menu below to run:" << endl;
	cout << " \t1. Load Weekly Diet Plan" << endl;
	cout << " \t2. Load Weekly Exercise Plan" << endl<<endl;
	cout << " \t3. Store Weekly Diet Plan" << endl;
	cout << " \t4. Store Weekly Exercise Plan" << endl<<endl;
	cout << " \t5. Display Weekly Diet Plan" << endl;
	cout << " \t6. Display Weekly Exercise Plan" << endl << endl;;
	cout << " \t7. Edit Daily Diet Plan" << endl;
	cout << " \t8. Edit Daily Exercise Plan" << endl<<endl;
	cout << " \t9. Exit Menu" << endl << endl;
	
	int selection; //menu selection

	//input validation
	do {
		cout << "Your selection:";
		cin >> selection;
		
		if ((selection > 9) || (selection < 1))
		{cout << "Invalid selection. Try again." << endl; }


	} while ((selection > 9) || (selection < 1)); 

		return selection;
}



//***Diet menu functions***

//read a daily plan from file to object
void FitnessAppWrapper::loadDailyDietPlan(fstream &dietPlanFile, DietPlan &plan) {
	dietPlanFile >> plan; //overloaded ifstream operator
}

//read weekly plan from file to array
void FitnessAppWrapper::loadWeeklyDietPlan(fstream &dietPlanFile, DietPlan weeklyPlan[]) {
	dietPlanFile.open("dietPlans.txt"); 
	for (int i = 0; i < 7; i++) {
		loadDailyDietPlan(dietPlanFile,weeklyPlan[i]);
	}
	dietPlanFile.close();
}

//write daily plan to file
void FitnessAppWrapper::storeDailyDietPlan(fstream &dietPlanFile, DietPlan &plan) {
	dietPlanFile << plan; //overloaded ofstream operator
}

//write weekly plan to file
void FitnessAppWrapper::storeWeeklyDietPlan(fstream &dietPlanFile){
	dietPlanFile.open("dietPlans.txt");
	for (int i = 0; i < 7; i++) {
		storeDailyDietPlan(dietPlanFile, this->dietPlanptr[i]);
	}
	dietPlanFile.close();
}

//print daily plan
void FitnessAppWrapper::displayDailyDietPlan(DietPlan &day) const {
	cout << day << endl; //overloaded ostream operator
}

//print weekly plan
void FitnessAppWrapper::displayWeeklyDietPlan() const {
	for (int i = 0; i < 7; i++) 
		displayDailyDietPlan(this->dietPlanptr[i]);
}

//edit plan
int FitnessAppWrapper::editDietPlan() {
	int day = 0;

	do {
		cout << "Enter which day of the plan you want to edit (1-7):";
		cin >> day;
	} while ((day <1) || (day >7));

	return day;
}



//***Exercise menu functions***

//read a daily plan from file to object
void FitnessAppWrapper::loadDailyExercisePlan(fstream &exercisePlanFile, ExercisePlan &plan) {
	exercisePlanFile >> plan; //overloaded ifstream operator
}

//read weekly plan from file to array
void FitnessAppWrapper::loadWeeklyExercisePlan(fstream &exercisePlanFile, ExercisePlan weeklyPlan[]) {
	exercisePlanFile.open("exercisePlans.txt");
	for (int i = 0; i < 7; i++) {
		loadDailyExercisePlan(exercisePlanFile, weeklyPlan[i]);
	}
	exercisePlanFile.close();
}

//write daily plan to Diet
void FitnessAppWrapper::storeDailyExercisePlan(fstream &exercisePlanFile, ExercisePlan &plan){
	exercisePlanFile << plan; //overloaded ofstream operator
}

//write weekly plan to file
void FitnessAppWrapper::storeWeeklyExercisePlan(fstream &exercisePlanFile) {
	exercisePlanFile.open("exercisePlans.txt");
	for (int i = 0; i < 7; i++) {
		storeDailyExercisePlan(exercisePlanFile, this->exercisePlanptr[i]);
	}
	exercisePlanFile.close();
}

//print daily plan
void FitnessAppWrapper::displayDailyExercisePlan(ExercisePlan &day) const {
	cout << day << endl; //overloaded ostream operator
}

//print weekly plan
void FitnessAppWrapper::displayWeeklyExercisePlan() const {
	for (int i = 0; i < 7; i++)
		displayDailyExercisePlan(this->exercisePlanptr[i]);
}

//edit plan
int FitnessAppWrapper::editExercisePlan() {
	int day = 0;

	do {
		cout << "Enter which day of the plan you want to edit (1-7):";
		cin >> day;
	} while ((day < 1) || (day > 7));

	return day;
}
