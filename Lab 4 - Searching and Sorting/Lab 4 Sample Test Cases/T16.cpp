#include <iostream>
#include <vector>
#include "Searches.h"

int main()
{
    std::vector<int> intTest {1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55};
    int a = binarySearch(intTest, 45);
    //ASSERT_EQ(a,9);
    if (a != 9)
    {
        std::cout << "expected/correct value for a is 9, actual value when testing " << a << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}