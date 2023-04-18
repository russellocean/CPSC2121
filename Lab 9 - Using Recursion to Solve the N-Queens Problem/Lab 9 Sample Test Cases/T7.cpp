#include <iostream>

int nQueens(int n);

int main()
{
    int test = nQueens(7);
    //ASSERT_EQ(nQueens(7),40);
    if (test != 40)
    {
        std::cout << "expected/correct value for nQueens(7) is 40, actual value when testing " << test << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}