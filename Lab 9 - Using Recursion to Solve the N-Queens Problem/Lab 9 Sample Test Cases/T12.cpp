#include <iostream>

int nQueens(int n);

int main()
{
    int test = nQueens(12);
    //ASSERT_EQ(nQueens(12),14200);
    if (test != 14200)
    {
        std::cout << "expected/correct value for nQueens(12) is 14200, actual value when testing " << test << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}