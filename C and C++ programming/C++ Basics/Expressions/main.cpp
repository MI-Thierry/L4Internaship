#include <iostream>

int main()
{
    int sum = 2 + 2;
    sum += 5;
    sum++;

    std::cout << "The sum is: " << sum << std::endl;
    std::cin.get();
}