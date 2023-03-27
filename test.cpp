#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <cassert> 


using namespace std;

int main(){
    int array[6];
    string s_array[6];
    bool b_array[6];
    char c_array[6];
    double d_array[6];
    int i_array[6] = {1, 2, 3, 4, 5, 6};
    int neg_Array[6] = {-1,-2,-3,-4,-5,-6};
    int testy[6] = {3,6,4,1,4,3};
    int array_with_indices[6] = {1,2,3,4,5,6};
    char char_Array[6] = {'a','b','c','d','e','f'};
    char char_Array_with_indices[6] = {'a','b','c','d','e','f'};
    double double_array[6] = {1.3,2.7,3.1,4.8,5.0,6.9};
    double double_array_with_indices[6] = {1.3,2.7,3.1,4.8,5.0,6.9};
    string string_array [4] ={"Chris", "Sazzad", "Michael", "Sean"}; 
    bool bool_array[6] = {true, false, true, false, true, false};
    bool bool_array_with_indices[6] = {true, false, true, false, true, false};

//add another message in the case of failing assertion or switch to bool as a backup with
//check if == int assert checks values or just pointers
int i_length = sizeof(i_array)/sizeof(int);
int s_length = sizeof(s_array)/sizeof(string);
std::cout<<" "<<i_length<<endl;

    for(int i=0; i<i_length; i++){
        array[i] = i_array[i];
        
        std::cout<<" "<<array[i]<<endl;   
    }

    assert(array == i_array);
    cout<<"Passed"<<endl;
    assert(neg_Array == array);
    cout<<"Passed"<<endl;
    assert(testy == array);
    cout<<"Passed"<<endl;
    (char_Array == c_array); 
    cout<<"Passed"<<endl;
    assert(char_Array_with_indices == c_array);
    cout<<"Passed"<<endl;
    assert(double_array == d_array);
    cout<<"Passed"<<endl;
    assert(double_array_with_indices == d_array);
    cout<<"Passed"<<endl;
    assert(string_array == s_array);
    cout<<"Passed"<<endl;
    assert(array_with_indices == array); 
    cout<<"Passed"<<endl;



    
    return 0;
}


