#include <iostream>
#include <algorithm>

int main() {
    int size = 12;
    int my_array[size] = {7, 4, 2, 1, 15, 3, 6, 11, 18, 13, 12, 5};

    // Bubble sort algorithm
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (my_array[j] > my_array[j + 1]) {
            
                // Swap elements using std::swap
                std::swap(my_array[j], my_array[j + 1]);

                
            }
        }
    }

   
            for(int i = 0; i<size; i++){
                std::cout<<" "<<my_array[i]<<std::endl;
            }
    

    return 0;
}