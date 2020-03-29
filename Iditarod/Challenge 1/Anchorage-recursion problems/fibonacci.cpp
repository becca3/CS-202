#include <iostream>

bool __debug__ = true;

//Recursive fib
int fib(int x)
{
    static int f0 = 0;
    static int f1 = 1;
    static int f;

    if (x > 0)
    {
        f = f0 + f1;

        if (__debug__)
            std::cout << f0 << " + " << f1 << " = " << f << std::endl;

        f0 = f1;
        f1 = f;

        fib(x - 1);
    }

    return f;
}