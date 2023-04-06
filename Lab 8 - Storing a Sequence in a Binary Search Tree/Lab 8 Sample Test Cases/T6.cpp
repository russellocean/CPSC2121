#include <vector>
#include <cstdlib>
#include <algorithm>

#include "bstSequence.h"

//using testing::ElementsAreArray;

int main()
{
    Node *T = nullptr;
    std::vector<int> test;
    for (int i=1; i<=1000000; i++) test.push_back(i);
    for (int i=0; i<1000000; i++) T = insert_random(T, test[i], T?T->size/2:0);
    std::vector<int> test2;
    for (int i=1; i<=500000; i++) test2.push_back(i*2);
    for (int i=500000; i>=1; i--) test2.push_back(i*2-1);
    std::vector<int> inorder = inorder_traversal(T);

    //ASSERT_THAT(inorder, ElementsAreArray(test2));
    for (int i=0; i<1000000; i++)
    {
        if (inorder[i] != test2[i])
        {
            std::cout << "Mismatch at position " << i << ": expected/correct value " << test2[i] << ", actual value when testing " << inorder[i] << ".\n";
            return 1;
        }
    }
    std::cout << "Passed" << std::endl;
    return 0;
}