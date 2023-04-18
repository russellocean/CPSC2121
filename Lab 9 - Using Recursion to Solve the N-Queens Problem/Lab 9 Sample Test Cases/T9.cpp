#include <iostream>

int nQueens(int n);

int main()
{
    int test = nQueens(9);
    //ASSERT_EQ(nQueens(9),352);
    if (test != 352)
    {
        std::cout << "expected/correct value for nQueens(9) is 352, actual value when testing " << test << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}