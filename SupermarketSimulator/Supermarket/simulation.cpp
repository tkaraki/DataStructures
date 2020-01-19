#include "Simulation.h"


int Simulation::start_simulation()
{
	int n = 0;

	cout << "          Supermarket Simulation         " << endl << endl;
	cout << "_________________________________________" << endl << endl << endl << endl;

	cout << "Enter the number of minutes:";

	do {
		cin >> n;
	} while (n < 0);

	cout << endl << endl;

	return n;
}

bool Simulation::run_simulation(int nMinutes)
{
	Queue express, normal;

	int timeElapsed = 0;

	int custNum = 1;

	//arrival of each customer to lanes
	int expressArrival = get_rand('e'); 
	int normalArrival = get_rand('n');

	//variable to store serviceTime of each customer that is enqueued
	int expressService = 0;
	int normalService = 0;

	//stores the total service times in each lines
	int expressTotalTime = 0;
	int normalTotalTime = 0;
	
	//stores the serviceTime of the customer at the head of the line. variable to be decremented.
	int expressServiceHEAD = -1;
	int normalServiceHEAD = -1;
	
	while (timeElapsed <= nMinutes )
	{
		//enter EXPRESS lane
			if (expressArrival==timeElapsed)//customer's arrival time is current time
			{
				//update date for new customer
				expressService = get_rand('e');

				expressTotalTime += expressService;
			    
				Data *expressCust = new Data(custNum,expressService,expressTotalTime);//create data object

				cout<<"Customer " <<custNum<< " has entered express lane. Arrival time: " <<expressArrival<<endl;
				express.enqueue(expressCust,expressService);//enqueue data object
				
				//update data for next customer
				custNum++;
				expressArrival = get_rand('e')+timeElapsed;

				//If express is empty set head customer's serviceTime to current customer
				if (expressServiceHEAD == -1)
				{
					expressServiceHEAD = express.getpHeadServTime();
					expressTotalTime -= expressServiceHEAD;
				}
			}
			


			//exit EXPRESS lane
			if (expressServiceHEAD == 0)// First/Head customer service time is done
			{
				//dequeue when line isnt empty
				if (express.isEmpty()==false) {
					cout << "Customer " << express.getpHeadCustNum() << " has left express lane. Total time: " << express.getpHeadTotalTime() << endl;
					express.dequeue();
					expressServiceHEAD = express.getpHeadServTime();//update to the next customer
					expressTotalTime -= expressServiceHEAD;
				}
				//set Head service to -1. variable will be updated after the next enqueue
				if (express.isEmpty()==true)
				{
					expressServiceHEAD= -1;
				}
				
			}
		
			//enter NORMAL lane
			if (normalArrival == timeElapsed)//customer's arrival time is current time
			{
				normalService = get_rand('n');

				normalTotalTime += normalService;
				Data *normalCust = new Data(custNum, normalService, normalTotalTime);//create data obj
				cout << "Customer " << custNum << " has entered normal lane. Arrival time: " << normalArrival << endl;
				normal.enqueue(normalCust, normalService);

				//update data for next customer
				custNum++;
				normalArrival = get_rand('n') + timeElapsed;

				//If express is empty set head customer's serviceTime to current customer
				if (normalServiceHEAD == -1)
				{
					normalServiceHEAD = normal.getpHeadServTime();
					normalTotalTime -= normalServiceHEAD;
				}
			}



			//exit NORMAL lane
			if (normalServiceHEAD == 0)// First/Head customer service time is done
			{
				//dequeue when line isnt empty
				if (normal.isEmpty() == false) {
					cout << "Customer " << normal.getpHeadCustNum() << " has left normal lane. Total time: " << normal.getpHeadTotalTime() << endl;
					normal.dequeue();
					normalServiceHEAD = normal.getpHeadServTime();//update to the next customer
					normalTotalTime -= normalServiceHEAD;
				}
				//set Head service to -1. variable will be updated after the next enqueue
				if (normal.isEmpty())
				{
					normalServiceHEAD = -1;
				}

			}


		//Customer Number after 24 hours should be reset to 1
		if ((timeElapsed % 1440) == 0 && timeElapsed != 0)
		{
			custNum = 1;
		}

		//For every 10 minutes, print out the entire queue for each line
		if ((timeElapsed % 10) == 0 && timeElapsed != 0)
		{
			cout << endl << endl;
			cout << "-------------------------------" << endl;
			cout << "Time is now:" << timeElapsed << endl;
			cout << "-------------------------------" << endl;
			cout<< "Express Lane:" << endl<<endl;
			express.printQueue();
			cout << "-------------------------------" << endl;
			cout << "Normal Lane:" << endl<<endl;
			normal.printQueue();
			cout << endl << endl;
		}
		
		if (expressServiceHEAD != -1)
		{
			expressServiceHEAD--;
		}
		
		if (normalServiceHEAD != -1)
		{
			normalServiceHEAD--;
		}

		timeElapsed++;
	}
	
	if (timeElapsed== (nMinutes-1))
		return true;
	else 
		return false;
}

int Simulation::get_rand(char lane)
{

	if (lane == 'e')
		return  (rand() % 5) + 1; 
	else if (lane == 'n')
		return  (rand() % 6) + 3;
}