# About the save file

Each datastructure is an object.

They main key for each object will be what the students variable name for that datastructure is
e.g. pos_int[] is saved into the JSON file as an object with the name pos_int.

Each object will have a type key and data key.
The type key defines what type of datastructure the object is.
The data key contains the contents of that datastructure.
Every time a datastructure is saved, the contents of the datastructure are saved as an array in its JSON object.
If multiple saves of the same datastructure occur, each datastructure save array is appened to the data key.


