#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>

std::vector <int> crabs;

void part_1();
void part_2();

// haha brute goes IIII (intensive noises of my cpu)

int main ()
{
    std::ifstream read("7.in");

    std::string line;
    while (std::getline(read, line, ','))
        crabs.push_back(std::stoi(line));
    read.close();

    std::sort(crabs.begin(), crabs.end());

    part_1();
    part_2();

    return 0;
}

void part_1()
{
    int minSum = 666666666;
    for (int i = crabs.front(); i < crabs.back(); ++i)
    {
        int sum = 0;
        for (auto& crab : crabs)
            sum += abs(crab - i);
        if (sum < minSum)
            minSum = sum;
    }
    std::cout << minSum << '\n';
}

void part_2()
{
    int minSum = 666666666;
    for (int i = crabs.front(); i < crabs.back(); ++i)
    {
        int sum = 0;
        for (auto& crab : crabs)
            sum += abs(crab - i) * (abs(crab - i) + 1) / 2;
        if (sum < minSum)
            minSum = sum;
    }
    std::cout << minSum;
}