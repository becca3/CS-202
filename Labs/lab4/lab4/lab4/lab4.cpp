#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv)
{
	std::string line;
	int x;
	std::ifstream readFile("book.txt");

	if (readFile.is_open())
	{
		while (std::getline(readFile, line))
		{
			std::cout << line << '\n';
		}
	}

	std::cout << "Enter a line of text: \n";
	std::getline(std::cin, line);

	std::cout << "Enter the number of times for that line to be appended: ";
	std::cin >> x;

	std::ofstream file;
	file.open("book.txt", std::ios_base::app);

	for (int i = 0; i < x; i++)
	{
		file << line << "\n";
	}

	file.close();
	return 0;
}