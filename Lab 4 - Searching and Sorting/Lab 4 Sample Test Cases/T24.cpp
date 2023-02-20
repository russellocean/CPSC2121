#include <iostream>
#include <vector>

//using testing::ElementsAreArray;

#include "Sorts.h"

int main()
{
    std::vector<int> intTest {1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55};
    std::vector<int> intTest2 {25, 55, 45, 30, 10, 1, 50, 35, 15, 5, 20, 40};
    std::vector<int> a = quickSort(intTest2);

    //ASSERT_THAT(a, ElementsAreArray(intTest));
    for (int i=0; i<12; i++)
    {
        if (a[i] != intTest[i])
        {
            std::cout << "Mismatch at position " << i << ": expected/correct value " << intTest[i] << ", actual value when testing " << a[i] << ".\n";
            return 1;
        }
    }
    std::cout << "Passed" << std::endl;
    return 0;
}