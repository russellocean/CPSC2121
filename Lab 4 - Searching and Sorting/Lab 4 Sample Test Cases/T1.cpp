#include <iostream>
#include <vector>
#include "Searches.h"

int main()
{
    std::vector<int> intTest {1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55};
    int a = linearSearch(intTest, 20);
    //ASSERT_EQ(a,4);
    if (a != 4)
    {
        std::cout << "expected/correct value for a is 4, actual value when testing " << a << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}