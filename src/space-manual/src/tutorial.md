# Tutorial

Lets get started using SPACE. After you have followed the installation 
instructions, you should be ready to write your first program using SPACE! 
Lets make a simple project to demonstrate how SPACE works.

### Simple Array

Here is a simple C++ program that creates an array of 7 elements.

	#include <iostream>
	#include "space.hpp"

	int main() {
		//Create array of 7 elements
	    int my_array[7] = {11, 20, 23, 4, 15, 6, 78};

	    //Call the space::sout function to output the array to data.json
		space::sout("my_array", my_array, 7);

	    return 0;
	}

First, we must #include the "space.hpp" file at the start of your program. 
Doing this will allow you to use the space::sout() function. The 
space::sout() function is the only function you will need to use to 
visualize your programs with SPACE. 

What is the space::sout() function? The space::sout() function is a lot like 
printf(). All it does is take the data structure you give it (in this case 
a simple array of integers) and prints it out into a file. It also does 
some formatting behind the scenes to get your data structure into JSON format, 
but you don't need to think about that because its all automatic!

In this program the space::sout() function takes three arguments:

1. "my_array" is the string that your array will be named in the visualizer
2. my_array is the array itself
3. 7 is the size of the array

After compiling and running this program, you will find a data.json file 
in your project directory. We will drag and drop this file into our browser 
app.

### Browser App

To visuzalize the output of our demo program, open the index.html file from 
the SPACE directory with a web browser like Firefox or Chrome. With your 
file manager open, click and drag the data.json file into the browser window. 

Now lets take a tour of the browser app.

#### Overview

The general layout of our application is a main visualization area on the 
right with a sidebar on the left.

#### Functionality

The user may drag a data.json file from their file explorer into the webpage. 
The data structures saved in the data.json file will populate the side bar. 
To visualize a data structure, click one of the elements in the side bar. 
This will fill the visualization pane with a view of that data structure.

#### The Visualization Pane

Hover your mouse over an element to see its value. 
Use the media controls at the bottom to play/pause automatic iteration through 
the save states of your structure. Use the bar to scrub through the save 
states of your structure.

#### The Side Bar

The sidebar contains a list of all data structures present in the data.json 
file. Clicking on one will open it in the visualization pane. Only one 
data structure may be visualized at a time. You can open the SPACE manual 
by clicking the button at the bottom of the side bar.


In the next section we will look at some examples of different data 
structures and sorting algorithms, and how you can use space::sout() to 
visualize them.
