/*
This program is to show the user how to use our product to save and store
    STL stacks
    Written By Michael Giardina And Christian Gregory
*/

#include <iostream>
#include <stack>

#include "../space.hpp"

int main(void)
{
    // Below are initializations of stacks
    std::stack<int> int_stack;
    std::stack<float> float_stack;
    std::stack<double> double_stack;
    std::stack<bool> bool_stack;
    std::stack<char> char_stack;

    // Below is a loop to fill the stacks with values
    for (int i = 97; i < 97 + 26; i += 5)
    {
        int_stack.push(i);
        float_stack.push(i + .5);
        double_stack.push(i + .8);
        bool_stack.push(i);
        char_stack.push(i);

        // We can now call the sout function, which will save each step of filling the stack
        // Note: for stacks, our sout function takes two parameters, the name of the array as a string
        //      and the stack itself
        space::sout("int_stack", int_stack);
        space::sout("float_stack", float_stack);
        space::sout("double_stack", double_stack);
        space::sout("bool_stack", bool_stack);
        space::sout("char_stack", char_stack);
        
    }

    // Now that the stacks are full, we can call our function to save the data into a JSON file
    // Note: for stacks, our sout function takes two parameters, the name of the array as a string
    //      and the stack itself
    space::sout("int_stack", int_stack);
    space::sout("float_stack", float_stack);
    space::sout("double_stack", double_stack);
    space::sout("bool_stack", bool_stack);
    space::sout("char_stack", char_stack);

    // Notice how a data.json file has either been created or overwritten,
    //      you can now drag and drop that data.json file into the browser app
    //      to visualize your stack

    return 0;
}