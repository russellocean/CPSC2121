#include <iostream>
#include <vector>
#include "Searches.h"

int main()
{
    std::vector<int> intTest {1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55};
    int a = binarySearch(intTest, 10);
    //ASSERT_EQ(a,2);
    if (a != 2)
    {
        std::cout << "expected/correct value for a is 2, actual value when testing " << a << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}