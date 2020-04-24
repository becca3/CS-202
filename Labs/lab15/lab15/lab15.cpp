#include <iostream>        
#include <numeric>      

int testFunction(int x, int y) 
{ 
    return x + 2 * y;
}

struct operatorc 
{
    int operator()(int x, int y) { return x + 3 * y; }
} 

myobject;

int main() 
{
    int init = 100;
    int numbers[] = { 10, 20, 30 };

    std::cout << "Using default accumulate: ";
    std::cout << std::accumulate(numbers, numbers + 3, init);
    std::cout << '\n';

    std::cout << "Using custom function: ";
    std::cout << std::accumulate(numbers, numbers + 3, init, testFunction);
    std::cout << '\n';

    std::cout << "Using custom object: ";
    std::cout << std::accumulate(numbers, numbers + 3, init, myobject);
    std::cout << '\n';

    return 0;
}