/*
This program is to show the user how to use our product to save and store
    STL lists
*/

#include <iostream>
#include "../space.hpp"

// Create your linked list
// Note: The name of your structure can be anything you want, but the value identifier must
//       be called "val" and the next indentifier must be called "next"
// Note: The data type of the value can be int, float, double, or bool
struct linked_list
{
    int val;
    linked_list *next;
} typedef linked_list;

int main(void)
{
    // Below is the intialization of the linked list
    linked_list *head = new linked_list;
    linked_list *curr = head;

    // Below we are filling the linked list
    for (int i = 0; i < 6; ++i)
    {
        curr->val = i;
        curr->next = new linked_list;
        curr = curr->next;
    }
    curr->next = NULL;

    // Below we are setting the pointer to the beginning of the linked list
    curr = head;

    // Now we can call the sout function
    // Note: for user created linked lists, our sout function takes two parameters, the name of the array as a string
    //      and the list itself
    space::sout("linked list", curr);

    // Notice how a data.json file has either been created or overwritten,
    //      you can now drag and drop that data.json file into the browser app
    //      to visualize your list

    return 0;
}
