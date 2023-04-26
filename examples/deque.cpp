/*
This program is to show the user how to use our product to save and store
    STL deques
*/

#include <iostream>
#include <deque>

#include "../space.hpp"

int main(void)
{
    // Below are initializations of deques
    std::deque<int> int_deque;
    std::deque<float> float_deque;
    std::deque<double> double_deque;
    std::deque<bool> bool_deque;
    std::deque<char> char_deque;

    // Below is a loop to fill the deques with values
    for (int i = 97; i < 97 + 26; i += 5)
    {
        int_deque.push_front(i);
        float_deque.push_front(i + .5);
        double_deque.push_front(i + .8);
        bool_deque.push_front(i);
        char_deque.push_front(i);
        //If you want to see each step of the deque as it is inserted, you would call the sout function here
    }

    // Now that the deques are full, we can call our function to save the data into a JSON file
    // Note: for deques, our sout function takes two parameters, the name of the array as a string
    //      and the deque itself
    space::sout("int_deque", int_deque);
    space::sout("float_deque", float_deque);
    space::sout("double_deque", double_deque);
    space::sout("bool_deque", bool_deque);
    space::sout("char_deque", char_deque);

    // Notice how a data.JSON file has either been created or overwritten,
    //      you can now drag and drop that data.JSON file into the browser app
    //      to visualize your deque

    return 0;
}