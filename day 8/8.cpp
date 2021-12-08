#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::ifstream read("8.in");

    int c = 0, sum = 0;
    while (!read.eof())
    {
        std::vector <std::string> patterns;
        std::string str = "";

        for (int i = 0; i < 10; ++i)
        {
            read >> str;
            std::sort(str.begin(), str.end());
            patterns.push_back(str);
        }

        std::sort(patterns.begin(), patterns.end(), [](std::string& s1, std::string& s2) { return s1.size() < s2.size(); });

        read.ignore(3); // ommit '|'

        std::string res = "";
        for (int i = 0; i < 4; ++i)
        {
            read >> str;

            int size = str.size();
            if ((size >= 2 && size <= 4) || size == 7)
            {
                res += size == 2 ? "1" : size == 3 ? "7" : size == 4 ? "4" : "8";
                ++c;
            }
            else if (size == 5)
            {
                if (std::all_of(patterns[0].begin(), patterns[0].end(), [&](char& c) { return std::find(str.begin(), str.end(), c) != str.end(); }))
                    res += "3";
                else if (std::count_if(patterns[2].begin(), patterns[2].end(), [&](char& c) { return std::find(str.begin(), str.end(), c) != str.end(); }) == 2)
                    res += "2";
                else
                    res += "5";
            }
            else if (size == 6)
            {
                if (std::all_of(patterns[0].begin(), patterns[0].end(), [&](char& c) { return std::find(str.begin(), str.end(), c) != str.end(); }))
                {
                    if (std::count_if(patterns[2].begin(), patterns[2].end(), [&](char& c) { return std::find(str.begin(), str.end(), c) != str.end(); }) == 3)
                        res += "0";
                    else
                        res += "9";
                }
                else
                    res += "6";
            }
        }

        sum += std::stoi(res);
    }

    std::cout << c << '\n';
    std::cout << sum;

    read.close();

    return 0;
}