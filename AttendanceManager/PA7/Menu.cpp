#include "Menu.h"

using std::cin;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::istringstream;

int Menu::displayMenu()
{

	//output message

	cout << endl << endl << "_______________________________________________" << endl;
	cout << "           Course Attendance Manager         " << endl << endl;
	cout << "  Enter a selection from the menu below to run:" << endl;
	cout << " \t1. Import Course List" << endl<<endl;
	cout << " \t2. Load Master List" << endl << endl;
	cout << " \t3. Store Master List" << endl << endl;
	cout << " \t4. Mark Absences" << endl << endl;
	cout << " \t5. Edit List" << endl << endl;
	cout << " \t6. Generate Report" << endl << endl;
	cout << " \t7. Exit" << endl << endl;
	

	int selection; //menu selection

	//input validation
	do {
		cout << "Your selection:";
		cin >> selection;

		if ((selection > 7) || (selection < 1))
		{
			cout << "Invalid selection. Try again." << endl;
		}


	} while ((selection > 7) || (selection < 1));

	return selection;

}

void Menu::menuManager()
{

	bool isFinished = false;//exit menu condition 

	int userInput = 0;
	while (isFinished != true) {

		userInput = displayMenu();

		switch (userInput)
		{
		case 1:
			import();
			cout << endl << " \t Imported Course List" << endl;
			break;
		case 2:
			load();
			cout << endl << " \t Loaded Master List" << endl;
			break;
		case 3:
			store();
			cout << endl << " \t Stored Master List" << endl;
			break;
		case 4:
			markAbsences();
			cout << endl << " \t Marked all Absences" << endl;
			break;
		case 5:
			edit();
			break;
		case 6:
			generateReport();
			cout << endl << " \t Generated Report" << endl;
			break;
		case 7:
			cout << endl << " \t Exited Program." << endl;
			isFinished = true;
			exit(0);
		default:
			cout << endl << "Invalid selection." << endl;
			break;

		}

	}

}

void Menu::import()
{

	string recordNumber, idNumber, units;
	string firstname, lastname, fullname, email, major, level, garbage;

	ifstream infile;
	infile.open("classList.csv");
	if (infile.is_open())
	{
		getline(infile, garbage);

		while (!infile.eof())
		{
			//read file
			getline(infile, recordNumber, ',');
			getline(infile, idNumber, ',');
			getline(infile, garbage, '"');
			getline(infile, lastname, ',');
			getline(infile, firstname, '"');
			getline(infile, garbage, ',');
			getline(infile, email, ',');
			getline(infile, units, ',');
			getline(infile, major, ',');
			getline(infile, level);

			//load data
			fullname = firstname + " " + lastname;
			Data *student=new Data();
			student->setRecordNumber(atoi(recordNumber.c_str()));
			student->setIdNumber(atoi(idNumber.c_str()));
			student->setName(fullname);
			student->setEmail(email);
			student->setUnits(atoi(units.c_str()));
			student->setMajor(major);
			student->setLevel(level);

			recordList.insert(student);

		}

		infile.close();
	}
	else cout << "Unable to open file";
}

void Menu::load()
{
	int count = 0;
	ifstream infile;
	infile.open("master.txt");
	if (infile.is_open())
	{

		if (infile.peek() == std::ifstream::traits_type::eof())
		{
			cout << " File is empty. Record List was not changed." << endl;
		}

		else
		{
			recordList.~List(); //clear list

			string recordNumber, idNumber, units, absences;
			string firstname, lastname, fullname, email, major, level, garbage, absenceDates;


			while (count<11)
			{
				//read file
				getline(infile, recordNumber);
				getline(infile, idNumber);
				getline(infile, fullname);
				getline(infile, email);
				getline(infile, units);
				getline(infile, major);
				getline(infile, level);
				getline(infile, absences);
				getline(infile, absenceDates);


				//load data
				Data *student = new Data();
				student->setRecordNumber(atoi(recordNumber.c_str()));
				student->setIdNumber(atoi(idNumber.c_str()));
				student->setName(fullname);
				student->setEmail(email);
				student->setUnits(atoi(units.c_str()));
				student->setMajor(major);
				student->setLevel(level);
				student->setAbsences(atoi(absences.c_str()));


				istringstream ss(absenceDates);
				string splitDates;
				for (splitDates; ss >> splitDates; )
					student->getAbsenceDates()->push(splitDates);



				//start inserting back into cleared list
				recordList.insert(student);
				count++;

			}

		}
		infile.close();


	}
	else cout << "Unable to open file";
}

void Menu::store()
{

	ofstream outfile;
	outfile.open("master.txt");
	if (outfile.is_open())
	{
		Node<Data> *pTemp = recordList.getpHead();
		while (pTemp!=nullptr)
		{
			outfile << pTemp->getRecord()->getRecordNumber() << endl;
			outfile << pTemp->getRecord()->getIdNumber() << endl;
			outfile << pTemp->getRecord()->getName() << endl;
			outfile << pTemp->getRecord()->getEmail() << endl;
			outfile << pTemp->getRecord()->getUnits() << endl;
			outfile << pTemp->getRecord()->getMajor() << endl;
			outfile << pTemp->getRecord()->getLevel() << endl;
			outfile << pTemp->getRecord()->getAbsences() << endl;
			outfile << pTemp->getRecord()->getAbsenceDates()->printDates()<<endl;

			pTemp= pTemp->getpNext();

		}

		outfile.close();
	}
	else cout << "Unable to open file";
}

