#ifndef SPACE_HPP
#define SPACE_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class SPACE
{
public:
    SPACE()
    {
        //Do nothing
    }

    bool test(int array[], size_t size, size_t i, std::string op, size_t j)
    {
        const std::vector<std::string> valid = {"<", "<=", ">", ">="};

        while (!std::count(valid.begin(), valid.end(), op))
        {
            std::cout << "You did not enter a valid operator, please try again: ";
            std::cin >> op;
        }

        tIndicies.vector::push_back(i);
        tIndicies.vector::push_back(j);
        indicies.vector::push_back(tIndicies);

        for (size_t i = 0; i < size; i++)
        {
            tElements.vector::push_back(array[i]);
        }

        elements.push_back(tElements);

        if (op == valid[0])
        {
            return i < j;
        }
        else if (op == valid[1])
        {
            return i <= j;
        }
        else if (op == valid[2])
        {
            return i > j;
        }
        else if (op == valid[3])
        {
            return i >= j;
        }

        return true;
    }

    void done()
    {
        data.open("data.json");

        data << "{\n\"Data\" : {\n\t\"Indicies\" : [";

        for (size_t i = 0; i < indicies.size(); i++)
        {
            data << "[";
            for (size_t j = 0; j < indicies[0].size(); j++)
            {
                data << indicies[i][j] << ((j == indicies[0].size() - 1) ? "" : ",");
            }
            data << "]" << ((i == indicies.size() - 1) ? "" : ",");
        }

        data << "],\n\t\"Elements\" : [";
        for (size_t i = 0; i < elements.size(); i++)
        {
            data << "[";
            for (size_t j = 0; j < elements.size(); j++)
            {
                data << elements[i][j] << ((j == elements[0].size() - 1) ? "" : ",");
            }
            data << "]" << ((i == elements.size() - 1) ? "" : ",");
        }

        data << "]\n\t}\n}";

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
