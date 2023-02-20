#include <iostream>
#include <vector>
#include "Searches.h"

int main()
{
    std::vector<char> charTest{'A', 'B', 'C', 'D', 'E', 'a', 'b', 'c', 'd', 'e'};
    int a = linearSearch(charTest, 'c');
    //ASSERT_EQ(a,7);
    if (a != 7)
    {
        std::cout << "expected/correct value for a is 7, actual value when testing " << a << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}