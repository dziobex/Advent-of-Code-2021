#include <iostream>
#include <fstream>

void a();
void b();

int main()
{
    a();
    b();
    return 0;
}

void a()
{
    std::ifstream read("2.in");
    std::string command = "";
    int x = 0, y = 0, moves = 0;

    while (read >> command >> moves)
    {
        if (command == "forward")
            x += moves;
        else if (command == "down")
            y += moves;
        else if (command == "up")
            y -= moves;
    }

    read.close();

    std::cout << x * y << '\n';
}

void b()
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
            aim += moves;
        else if (command == "up")
            aim -= moves;
    }

    read.close();

    std::cout << x * y << '\n';
}