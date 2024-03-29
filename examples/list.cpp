/*
This program is to show the user how to use our product to save and store
    STL lists
    Written By Michael Giardina And Christian Gregory
*/

#include <iostream>
#include <list>

#include "../space.hpp"

int main(void)
{
    // Below are initializations of lists
    std::list<int> int_list;
    std::list<float> float_list;
    std::list<double> double_list;
    std::list<bool> bool_list;
    std::list<char> char_list;

    // Below is a loop to fill the lists with values
    for (int i = 97; i < 97 + 26; i += 5)
    {
        int_list.push_front(i);
        float_list.push_front(i + .5);
        double_list.push_front(i + .8);
        bool_list.push_front(i);
        char_list.push_front(i);

        // We can now call the sout function, which will save each step of filling the list
        // Note: for lists, our sout function takes two parameters, the name of the array as a string
        //      and the list itself
        space::sout("int_list", int_list);
        space::sout("float_list", float_list);
        space::sout("double_list", double_list);
        space::sout("bool_list", bool_list);
        space::sout("char_list", char_list);
        
    }

    // Now that the lists are full, we can call our function to save the data into a JSON file
    // Note: for lists, our sout function takes two parameters, the name of the array as a string
    //      and the list itself
    space::sout("int_list", int_list);
    space::sout("float_list", float_list);
    space::sout("double_list", double_list);
    space::sout("bool_list", bool_list);
    space::sout("char_list", char_list);

    // Notice how a data.json file has either been created or overwritten,
    //      you can now drag and drop that data.json file into the browser app
    //      to visualize your list

    return 0;
}