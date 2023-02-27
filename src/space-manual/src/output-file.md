# About the save file

Each datastructure is an object.

They main key for each object will be what the students variable name for that datastructure is
e.g. pos_int[] is saved into the JSON file as an object with the name pos_int.

Each object will have a type key and data key.
The type key defines what type of datastructure the object is.
The data key contains the contents of that datastructure.
Every time a datastructure is saved, the contents of the datastructure are saved as an array in its JSON object.
If multiple saves of the same datastructure occur, each datastructure save array is appened to the data key.

### Example

	{
	"array": {
		"type": "Array1D",
		"data": [
		[23,16,62,56,31,49,22],
		[16,23,62,56,31,49,22],
		[16,23,56,62,31,49,22],
		[16,23,56,31,62,49,22],
		[16,23,56,31,49,62,22],
		[16,23,56,31,49,22,62],
		[16,23,31,56,49,22,62],
		[16,23,31,49,56,22,62],
		[16,23,31,49,22,56,62],
		[16,23,31,22,49,56,62],
		[16,23,22,31,49,56,62],
		[16,22,23,31,49,56,62]
		]
	}
	}

