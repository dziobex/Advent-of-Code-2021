#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

#define width 100
#define height 100

int grid[height][width]{};

int main()
{
    std::ifstream read("9.in");

    std::string line;
    int c = 0;
    while (std::getline(read, line))
    {
        for (int i = 0; i < width; ++i)
            grid[c][i] = line[i] - '0';
        ++c;
    }

    int sum = 0;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            int tempSum = 4;

            // up
            if (i != 0 && grid[i - 1][j] <= grid[i][j])
            {
                --tempSum;
            }

            // down
            if (i != height - 1 && grid[i + 1][j] <= grid[i][j])
            {
                --tempSum;
            }

            // left
            if (j != 0 && grid[i][j - 1] <= grid[i][j])
            {
                --tempSum;
            }

            // right
            if (j != width - 1 && grid[i][j + 1] <= grid[i][j])
            {
                --tempSum;
            }

            if (tempSum == 4)
            {
                sum += grid[i][j] + 1;
            }
        }
    }

    std::cout << sum;

    read.close();

    return 0;
}