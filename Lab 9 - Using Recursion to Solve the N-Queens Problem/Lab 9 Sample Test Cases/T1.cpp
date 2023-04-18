#include <iostream>

int nQueens(int n);

int main()
{
    int test = nQueens(1);
    //ASSERT_EQ(nQueens(1),1);
    if (test != 1)
    {
        std::cout << "expected/correct value for nQueens(1) is 1, actual value when testing " << test << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}