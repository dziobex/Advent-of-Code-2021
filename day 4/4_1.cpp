#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

int main()
{
    std::ifstream read("4.in");
    std::string data;

    std::vector<int> nums;

    read >> data;
    std::stringstream ss(data);

    while (std::getline(ss, data, ','))
    {
        nums.push_back(atoi(data.c_str()));
    } nums.pop_back(); // removing additional 0 (wtf)
    
    int minNum = 666, minSum = 0;

    while (!read.eof())
    {
        bool bingo = false;
        int boardSum = 0, num = 0;
        std::vector<int> board;

        for (int i = 0; i < 25; ++i)
        {
            read >> num;
            board.push_back(num);
            boardSum += num;
        }

        for (int i = 0; i < nums.size() && !bingo; ++i)
        {
            int index = std::distance(board.begin(), std::find(board.begin(), board.end(), nums[i]));

            if (index != 25)
            {
                boardSum -= board[index];
                board[index] = -1;

                // check if B I N G O
                
                int count_r = 0, count_c = 0;

                for (int j = 0; j < 5; ++j)
                {
                    // row?
                    count_r += board[5 * floor(index / 5) + j] == -1;
                    // col?
                    count_c += board[(index % 5) + 5 * j] == -1;
                }
                if (count_r == 5 || count_c == 5)
                {
                    if (i < minNum)
                    {
                        minNum = i;
                        minSum = boardSum;
                    }
                    bingo = true;
                }
            }
        }
    }

    std::cout << nums[minNum] * minSum;

    read.close();

    return 0;
}