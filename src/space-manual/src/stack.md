# Stack

This is how you use space::sout() to visualize stacks. 

	#include <iostream>
	#include <stack>

	// include the space.hpp file
	#include "space.hpp"

	int main(void)
	{
		// initialize a stack of ints
		std::stack<int> int_stack;

		// push some elements to the stack
		int_stack.push(4);
		int_stack.push(2);
		int_stack.push(6);
		int_stack.push(9);
		int_stack.push(1);
		int_stack.push(3);

		// call space to save the stack to memeory
		space::sout("int_stack", int_stack);

	}

> space::sout("int_stack", int_stack);

This is how we call space::sout() when dealing with stacks. 
All we need it the name of the data structure as a string, 
and the data structure itself.

