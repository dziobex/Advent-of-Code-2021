#include <iostream>
#include <fstream>

int main ()
{
    std::ifstream read("1.txt");

    int a = 0, b = 0, c = 0;

    read >> a;
    
    while (read >> b)
    {
        if (a < b) ++c;
        a = b;
    }

    std::cout << c;

    read.close();
    
    return 0;
}