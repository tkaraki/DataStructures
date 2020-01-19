#pragma once


#include <iostream>


using std::cin;
using std::cout;
using std::endl;

class Data
{
public:

	//constructor 
	Data(int custNumber = 0, int servTime = 0, int totTime = 0);

	//copy constructor
	Data(const Data &dataset);

	//destructor
	~Data();

	//assignment operator
	Data & operator= (const Data &rhs);

	//setters and getters
	void setCustomerNumber(int custNumber);
	void setServiceTime(int servTime);
	void setTotalTime(int totTime);

	int getCustomerNumber() const;
	int getServiceTime() const;
	int getTotalTime() const;


private:
	int customerNumber;
	int serviceTime;
	int totalTime;
};
