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

//Non-recursive fib
int fib_loop(int x)
{
    static int f0 = 0;
    static int f1 = 1;
    static int f;

    if (x == 0)
        return 0;

    if (x == 1)
        return 1;

    while (x > 0)
    {
        f = f0 + f1;

        if (__debug__)
            std::cout << f0 << " + " << f1 << " = " << f << std::endl;

        f0 = f1;
        f1 = f;

        --x;
    }

    return f;
}

int main()
{
    std::cout << "Recursive Fibonacci \n";
    int f = fib(10);

    std::cout << std::endl;

    std::cout << "Non-recursive Fibonacci \n";
    int g = fib_loop(10);

    return 0;
}
