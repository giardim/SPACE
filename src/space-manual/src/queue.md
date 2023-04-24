# Queue

This is how you use space::sout() to visualize queues. 

	#include <iostream>
	#include <queue>

	// include the space.hpp file
	#include "space.hpp"

	int main(void)
	{
		// initialize a queue of ints
		std::queue<int> int_queue;

		// push some elements to the queue
		int_queue.push(4);
		int_queue.push(2);
		int_queue.push(6);
		int_queue.push(9);
		int_queue.push(1);
		int_queue.push(3);

		// call space to save the queue to memeory
		space::sout("int_queue", int_queue);

	}

> space::sout("int_queue", int_queue);

This is how we call space::sout() when dealing with queues. 
All we need it the name of the data structure as a string, 
and the data structure itself.
