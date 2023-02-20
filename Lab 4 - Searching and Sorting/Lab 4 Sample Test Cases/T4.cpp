#include <iostream>
#include <vector>
#include "Searches.h"

int main()
{
    std::vector<double> doubleTest{ 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0};
    int a = linearSearch(doubleTest, 2.0);
    //ASSERT_EQ(a,9);
    if (a != 9)
    {
        std::cout << "expected/correct value for a is 9, actual value when testing " << a << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}