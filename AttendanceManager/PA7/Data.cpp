#include "Data.h"

//ructor 


Data::Data()
{
	mRecordNumber = 0;
	mIdNumber = 0;
	mName = "";
	mEmail = "";
	mUnits = 0;
	mMajor = "";
	mLevel = "";
	mAbsences = 0;
    mAbsenceDates= new Stack();

}


//setters and getters
void Data::setRecordNumber(int recordNumber)
{
	mRecordNumber = recordNumber;
}

void Data::setIdNumber(int idNumber)
{
	mIdNumber = idNumber;
}

void Data::setName(string name)
{
	mName = name;
}

void Data::setEmail(string email)
{
	mEmail = email;
}

void Data::setUnits(int units)
{
	mUnits = units;
}

void Data::setMajor(string major)
{
	mMajor = major;
}

void Data::setLevel(string level)
{
	mLevel = level;
}

void Data::setAbsences(int absences)
{
	mAbsences = absences;
}

void Data::setAbsenceDates(Stack *pAbsenceDates)
{
	mAbsenceDates = pAbsenceDates;
}

int Data::getRecordNumber() 
{
	return mRecordNumber;
}

int Data::getIdNumber() 
{
	return mIdNumber;
}

string Data::getName() 
{
	return mName;
}

string Data::getEmail() 
{
	return mEmail;
}

int Data::getUnits() 
{
	return mUnits;
}

string Data::getMajor() 
{
	return mMajor;
}

string Data::getLevel() 
{
	return mLevel;
}

int Data::getAbsences()
{
	return mAbsences;
}

Stack *Data::getAbsenceDates()
{
	return mAbsenceDates;
}

void Data::decrementAbsences()
{
	int m = mAbsenceDates->getpHead();
	setAbsences(m+1);
}