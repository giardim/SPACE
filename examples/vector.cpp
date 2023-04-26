/*
This program is to show the user how to use our product to save and store
    STL vectors
*/

#include <iostream>
#include <vector>

#include "../space.hpp"

int main(void)
{
    // Below are initializations of vectors
    std::vector<int> int_vector;
    std::vector<float> float_vector;
    std::vector<double> double_vector;
    std::vector<bool> bool_vector;
    std::vector<char> char_vector;

    // Below is a loop to fill the vectors with values
    for (int i = 97; i < 97 + 26; i += 5)
    {
        int_vector.push_back(i);
        float_vector.push_back(i + .5);
        double_vector.push_back(i + .8);
        bool_vector.push_back(i);
        char_vector.push_back(i);
        //If you want to see each step of the vector as it is inserted, you would call the sout function here
    }

    // Now that the vectors are full, we can call our function to save the data into a JSON file
    // Note: for vectors, our sout function takes two parameters, the name of the array as a string
    //      and the vector itself
    space::sout("int_vector", int_vector);
    space::sout("float_vector", float_vector);
    space::sout("double_vector", double_vector);
    space::sout("bool_vector", bool_vector);
    space::sout("char_vector", char_vector);

    // Notice how a data.JSON file has either been created or overwritten,
    //      you can now drag and drop that data.JSON file into the browser app
    //      to visualize your vector

    return 0;
}