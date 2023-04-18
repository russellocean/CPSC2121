#include <iostream>

int nQueens(int n);

int main()
{
    int test = nQueens(11);
    //ASSERT_EQ(nQueens(11),2680);
    if (test != 2680)
    {
        std::cout << "expected/correct value for nQueens(11) is 2680, actual value when testing " << test << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}