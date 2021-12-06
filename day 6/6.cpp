#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

#define ull unsigned long long
ull states[9]{};

int main ()
{
    std::ifstream read("6.in");

    std::string line;
    std::getline(read, line);
    read.close();

    std::replace(line.begin(), line.end(), ',', ' ');
    std::istringstream iss(line);

    int state = 0;
    while (iss >> state)
    {
        ++states[state + 1];
    }

    for (int i = 0; i < 257; ++i)
    {
        ull add8 = 0, add6 = 0;
        for (int j = 0; j < 10; ++j)
        {
            if (states[j] > 0)
            {
                if (j == 0)
                {
                    add8 += states[j];
                    add6 += states[j];
                }
                else
                    states[j - 1] += states[j];
                states[j] = 0;
            }
        }

        states[6] += add6;
        states[8] += add8;

        if (i == 80 || i == 256)
        {
            ull sum = 0;
            for (int i = 0; i < 9; ++i)
                sum += states[i];
            std::cout << sum << '\n';
        }
    }
    
    return 0;
}