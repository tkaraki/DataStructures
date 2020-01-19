#include "Data.h"


//constructor 
Data::Data(int custNumber, int servTime, int totTime) {
	this->customerNumber = custNumber;
	this->serviceTime = servTime;
	this->totalTime = totTime;
}

//copy constructor
Data::Data(const Data &dataset) {
	customerNumber = dataset.getCustomerNumber();
	serviceTime = dataset.getServiceTime();
	totalTime = dataset.getTotalTime();
}

//destructor
Data::~Data() {}

//assignment operator
Data & Data::operator= (const Data &rhs) {
	if (this != &rhs)
	{
		customerNumber = rhs.getCustomerNumber();
		serviceTime = rhs.getServiceTime();
		totalTime = rhs.getTotalTime();
	}

	return *this;

}



//setters and getters
void Data::setCustomerNumber(int custNumber) 
{
		this->customerNumber = custNumber;
}

void Data::setServiceTime(int servTime)
{
	this->serviceTime = servTime;
}

void Data::setTotalTime(int totTime) 
{
	this->totalTime = totTime;
}

int Data::getCustomerNumber() const {
	return customerNumber;
}

int Data::getServiceTime() const {
	return serviceTime;
}

int Data::getTotalTime() const {
	return totalTime;
}

