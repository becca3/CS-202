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
  functionB();
  // your code here
  std::cout << "Caught an exception: " << e.what() << std::endl;
  // your code here
}

int main()
{
  std::cout << "Starting main()" << std::endl;
  functionA();
  std::cout << "Ended normally." << std::endl;
  return 0;
}
