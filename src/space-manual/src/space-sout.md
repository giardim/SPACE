	void space::sout()

### Example

	int array_size = 3;
	int joke[array_size] = [6,7,8,9];
	space::sout("joke", joke, array_size);

### Description

Stores the data structure to memory AS IS (just like std::cout) 
If you modify the data structure you must call space::sout() again if you 
want to save the updated structure. At the end of your program the stored 
memory will be outout to the data.json file.

### Syntax

	space::sout(STRING name_of_array, INT array, INT size_of_array);

### Parameters

	space::sout(
	STRING name_of_array, /* if your array is named "joke" pass in "joke" as a string in double quotes */
	INT array, /* pass in the array */
	INT size_of_array /* pass in the size of the array */

### Returns

N/A because space::sout() is a void function.





