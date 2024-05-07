#include <iostream>

int main()
{
    bool boolean = false;
    unsigned char letter = 'a';
    unsigned short smallNum = 256;
    unsigned int mediumNum = 7573485;
    long long largeNum = -1;
    float smallDecimal = 3.141f;
    double largetDecimal = 3.14159265;

    std::cout << "Size of bool is: " << sizeof(bool) << " byte\n";
    std::cout << "Size of char is: " << sizeof(char) << " byte\n";
    std::cout << "Size of short is: " << sizeof(short) << " bytes\n";
    std::cout << "Size of int is: " << sizeof(int) << " bytes\n";
    std::cout << "Size of long is: " << sizeof(long) << " bytes\n";
    std::cout << "Size of long long is: " << sizeof(long long) << " bytes\n";
    std::cout << "Size of float is: " << sizeof(float) << " bytes\n";
    std::cout << "Size of double is: " << sizeof(double) << " bytes\n";

    std::cin.get();
}