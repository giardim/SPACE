# Saving Indicies

To make our visualizer even better at showing us what our program is doing, 
we are going to tell it the indicies of the sorting algorithm at every 
step.

### What are indicies?

The word indicies is the plural of the word index. An index is a number that 
uniquely identifies an element in an array. For example in the array 

	example_array[3] = {22, 33, 44};

22 has an index of 0, 33 has an index of 1, and 44 has an index of 2.
So if we want to get see what the first element of this array is, we cant 
do

	std::cout << example_array[0];

And we will get 22 as the output.

### How do we use indicies

In our bubble sort program, we compare two elements in the array to see if 
they are in the correct order. The two elements we compare are always next 
to each other. So if we are comparing the element at index 5, then we must 
be comparing it with the element at index 6. We can represent this 
relationship with variables like this: we are always comparing j with j+1. 

SPACE can save the indicies you are comparing in addition to the data 
structure. Take a look at the example code to see how we do this.


	#include <iostream>
	#include <algorithm>

	// First, we need to include space.hpp
	#include "space.hpp"

	int main() {

		int size = 12
	    int my_array[size] = {7, 4, 2, 1, 15, 3, 6, 11, 18, 13, 12, 5};

	    // Save the initial state of the array
	    space::sout("my_array", my_array, size);

	    // Bubble sort algorithm
	    for (int i = 0; i < size - 1; i++) {
	        for (int j = 0; j < size - i - 1; j++) {

				/* Hey look! There are two new arguements being passed
				 * to the space::sout() function after size.
				 * j and j+1 are the two indicies of the array that the 
				 *  bubble sort is comparing.
				 */
				space::sout("my_array", my_array, size, j, j+1);
	        
	            if (my_array[j] > my_array[j + 1]) {
	            
	                // Swap elements using std::swap
	                std::swap(my_array[j], my_array[j + 1]);

	                // Every time there is a swap, save the array again
				space::sout("my_array", my_array, size, j, j+1);
	                
	            }
	        }
	    }

	    // Save the final state of the array
		space::sout("my_array", my_array, size, j, j+1);

	    return 0;
	}

Lets break down how we call space::sout() to save the data structure 
*and* the indicies of the sorting algorithm.

> space::sout("my_array", my_array, size, j, j+1);

The indicies j and j+1 are passed as arguements into the function after 
size. The order of arguements matters when using SPACE, so check the 
[space::sout()](space-sout.md) documentation to make sure you use it 
correctly.

