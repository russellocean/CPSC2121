#include <iostream>

int nQueens(int n);

int main()
{
    int test = nQueens(2);
    //ASSERT_EQ(nQueens(2),0);
    if (test != 0)
    {
        std::cout << "expected/correct value for nQueens(2) is 0, actual value when testing " << test << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}