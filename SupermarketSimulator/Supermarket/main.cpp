/*******************************************************************************                                           *
 * Date:  3/28/2019                                                                     *
 *                                                                             *
 * Description: Supermarket Simulation
 ******************************************************************************/


#include <iostream>
#include "Simulation.h"
#include "test.h"


int main()
{
	srand(time(NULL));
	
	/*Test t;
	t.testEnqueueEmpty();
	t.testEnqueueEmpty();
	t.testEnqueueOneNode();
	t.testDequeueOneNode();
	t.testDequeueTwoNode();
	t.testSimulation24();*/

	
	Simulation s;
	int m = s.start_simulation();
	s.run_simulation(m);


	return 0;
}

