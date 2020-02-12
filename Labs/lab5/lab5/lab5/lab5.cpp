#include<iostream>
#include<fstream>

int main()
{
	std::streampos size;
	char* memblock;

	std::ifstream fileName("data.dat", std::ios::in | std::ios::binary | std::ios::ate);

	if (fileName.is_open())
	{
		size = fileName.tellg();
		memblock = new char[size];
		fileName.seekg(0, std::ios::beg);
		fileName.read(memblock, size);
		fileName.close();
		std::cout << memblock;

		delete[] memblock;
	}

    return 0;
}