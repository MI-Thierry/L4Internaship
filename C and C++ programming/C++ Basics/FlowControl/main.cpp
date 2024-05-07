#include <iostream>

int main()
{
    unsigned age = 0;
    std::cout << "Enter your age: ";
    std::cin >> age;

    if (age < 10)
    {
        std::cout << "You're a kid." << std::endl;
    }
    else if (age < 20)
    {
        std::cout << "You're a teenager." << std::endl;
    }
    else
    {
        std::cout << "You're an adult." << std::endl;
    }
    std::cin.get();
}