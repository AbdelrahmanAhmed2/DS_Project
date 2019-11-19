#pragma once

#include "..\Defs.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"

#include "..\Generic_DS\LinkedList.h"
#include "..\Generic_DS\PriorityQueue.h"
#include "Order.h"
#include "Cook.h"
#include <fstream>
#include <string>
#include <string.h>

// it is the maestro of the project
class Restaurant  
{	
private:
	GUI *pGUI; 
	Queue<Event*> EventsQueue;	     //Queue of all events that will be loaded from file
	
	// Orders -------------------
	LinkedList<Order*> Norm_Ord;
	Queue<Order*> Veg_Ord;
	PriorityQueue<Order*> VIP_Ord;

	// Cooks --------------------
	PriorityQueue<Cook*> Norm_Cook;
	PriorityQueue<Cook*> Veg_Cook;
	PriorityQueue<Cook*> VIP_Cook;



	//
	// TODO: Add More Data Members As Needed
	//


public:
	
	Restaurant();
	~Restaurant();
	
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	
	void RunSimulation();
	void FillDrawingList();

	void AddOrders(Order* ord);

	//
	// TODO: Add More Member Functions As Needed
	//

};
