#include <iostream>

int nQueens(int n);

int main()
{
    int test = nQueens(4);
    //ASSERT_EQ(nQueens(4),2);
    if (test != 2)
    {
        std::cout << "expected/correct value for nQueens(4) is 2, actual value when testing " << test << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}