#include <iostream>
#include <vector>

//using testing::ElementsAreArray;

#include "Sorts.h"

int main()
{
    std::vector<char> charTest{'A', 'B', 'C', 'D', 'E', 'a', 'b', 'c', 'd', 'e'};
    std::vector<char> charTest2 {'D', 'b', 'c', 'A', 'e', 'E', 'B', 'C', 'a', 'd'};
    std::vector<char> a = mergeSort(charTest2);

    //ASSERT_THAT(a, ElementsAreArray(charTest));
    for (int i=0; i<10; i++)
    {
        if (a[i] != charTest[i])
        {
            std::cout << "Mismatch at position " << i << ": expected/correct value " << charTest[i] << ", actual value when testing " << a[i] << ".\n";
            return 1;
        }
    }
    std::cout << "Passed" << std::endl;
    return 0;
}