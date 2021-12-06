#include <iostream>
#include <fstream>
#include <vector>

struct Window
{
    int sum = 0, count = 0;
    void reset()
    {
        sum = 0;
        count = -1;
    }
};

int main ()
{
    std::ifstream read("1.in");

    int x = 0;
    Window windows[4]
    {
        Window{0, 0},
        Window{0, -1},
        Window{0, -2},
        Window{0, -3}
    };
    int sum = 0, prevAnswer = -69;
    
    while (read >> x)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (windows[i].count >= 0 && windows[i].count <= 2)
                windows[i].sum += x;
            if (windows[i].count >= 2)
            {
                if (prevAnswer != -69 && prevAnswer < windows[i].sum)
                    ++sum;
                prevAnswer = windows[i].sum;
                windows[i].reset();
                continue;
            }
            ++windows[i].count;
        }
    }
    
    std::cout << sum;

    read.close();
    
    return 0;
}