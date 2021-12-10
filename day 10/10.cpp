#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define ull unsigned long long

std::map<char, char> pairs
{
    {')', '('},
    {'}', '{'},
    {']', '['},
    {'>', '<'}
};

std::map<char, int> values
{
    {')', 3},
    {']', 57},
    {'}', 1197},
    {'>', 25137} // damn almost papais num :(
};

std::map<char, int> cValues
{
    {'(', 1},
    {'[', 2},
    {'{', 3},
    {'<', 4}
};

std::vector <ull> scores;

int main ()
{
    std::ifstream read("10.in");
    std::string line = "";

    int sum = 0;

    while (std::getline(read, line))
    {
        std::vector <int> depths;
        
        bool isFine = true;
        for (auto& c : line)
        {
            if (c == '{' || c == '(' || c == '[' || c == '<')
            {
                depths.push_back(c);
            }
            else
            {
                if (depths[depths.size() - 1] != pairs[c] )
                {
                    sum += values[c];
                    isFine = false;
                    break;
                }
                else
                {
                    depths.pop_back();
                }
            }
        }

        if (isFine)
        {
            ull tScore = 0;
            for (int i = depths.size() - 1; i >= 0; --i)
            {
                tScore *= 5;
                tScore += cValues[depths[i]];
            }

            scores.push_back(tScore);
        }
    }

    read.close();

    std::sort(scores.begin(), scores.end());
    std::cout << sum << '\n' << scores[scores.size() / 2];

    return 0;
}