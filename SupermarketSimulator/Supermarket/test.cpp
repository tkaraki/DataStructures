
#include "test.h"

void Test::testEnqueueEmpty()
{
	Queue t;

	bool success = false;

	Data *d= new Data(1, 1, 1);//data
	int l = 1;//list items

	success = t.enqueue(d,1);

	if (success)
	{
		cout << "testEnqueueEmpty= success" <<endl;
	}
	
	else
	{
		cout << "testEnqueueEmpty= not success" << endl;
	}

}

void Test::testEnqueueOneNode()
{
	Queue t;

	bool success = false;

	Data *d= new Data(1, 1, 1);//data
	int l = 1;//list items

	t.enqueue(d, 1);//empty
	success= t.enqueue(d, 1);//not empty anymore 

	if (success)
	{
		cout << "testEnqueueOneNode= success" << endl;
	}

	else
	{
		cout << "testEnqueueOneNode= not success" << endl;
	}
}

void Test::testDequeueOneNode()
{
	Queue t;

	bool success = false;

	Data *d= new Data(1, 1, 1);//data
	int l = 1;//list items

	t.enqueue(d, 1);//one node
	success = t.dequeue();

	if (success)
	{
		cout << "testDequeueOneNode= success" << endl;
	}

	else
	{
		cout << "testDequeueOneNode= not success" << endl;
	}
}

void Test::testDequeueTwoNode()
{
	Queue t;

	bool success = false;

	Data *d= new Data(1, 1, 1);//data
	int l = 1;//list items

	t.enqueue(d, 1);//one node
	t.enqueue(d, 1);//two node
	success = t.dequeue();

	if (success)
	{
		cout << "testDequeueTwoNode= success" << endl;
	}

	else
	{
		cout << "testDequeueTwoNode= not success" << endl;
	}
}

void Test::testSimulation24()
{
	Simulation m;

	bool success = false;

	success = m.run_simulation(24*60);

	if (success)
	{
		cout << "testSimulation24= success" << endl;
	}

	else
	{
		cout << "testSimulation24= not success" << endl;
	}
}