#include <iostream>
#include <vector>
#include "Searches.h"

int main()
{
    std::vector<double> doubleTest{ 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0};
    int a = binarySearch(doubleTest, 10.1);
    //ASSERT_EQ(a,-1);
    if (a != -1)
    {
        std::cout << "expected/correct value for a is -1, actual value when testing " << a << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}