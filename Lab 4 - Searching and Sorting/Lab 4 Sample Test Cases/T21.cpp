#include <iostream>
#include <vector>
#include <string>

//using testing::ElementsAreArray;

#include "Sorts.h"

int main()
{
    std::vector<std::string> stringTest {"earthlings","greetings","leader","me","take","to","yall","your"};
    std::vector<std::string> stringTest2 {"greetings", "yall", "earthlings", "take", "me", "to", "your", "leader"};
    std::vector<std::string> a = quickSort(stringTest2);

    //ASSERT_THAT(a, ElementsAreArray(stringTest));
    for (int i=0; i<8; i++)
    {
        if (a[i] != stringTest[i])
        {
            std::cout << "Mismatch at position " << i << ": expected/correct value " << stringTest[i] << ", actual value when testing " << a[i] << ".\n";
            return 1;
        }
    }
    std::cout << "Passed" << std::endl;
    return 0;
}