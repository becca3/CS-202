#include <iostream>        
#include <numeric>           
#include <algorithm>    
#include <vector>       

//Accumulate algorithm.
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
    //Accumulate algorithm.
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
    std::cout << "\n";

    //Swap algorithm.
    int a = 1, b = 5;
    std::swap(a, b);

    std::vector<int> foo(3, a), foo2(9, b);
    std::swap(foo, foo2);

    std::cout << "Foo contains: ";
    for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
    {
        std::cout << ' ' << *it;
    }
    std::cout << '\n';

    return 0;
}