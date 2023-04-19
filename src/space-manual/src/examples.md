# Examples

So we know that space::sout() works kind of like printf() or std::cout, 
but how does that effect how we use it? Well lets imagine that we were 
just using std::cout to figure out what our data structures look like. 
To print an array with std::cout we need to use a for loop.

	#include <iostream>
	
	int main() {
		
		// Create our array
		int my_array[7] = {1, 2, 3, 4, 5, 6, 7};
		
		// Print array to std::out
		for (int i = 0; i < 7; i++) {
			std::cout << my_array[i] << " ";
	    }
		
	    std::cout << std::endl;
		
		return 0;
	}

Output: 

	1 2 3 4 5 6 7

The for loop goes through every element of the array starting at my_array[0] 
up to my_array[6] with a " " space in between each element. It prints 
every element in the array because programmer hard coded the size of the 
array to be 7 *and* the number of iterations of the for loop to also be 7. 
If the loop had 4 instead of 7 in its condition then it would only 
print 4 elements. As you can see, to print out *every* element of the array, 
we need to know the *size* of the array. This same principle applies to 
space::sout(), which is why you need to pass in the size of your data 
structure as an argument. 

This works for an array that doesn't change, but what if we modify it 
after we print it?

	#include <iostream>
	
	int main() {
		
		// Create our array
		int my_array[7] = {1, 2, 3, 4, 5, 6, 7};
		
		// Print array to std::out
		for (int i = 0; i < 7; i++) {
			std::cout << my_array[i] << " ";
	    }
		
	    std::cout << std::endl;
		
	    my_array[0] = 200; // Change the 1 in the array to 200
		
		return 0;
	}

Output: 

	1 2 3 4 5 6 7

Obviously, we are still printing out the array as it was originally because 
after we update the array to turn 1 into 200, we dont print it again. Lets 
fix that.

	#include <iostream>
	
	int main() {
		
		// Create our array
		int my_array[7] = {1, 2, 3, 4, 5, 6, 7};
		
		// Print array to std::out
		for (int i = 0; i < 7; i++) {
			std::cout << my_array[i] << " ";
	    }
		
	    std::cout << std::endl;
		
	    my_array[0] = 200; // Change the 1 in the array to 200

		// Print array to std::out AGAIN after we change it
		for (int i = 0; i < 7; i++) {
			std::cout << my_array[i] << " ";
		 }
				
		 std::cout << std::endl;
			    
		return 0;
	}

Output:

	1 2 3 4 5 6 7
	200 2 3 4 5 6 7

That makes sense, every time we update our array we need to print it again. 
Now instead of using for loops and std::cout to visualize the array, lets 
use space::sout().

	#include <iostream>
	#include "space.hpp"
	
	int main() {
		
		// Create our array
		int my_array[7] = {1, 2, 3, 4, 5, 6, 7};
		
		// Save the array to the data.json file
		space::sout("my array" my_array, 7);
		
	    my_array[0] = 200; // Change the 1 in the array to 200

		// Save the array AGAIN after we change it
		space::sout("my array" my_array, 7);
			    
		return 0;
	}
	
Just like how we needed to print the array after every update, with 
space::sout() we need to save the array after every update.

In the next section we will use space::sout() in some more interesting 
programs like sorting algorithms.
