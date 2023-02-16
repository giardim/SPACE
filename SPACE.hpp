#ifndef SPACE_H
#define SPACE_H
#include <iostream>
#include <String>
#include <vector>
#include <algorithm>
#include <fstream>

class SPACE{
public:
    SPACE(){    
        
    }

    bool test(int *array, int i, std::string op, int j){
        bool check = false;
        const std::vector<std::string> valid = {"<", "<=", ">", ">="};

        while (!std::count(valid.begin(), valid.end(), op)){
            std::cout << "You did not enter a valid operator, please try again: ";
            std::cin >> op;
        }

        tIndicies.vector::push_back(i);
        tIndicies.vector::push_back(j);
        indicies.vector::push_back(tIndicies);

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

    void done(){
        data.open("data.json");

        data << "{\n\"Data\" : {\n\t\"Indicies\" : [";

        for (int i = 0; i < indicies.size(); ++i){
            data << "[";
            for (int j = 0; j < indicies[0].size(); ++j){
                data << indicies[i][j] << ((j == indicies[0].size() - 1)? "" : ",");
            }
            data << "]" << ((i == indicies.size() - 1) ? "" : ",");
        }
        data << "]\n}\n}";

        


        data.close();
    }

private:
    std::vector<std::vector<int>> elements;
    std::vector<std::vector<int>> indicies;
    std::vector<int> tIndicies;
    std::vector<int> tElements;

    std::ofstream data;
};


#endif