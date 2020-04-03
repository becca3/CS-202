#include <iostream>

void functionC()
{
  //your code here
}

void functionB()
{
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
