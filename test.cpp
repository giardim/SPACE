#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <cassert> 


using namespace std;

int main(){
    int array[6] = {1,2,3,4,5,6};
    int neg_Array[6] = {-1,-2,-3,-4,-5,-6};
    int testy[6] = {3,6,4,1,4,3};
    char char_Array[6] = {'a','b','c','d','e','f'};
    char char_Array_with_indices[6] = {'a','b','c','d','e','f'};
    double double_array[6] = {1.3,2.7,3.1,4.8,5.0,6.9};
    double double_array_with_indices[6] = {1.3,2.7,3.1,4.8,5.0,6.9};

    assert(array == array);
    cout<<"Passed"<<endl;
    assert(neg_Array == array);
    cout<<"Passed"<<endl;
    assert(testy == array);
    cout<<"Passed"<<endl;
    //assert(char_Array == array);
    //cout<<"Passed"<<endl;
    //assert (char_Array_with_indices == array);
    //cout<<"Passed"<<endl;
    //do the same thing going down with chars and keep going from there 


    
    return 0;
}


