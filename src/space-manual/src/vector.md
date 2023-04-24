# Vector

This is how you use space::sout() to visualize vectors. 

	#include <iostream>
	#include <vector>

	// include the space.hpp file
	#include "space.hpp"

	int main(void)
	{
		// initialize a vector of ints
		std::vector<int> int_vector;

		// push_back some elements to the vector
		int_vector.push_back(4);
		int_vector.push_back(2);
		int_vector.push_back(6);
		int_vector.push_back(9);
		int_vector.push_back(1);
		int_vector.push_back(3);

		// call space to save the vector to memeory
		space::sout("int_vector", int_vector);

	}

> space::sout("int_vector", int_vector);

This is how we call space::sout() when dealing with vectors. 
All we need it the name of the data structure as a string, 
and the data structure itself.
