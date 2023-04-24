	void space::sout()

### Examples

> See the [Examples](examples.md) chapter for more detailed examples with more data structures.

### Description

Stores the data structure to memory **as is** (just like std::cout) 
If you modify the data structure you must call space::sout() again if you 
want to save the updated structure. At the end of your program the stored 
memory will be outout to the data.json file.

### Syntax

##### Stacks, Queues, Vectors
	space::sout(
		"my_STL", 		// name of data structure
		data_structure	// data structure itself
	);

##### Array
	space::sout(
		"my_array", 	// name of data structure
		data_structure,	// data structure itself
		size_of_array	// size (length) of array
	);

##### Array with indicies
	space::sout(
		"my_array",		// name of data structure 
		data_structure,	// data structure itself
		size, 		// size (length) of array
		index_one, 		// index 1
		index_two		// index 2
	);

##### 2D array
    space::sout(
	    "2d array", 	// name of data structure
	    array_2d, 		// data structure itself
	    ROWS, COLS		// size of 2d array
    );

##### 2D array with indicies
	space::sout(
		"2d array", 	// name of data structure
		array_2d, 		// data structure itself
		ROWS, COLS, 	// size of 2d array
		j, k, 		// index 1 (x,y)
		j, k+1		// index 2 (x,y)
	);


### Types

All supported data structures can work with types 
*int, float, double, bool, char*, and *wide char* 
**EXCEPT LINKED LISTS!** 
Linked lists only support int, float, double, and bool.

### Returns

N/A because space::sout() is a void function.





