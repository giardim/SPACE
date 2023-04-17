# Saving Indicies

To make our visualizer even better at showing us what our program is doing, 
we are going to tell it the indicies of the sorting algorithm at every 
step.

### What are indicies?

Indicies are the values that contain the index of the item that you are 
looking at. **Add a better explanation here**

	#include <iostream>
	#include <algorithm>

	// First, we need to include space.hpp
	#include "space.hpp"

	int main() {
		// Its a good idea to save the size of the array in a variable to 
		// make your code easier to read and modify
		int size = 12
	    int my_array[size] = {7, 4, 2, 1, 15, 3, 6, 11, 18, 13, 12, 5};

	    // Save the initial state of the array
	    space::sout("my_array", my_array, size);

	    //Hey michael do they need to include indicies in the first call
	    //here like 0,0 or is it ok to leave them out?

	    // Bubble sort algorithm
	    for (int i = 0; i < size - 1; i++) {
	        for (int j = 0; j < size - i - 1; j++) {

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

Here you can see that i havent finished this page yet but i will someday.
