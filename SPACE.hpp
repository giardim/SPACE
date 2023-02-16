#ifndef SPACE_H
#define SPACE_H
#include <iostream>
#include <String>
#include <vector>
#include <algorithm>

class SPACE{
public:
    SPACE(){    
        //do nothing
    }

    bool test(int *array, int i, std::string op, int j){
        bool check = false;
        const std::vector<std::string> valid = {"<", "<=", ">", ">="};

        while (!std::count(valid.begin(), valid.end(), op)){
            std::cout << "You did not enter a valid operator, please try again: ";
            std::cin >> op;
        }

        if (op == valid[0]){
            return i < j;
        } else if (op == valid[1]){
            return i <= j;
        } else if (op == valid[2]){
            return i > j;
        } else if (op == valid[3]){
            return i >= j;
        }

        return true;
    }   

private:
    std::vector<std::vector<int>> elements;
    std::vector<std::vector<int>> indicies;


};


#endif