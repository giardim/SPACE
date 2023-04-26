/*
This program is to show the user how to use our product to save and store
    STL queues
*/

#include <iostream>
#include <queue>

#include "../space.hpp"

int main(void)
{
    // Below are initializations of queues
    std::queue<int> int_queue;
    std::queue<float> float_queue;
    std::queue<double> double_queue;
    std::queue<bool> bool_queue;
    std::queue<char> char_queue;

    // Below is a loop to fill the queues with values
    for (int i = 97; i < 97 + 26; i += 5)
    {
        int_queue.push(i);
        float_queue.push(i + .5);
        double_queue.push(i + .8);
        bool_queue.push(i);
        char_queue.push(i);

        // We can now call the sout function, which will save each step of filling the queue
        // Note: for queues, our sout function takes two parameters, the name of the array as a string
        //      and the queue itself
        space::sout("int_queue", int_queue);
        space::sout("float_queue", float_queue);
        space::sout("double_queue", double_queue);
        space::sout("bool_queue", bool_queue);
        space::sout("char_queue", char_queue);
        
    }

    // Now that the queues are full, we can call our function to save the data into a JSON file
    // Note: for queues, our sout function takes two parameters, the name of the array as a string
    //      and the queue itself
    space::sout("int_queue", int_queue);
    space::sout("float_queue", float_queue);
    space::sout("double_queue", double_queue);
    space::sout("bool_queue", bool_queue);
    space::sout("char_queue", char_queue);

    // Notice how a data.json file has either been created or overwritten,
    //      you can now drag and drop that data.json file into the browser app
    //      to visualize your queue

    return 0;
}