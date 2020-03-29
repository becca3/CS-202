#include <iostream>

//Recursive factorial
int fact(int x)
{
    if (x <= 1)
    {
        return 1;
    }

    return x * fact(x - 1);
}

//Non-recursive factorial

int main()
{
    std::cout << "5 = 5 * 4 * 3 * 2 * 1 = " << fact(5) << std::endl;

    std::cout << std::endl;

	return 0; 
}