#include <iostream>
#include <vector>
#include "Searches.h"

int main()
{
    std::vector<char> charTest{'A', 'B', 'C', 'D', 'E', 'a', 'b', 'c', 'd', 'e'};
    int a = binarySearch(charTest, 'q');
    //ASSERT_EQ(a,-1);
    if (a != -1)
    {
        std::cout << "expected/correct value for a is -1, actual value when testing " << a << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}