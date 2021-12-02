#include <iostream>
#include <fstream>

int main()
{
    std::ifstream read("2.in");

    std::string command = "";
    int x = 0, y = 0, aim = 0, moves = 0;

    while (read >> command >> moves)
    {
        if (command == "forward")
        {
            x += moves;
            y += moves * aim;
        }
        else if (command == "down")
        {
            aim += moves;
        }
        else if (command == "up")
        {
            aim -= moves;
        }
    }

    std::cout << x * y;

    read.close();

    return 0;
}
