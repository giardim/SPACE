# Sorting Array

Here is a simple C++ program that uses the 
[bubble sort](https://www.geeksforgeeks.org/bubble-sort/) 
algorithm to sort an array of 12 elements. 

	#include <iostream>
	#include <algorithm>

	int main() {
		int size = 12
	    int my_array[size] = {7, 4, 2, 1, 15, 3, 6, 11, 18, 13, 12, 5};

	    // Bubble sort algorithm
	    for (int i = 0; i < size - 1; i++) {
	        for (int j = 0; j < size - i - 1; j++) {
	            if (my_array[j] > my_array[j + 1]) {
	            
	                // Swap elements using std::swap
	                std::swap(my_array[j], my_array[j + 1]);


	                
	            }
	        }
	    }

	    

	    return 0;
	}

### Using space::sout() in bubble sort

In the last page we established that we need to save the array every time 
it changes. So lets see how we can do that in this bubble sort program.

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

	    // Bubble sort algorithm
	    for (int i = 0; i < size - 1; i++) {
	        for (int j = 0; j < size - i - 1; j++) {
	            if (my_array[j] > my_array[j + 1]) {
	            
	                // Swap elements using std::swap
	                std::swap(my_array[j], my_array[j + 1]);

	                // Every time there is a swap, save the array again
	                space::sout("my_array", my_array, size);
	                
	            }
	        }
	    }

	    // Save the final state of the array
	    space::sout("my_array", my_array, size);

	    return 0;
	}

For a refresher on how to pass arguments to the space::sout() function 
read the [space::sout](space-sout.md) page in the manual.

In the bubble sort program, we first call space::sout() right after we 
create the array to save its initial state. Then we have another 
space::sout() call if the bubble sort swaps two elements in the array. This 
means that every time there is a swap, the state of the array will be 
saved to the data.json file again. Finally, we call space::sout() at the 
very end of the program to save the last state of the array.

Compiling and running this program will produce a data.json file in your 
project's directory. Drag that file into the browser app to visualize 
how the sorting algorithm works.

Cool right? Heck yeah! But we're not done yet. We can make it even better! 
In the next page we will see how we can use space::sout() to save the 
*indicies* of the sorting algorithm to make the visualizer even cooler.
