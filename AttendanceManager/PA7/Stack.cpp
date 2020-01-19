#include "Stack.h"

//constructor 
Stack::Stack()
{
	head = -1;
}


void Stack::push(string dt="")
{
	if (head >49)
	{
		cout << "List of Absences is Full." << endl;
	}

	else
	{
		if (dt == "")
		{
			date[++head] = getDate();
		}
		else
		{
			date[++head] = dt;
		}
		
	}

}

void Stack::pop()
{
	if (head < 0)
	{
		cout << "List of Absences is Empty."<<endl;
	}
	else
	{
		head--;
	}
}

string Stack::peek() const
{
	if (head < 0)
	{
		return "List of Absences is Empty.";
	}
	else
	{
		return date[head];
	}
}

bool Stack::isEmpty()
{
	return (head<0);
}

string Stack::getDate()
{
	int m = 0, d = 0, y = 0;
	string date = "";


	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);

	y = (now->tm_year + 1900);
	m = (now->tm_mon + 1);
	d = now->tm_mday;
	

	date= to_string(y) + "-" + to_string(m) + "-" + to_string(d);

	return date;
}

string Stack::printDates() const
{
	string dates = "";

	if (head < 0)
	{
		return dates;
	}
	else
	{
		for (int i = 0; i <= head; i++)
		{
			dates += date[i] + " ";
		}
		return dates;
	}
}

void Stack::addDates()
{
	push("");//push date onto stack

}

void Stack::reorderStack(int m)
{
	int k = head;
	while (m <= k)
	{
		date[m] = date[m + 1];
		m++;
	}

	head = head - 1;
	
}

void Stack::locateDate(string m)
{
	int n = 0;
	int success = 0;

	while (n <= head)
	{
		if (date[n] == m)
		{
			success = 1;
			break;
		}

		n++;
	}

	if (success == 1)
	{

		reorderStack(n);
		cout<<endl<<"Date was removed.";

	}

	else
	{
		cout << endl << "Date not found.";
	}

	
}

int Stack::getpHead()
{
	return head;
}