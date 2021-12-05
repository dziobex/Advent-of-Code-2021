#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <fstream>

int grid[1000][1000] {};
int counter = 0;

struct Set
{
    int coords[4]{};
    void fill()
    {
        bool xContinue = true, yContinue = true;

        while (xContinue || yContinue)
        {
            if (++grid[ coords[0] ][ coords[1] ] >= 2)
            {
                ++counter;
                grid[ coords[0] ][ coords[1] ] = -666;
            }

            if (coords[0] != coords[2])
                coords[0] += coords[0] > coords[2] ? -1 : 1;
            else
                xContinue = false;

            if (coords[1] != coords[3])
                coords[1] += coords[1] > coords[3] ? -1 : 1;
            else
                yContinue = false;
        }
    }
};

int main()
{
    std::ifstream read("5.in");
    std::string line = "";

    std::vector<Set> sets;

    // I could actually replace in the input file all " -> " with ",", but I like suffering
    while (std::getline(read, line))
    {
        line.replace(line.find(" -> "), 4, ",");

        std::stringstream ss(line);
        Set set;
        for (int i = 0; i < 4; ++i)
        {
            std::getline(ss, line, ',');
            set.coords[i] = std::atoi(line.c_str());
        }

        if (set.coords[0] == set.coords[2] || set.coords[1] == set.coords[3]
        || (abs(set.coords[0] - set.coords[2]) == abs(set.coords[1] - set.coords[3]))
        )
        {
            sets.push_back(set);
        }
    }

    read.close();
    
    for (auto& set : sets)
    {
        set.fill();
    }

    std::cout << counter;

    return 0;
}