#include <iostream>

int main()
{
    int age = 18;
    int* agePtr = &age;

    std::cout << agePtr << std::endl;
    std::cout << &age << std::endl;
}