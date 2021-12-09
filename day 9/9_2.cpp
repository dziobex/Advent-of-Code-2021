#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

#define width 100
#define height 100

int grid[height][width]{};
int countGrid[height][width]{};

struct Chunk
{
    std::vector <int> elements;

    bool fit(int n)
    {
        if (elements.size() == 0) return false;
        for (auto& e : elements)
            if ((abs(n - e) == 1 && floor(n / width) ==  floor(e / width)) || (abs(n - e) == width && n % width== e%width))
            {
                elements.push_back(n);
                return true;
            }
        return false;
    }
};
std::vector<Chunk> chunks;

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
            int tempSum = 0;

            // up
            if (i != 0 && grid[i - 1][j] != 9 && grid[i - 1][j] > grid[i][j])
            {
                countGrid[i - 1][j] =1; countGrid[i][j] = 1;
            }

            // down
            if (i != height - 1 && grid[i + 1][j] != 9 && grid[i + 1][j] > grid[i][j])
            {
                countGrid[i + 1][j] =1; countGrid[i][j] = 1;
            }

            // left
            if (j != 0 && grid[i][j - 1] != 9 && grid[i][j - 1] > grid[i][j])
            {
                countGrid[i][j - 1] =1; countGrid[i][j] =1;
            }

            // right
            if (j != width - 1 && grid[i][j + 1] != 9 && grid[i][j + 1] > grid[i][j])
            {
                countGrid[i][j + 1] =1; countGrid[i][j] = 1;
            }
        }
    }

    // now let's make chunks
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (countGrid[i][j] == 1)
            {
                auto index = std::find_if(chunks.begin(), chunks.end(), [&](Chunk& chunk) { return chunk.fit(i * width + j); });
                if (index == chunks.end())
                {
                    Chunk newChunk;
                    newChunk.elements.push_back(i * width + j);
                    chunks.push_back(newChunk);
                }
            }
        }
    }

    for (int i = 0; i < chunks.size(); ++i)
    {
        for (int j = 0; j < chunks.size(); ++j)
        {
            if (i != j)
            {
                for (int k = 0; k < chunks[j].elements.size(); ++k)
                    if (chunks[i].fit(chunks[j].elements[k]))
                    {
                        chunks[j].elements.erase(chunks[j].elements.begin() + k);
                        for (auto& el : chunks[j].elements)
                            chunks[i].elements.push_back(el);
                        chunks[j].elements.clear();
                    }
            }
        }
    }

    std::sort(chunks.begin(), chunks.end(), [](Chunk& c1, Chunk& c2) { return c1.elements.size() < c2.elements.size(); });

    std::cout << chunks[chunks.size() - 3].elements.size() * chunks[chunks.size() - 2].elements.size()  * chunks[chunks.size() - 1].elements.size();

    read.close();

    return 0;
}