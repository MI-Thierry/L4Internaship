#include <iostream>

int main()
{
    float length = 0.0f;
    float width = 0.0f;

    std::cout << "Enter the length: ";
    std::cin >> length;
    std::cout << "Enter the width: ";
    std::cin >> width;

    float area = length * width;
    std::cout << "The area of rectangle is: " << area << " cm\n";
    std::cin.get();
}