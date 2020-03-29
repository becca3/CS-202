#include <iostream>

//Recursive factorial
int fact(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    return n * fact(n - 1);
}

//Non-recursive factorial
int fact_loop(int n)
{
    int f = 1;

    for (int i = n; i > 1; --i)
        f *= i;

    return f;
}

int main()
{
    std::cout << "5 = 5 * 4 * 3 * 2 * 1 = " << fact(5) << std::endl;

    std::cout << std::endl;

	return 0; 
}