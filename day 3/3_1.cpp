#include <iostream>
#include <fstream>

int main()
{
    std::ifstream read("3.in");
    std::string line;

    int appearances[12]{};

    while (read >> line)
    {
        for (int i = 0; i < 12; ++i)
            appearances[i] += line[i] == '1';
    }

    short v1 = 0, v2 = 0;
    for (int i = 0; i < 12; ++i)
    {
        if (appearances[i] >= 500)
            v1 += 1;
        else
            v2 += 1;
        if (i != 11)
        {
            v1 = v1 << 1;
            v2 = v2 << 1;
        }
    }

    std::cout << (int)v1 * (int)v2;

    read.close();

    return 0;
}
