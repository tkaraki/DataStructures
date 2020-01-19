#pragma once

#include <fstream>
#include <sstream>
#include "List.h"

class Menu
{
public:

	int displayMenu();
	void menuManager();

	void import();
	void load();
	void store();
	void markAbsences();
	void generateReport();
	void edit();

private:
	List<Data> recordList;
};