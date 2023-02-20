#include <iostream>
#include <vector>

//using testing::ElementsAreArray;

#include "Sorts.h"

int main()
{
    std::vector<double> doubleTest{ 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9};
    std::vector<double> doubleTest2 { 1.6, 1.2, 1.1, 1.5, 1.9, 1.3, 1.7, 1.4, 1.8};
    std::vector<double> a = quickSort(doubleTest2);

    //ASSERT_THAT(a, ElementsAreArray(doubleTest));
    for (int i=0; i<9; i++)
    {
        if (a[i] != doubleTest[i])
        {
            std::cout << "Mismatch at position " << i << ": expected/correct value " << doubleTest[i] << ", actual value when testing " << a[i] << ".\n";
            return 1;
        }
    }
    std::cout << "Passed" << std::endl;
    return 0;
}