#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>

int main()
{
    std::ifstream read("3.in");
    std::string line;

    std::vector<std::string> lines;

    while (read >> line)
    {
        lines.push_back(line);
    }

    std::string ox = "", co = "";
    for (int i = 0; i < 12; ++i)
    {
        int onesOx = 0, countOx = 0;
        int onesCO = 0, countCO = 0;
        std::string lastOneOx = "", lastOneCO = "";
        for (int j = 0; j < lines.size(); ++j)
        {
            if (lines[j].substr(0, i) == ox)
            {
                countOx++;
                onesOx += lines[j][i] == '1';
                lastOneOx = lines[j];
            }

            if (lines[j].substr(0, i) == co)
            {
                countCO++;
                onesCO += lines[j][i] == '0';
                lastOneCO = lines[j];
            }
        }

        if (ox.size() != 12)
        {
            if (countOx == 1)
            {
                ox = lastOneOx;
            }
            else
            {
                if (onesOx >= countOx - onesOx)
                    ox += "1";
                else
                    ox += "0";
            } 
        }

        if (co.size() != 12)
        {
            if (countCO == 1)
            {
                co = lastOneCO;
            }
            else
            {
                if (onesCO <= countCO - onesCO)
                    co += "0";
                else
                    co += "1";
            } 
        }
    }


    std::cout << std::stoi(ox, nullptr, 2) * std::stoi(co, nullptr, 2);

    read.close();

    return 0;
}