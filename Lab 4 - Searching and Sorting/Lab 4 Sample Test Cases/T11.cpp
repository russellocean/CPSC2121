#include <iostream>
#include <vector>
#include "Searches.h"

int main()
{
    std::vector<char> charTest{'A', 'B', 'C', 'D', 'E', 'a', 'b', 'c', 'd', 'e'};
    int a = binarySearch(charTest, 'b');
    //ASSERT_EQ(a,6);
    if (a != 6)
    {
        std::cout << "expected/correct value for a is 6, actual value when testing " << a << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}