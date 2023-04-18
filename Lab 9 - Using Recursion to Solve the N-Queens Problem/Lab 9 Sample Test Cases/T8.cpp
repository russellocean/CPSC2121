#include <iostream>

int nQueens(int n);

int main()
{
    int test = nQueens(8);
    //ASSERT_EQ(nQueens(8),92);
    if (test != 92)
    {
        std::cout << "expected/correct value for nQueens(8) is 92, actual value when testing " << test << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}