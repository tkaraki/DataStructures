#pragma once

#include <iostream>
#include <string>
#include "Stack.h"

using std::string;
using std::cout;
using std::endl;

class Data
{
public:

	//constructor 
	Data();

	//setters and getters
	void setRecordNumber(int recordNumber);
	void setIdNumber(int idNumber);
	void setName(string name);
	void setEmail(string email);
	void setUnits(int units);
	void setMajor(string major);
	void setLevel(string level);
	void setAbsences(int absences);
	void setAbsenceDates(Stack *AbsenceDates);

	int getRecordNumber() ;
	int getIdNumber() ;
	string getName() ;
	string getEmail() ;
	int getUnits() ;
	string getMajor() ;
	string getLevel() ;
	int getAbsences();
	Stack *getAbsenceDates();

	void decrementAbsences();

private:
	int mRecordNumber;
	int mIdNumber;
	string mName;
	string mEmail;
	int mUnits;
	string mMajor;
	string mLevel;
	int mAbsences;
	Stack *mAbsenceDates;


};

