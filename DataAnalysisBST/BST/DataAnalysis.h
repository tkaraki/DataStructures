#pragma once

#include "BST.h"

#include <fstream>

class DataAnalysis
{
public:
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis();


private:
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;


	bool openCsv();
	void readLineCsv(int &units, string &data, string &type);
	void readFileCsv();
	int sortDataToBST(string type);
	void displayTrends();
	

};
