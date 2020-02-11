#include<iostream>
#include<fstream>

int read_bin_value()
{
    std::fstream bin_in("data.dat", std::ios_base::binary | std::ios::app | std::ios_base::in);
    long long value;
    bin_in.read((char*)&value, sizeof(int));
    return value;
}

int main()
{
    std::cout << "Reading binary file value as integer: " << read_bin_value() << std::endl;
    return 0;
}