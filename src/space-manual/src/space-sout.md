	void space::sout()

### Examples

#### Array

	int array_size = 3;
	int joke[array_size] = {6,7,8,9};
	space::sout("joke", joke, array_size);

#### Array with indicies of sorting algorithm

	space::sout("joke", joke, array_size, i, j);


> See the [Examples](examples.md) chapter for more detailed examples with more data structures.


### Description

Stores the data structure to memory **as is** (just like std::cout) 
If you modify the data structure you must call space::sout() again if you 
want to save the updated structure. At the end of your program the stored 
memory will be outout to the data.json file.

### Syntax

	space::sout(STRING name_of_data_structure, data_structure, INT size_of_data_structure);

data_structure may be of any type aside from string.

### Parameters

	space::sout(
	STRING name_of_array, /* if your array is named "joke" pass in "joke" as a string in double quotes */
	INT array, /* pass in the array */
	INT size_of_array /* pass in the size of the array */

### Returns

N/A because space::sout() is a void function.