void Menu::markAbsences()
{
	int selection = 0;
	int absenceNum = 0;

	Node<Data> *pTemp = recordList.getpHead();


	cout <<endl<<endl<< "Mark Class Attendances" << endl;

	while (pTemp != nullptr)
	{
		do {
			cout << "__________________________" << endl;
			cout <<endl << pTemp->getRecord()->getName() << endl;
			cout << "\t1. Present" << endl;
			cout << "\t2. Absent" << endl << endl;
			cout << "Enter an option:";
			cin >> selection;

			if ((selection > 2) || (selection < 1))
			{
				cout << "Invalid selection. Try again." << endl;
			}

		} while ((selection > 2) || (selection < 1));
		
		if (selection == 2)
		{
			pTemp->getRecord()->getAbsenceDates()->addDates();//update stack
			absenceNum = pTemp->getRecord()->getAbsences() + 1;//increment absences #
			pTemp->getRecord()->setAbsences(absenceNum);//update data
		}

		pTemp = pTemp->getpNext();

	}
}

void Menu::generateReport()
{
	int selection = 0;
	
	do {
		cout<<endl << "1. All Students"<<endl;
		cout << "2. Absence Dates" << endl;
		cout << "\tEnter Report Option: ";
		
		cin >> selection;

		if ((selection > 2) || (selection < 1))
		{
			cout << "Invalid selection. Try again." << endl;
		}

	} while ((selection > 2) || (selection < 1));

	if (selection == 1)
	{
		ofstream outfile;
	    outfile.open("report.txt");
	
		if (outfile.is_open())
	{
		Node<Data> *pTemp = recordList.getpHead();
		while (pTemp != nullptr)
		{
			outfile << "Name: " << pTemp->getRecord()->getName() << endl;
			outfile << "Absences: " << pTemp->getRecord()->getAbsences() << endl;
			outfile << "Absence Dates: " << pTemp->getRecord()->getAbsenceDates()->peek()<< endl << endl;

			pTemp = pTemp->getpNext();

		}

		outfile.close();
	}
	
		else cout << "Unable to open file";

	}

	if (selection == 2)
	{
		
		do {
			cout << "\t\tEnter the number of absences:";
			cin >> selection;

		if ((selection > 50) || (selection < 0))
		
		{
			cout << "Invalid selection. Try again." << endl;
		}

	
		} while ((selection > 50) || (selection < 0));


	ofstream outfile;
	outfile.open("report.txt");

	if (outfile.is_open())
	{
		outfile << "Students absent for more than " << selection << " days:" << endl<<endl;

		Node<Data> *pTemp = recordList.getpHead();

		while (pTemp != nullptr)
		{
			if (selection < (pTemp->getRecord()->getAbsences()) )
			{

				outfile << "Name: " << pTemp->getRecord()->getName() << endl;
			
				outfile << "Absences: " << pTemp->getRecord()->getAbsences() << endl;
			}
			

			pTemp = pTemp->getpNext();

		}
		cout << " \t\t You chose a report for students absent greater than " << selection << " days." << endl;
		outfile.close();
	}

	else cout << "Unable to open file";

	}
	
}

void Menu::edit()
{
	int id;
	string name, name1, name2;
	int selection;
	string edit;
	int success = 0;

	Node<Data> *pTemp = recordList.getpHead();

	do{
	cout << endl << "1. Full Name" << endl;
	cout << "2. ID # " << endl;
	cout << "\tEnter Search Option: ";
	cin >> selection;

	if ((selection > 2) || (selection < 1))
	{
		cout << "Invalid selection. Try again." << endl;
	}


	} while ((selection > 2) || (selection < 1));

	if (selection == 1)
	{
		cout << endl<<"Enter Student's Full Name (eg: Kris Mort):";
		cin >> name1 >>name2;

		name = name1 + " " + name2;

		while (pTemp != nullptr)
		{
			if (pTemp->getRecord()->getName() == name)
			{
				cout<<" Absences Dates: "<< pTemp->getRecord()->getAbsenceDates()->printDates() << endl;
				cout << endl << "Enter a date from the list above you want to remove:";
				cin >> edit;

				pTemp->getRecord()->getAbsenceDates()->locateDate(edit);
				pTemp->getRecord()->decrementAbsences();
				success = 1;
				break;
			}

			pTemp = pTemp->getpNext();

		}
	}

	if (selection == 2)
	{
		cout << endl<< "Enter Student's Id #:";
		cin >> id;

		while (pTemp != nullptr)
		{
			if (pTemp->getRecord()->getIdNumber() == id)
			{
				cout << " Absences Dates: " << pTemp->getRecord()->getAbsenceDates()->printDates() << endl;
				cout << endl << "Enter a date from the list above you want to remove:";
				cin >> edit;


				pTemp->getRecord()->getAbsenceDates()->locateDate(edit);
				pTemp->getRecord()->decrementAbsences();
				success = 1;
				break;
			}

			pTemp = pTemp->getpNext();

		}
	}

	if (success==0)
	{
		cout << "Student Not Found." << endl;
	}
}