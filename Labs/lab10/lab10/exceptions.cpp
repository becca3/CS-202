#include <iostream>

class Testing
{
public:
    Testing()
    {
        std::cout << "Testing constructed. \n";
    }

    ~Testing()
    {
        std::cout << "Testing destroyed. \n";
    }
};

void functionC()
{
  //your code here
    throw std::runtime_error("FunctionC threw a runtime error.");
}

void functionB()
{
    Testing t1;
    //your code here
    std::cout << "Starting functionB()\n";
    functionC();
    std::cout << "Ending functionB()\n";
}
 
void functionA()
{
  // your code here
    try
    {
        functionB();
        std::cout << "If you've reached this code, you've failed... \n";
    }
    catch (const std::exception & e)
    {
        // your code here
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
  // your code here
    std::cout << "If you've reached this code... You've succeeded! \n";
}

int main()
{
  std::cout << "Starting main()" << std::endl;
  functionA();
  std::cout << "Ended normally." << std::endl;
  return 0;
}
