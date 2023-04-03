#include <vector>

#include "binarySearchTree.h"

//using testing::ElementsAreArray;

int main()
{
    Node *L = nullptr;
    std::vector<int> testL{3, 2, 1, 5, 4};
    for (int i=0; i<5; i++) L = insert(L, testL[i]);
    Node *R = nullptr;
    std::vector<int> testR{9, 6, 8, 10, 7};
    for (int i=0; i<5; i++) R = insert(R, testR[i]);
    Node *T = join(L, R);
    std::vector<int> inorder = inorder_traversal(T);
    std::vector<int> test{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //ASSERT_THAT(inorder, ElementsAreArray(test));
    for (int i=0; i<10; i++)
    {
        if (inorder[i] != test[i])
        {
            std::cout << "Mismatch at position " << i << ": expected/correct value " << test[i] << ", actual value when testing " << inorder[i] << ".\n";
            return 1;
        }
    }
    std::cout << "Passed" << std::endl;
    return 0;
}