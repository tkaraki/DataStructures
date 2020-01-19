#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{
	this->mTreePurchased = BST();
	this->mTreeSold = BST();
	
}

DataAnalysis::~DataAnalysis()
{
	this->mTreePurchased.~BST();
	this->mTreeSold.~BST();
}

void DataAnalysis::runAnalysis()
{
	bool success = openCsv();

	if (success == true)
	{
		readFileCsv();
		displayTrends();
	}
}

bool DataAnalysis::openCsv()
{
	bool isOpen = false;

	this->mCsvStream.open("data.csv");

	if (mCsvStream.is_open())
	{
		isOpen = true;
	}
	else
	{
		cout << "Unable to open file." << endl;
	}

	return isOpen;
		
}

void DataAnalysis::readLineCsv(int &Funits, string &Fdata, string &Ftype)
{
	string typeFile="", dataFile="", unitsFile="";

	//read line
	getline(this->mCsvStream, unitsFile, ',');
	getline(this->mCsvStream, dataFile, ',');
	getline(this->mCsvStream, typeFile);
	

	//split data
	Funits=(atoi(unitsFile.c_str()));
	Fdata = dataFile;
	Ftype = typeFile;
}

void DataAnalysis::readFileCsv()
{
	//A function that loops until all lines are read from the file; 
	//calls the function below, and then displays the current contents of both BSTs; 
	//use inOrderTraversal () to display the trees
	
	string data="", type="", garbage="";
	int units=0;

	getline(this->mCsvStream, garbage); //skip first line

	while (!mCsvStream.eof()) 
	{

		readLineCsv(units, data, type);

		int treeType = sortDataToBST(type);
		
		if (treeType == 1)
		{
			this->mTreePurchased.insert(data, units);
		}

		else if (treeType == 2)
		{
			this->mTreeSold.insert(data, units);
		}

	}

	mCsvStream.close();

	cout << "      Purchased "; 
	mTreePurchased.inOrderTraversal();
	cout << endl;

	cout << "      Sold ";
	mTreeSold.inOrderTraversal();
	cout << endl;

}

int DataAnalysis::sortDataToBST(string type)
{
	int tree = 0; 

	if (type == "Purchased")
	{
		tree = 1;
	}
	else if (type == "Sold")
	{
		tree = 2;
	}

	return tree;
}

void DataAnalysis::displayTrends()
{
	cout << "       Data Analysis Trends:" << endl<<endl;

	cout << "Most Purchased:" << endl;
	this->mTreePurchased.findLargest().printData();

	cout << "Least Purchased:" << endl;
	this->mTreePurchased.findSmallest().printData();

	cout << "Most Sold:" << endl;
	this->mTreeSold.findLargest().printData();

	cout << "Least Sold:" << endl;
	this->mTreeSold.findSmallest().printData();

}