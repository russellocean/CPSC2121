#include <vector>
#include <cstdlib>

#include "bstSequence.h"

int main()
{
    int N = 100000; // this should run quickly even for very large N!
    Node *S = order_n_teams(N);
    //ASSERT_NE(S, nullptr);
    if (S == nullptr)
    {
        std::cout << "S = order_n_teams(100000): S expected to be a valid pointer, S is null (S == nullptr).\n";
        return 1;
    }
    //ASSERT_EQ(S->size, N);
    if (S->size != N)
    {
        std::cout << "expected/correct value for S->size is 100000, actual value when testing " << S->size << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}