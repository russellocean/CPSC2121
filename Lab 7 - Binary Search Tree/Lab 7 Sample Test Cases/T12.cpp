#include <vector>

#include "binarySearchTree.h"

//using testing::ElementsAreArray;

int main()
{
    Node *T = nullptr;
    std::vector<int> test{7, 3, 2, 9, 4, 8, 5, 6, 10, 1};
    for (int i=0; i<10; i++) T = insert(T, test[i]);

    Node *L = nullptr;
    Node *R = nullptr;

    split(T, 5, &L, &R);

    std::vector<int> testL{1, 2, 3, 4, 5};
    std::vector<int> testR{6, 7, 8, 9, 10};
    std::vector<int> inorderL = inorder_traversal(L);
    std::vector<int> inorderR = inorder_traversal(R);

    //ASSERT_THAT(inorderL, ElementsAreArray(testL));
    for (int i=0; i<5; i++)
    {
        if (inorderL[i] != testL[i])
        {
            std::cout << "Mismatch in testL at position " << i << ": expected/correct value " << testL[i] << ", actual value when testing " << inorderL[i] << ".\n";
            return 1;
        }
    }
    //ASSERT_THAT(inorderR, ElementsAreArray(testR));
    for (int i=0; i<5; i++)
    {
        if (inorderR[i] != testR[i])
        {
            std::cout << "Mismatch in testR at position " << i << ": expected/correct value " << testR[i] << ", actual value when testing " << inorderR[i] << ".\n";
            return 1;
        }
    }
    std::cout << "Passed" << std::endl;
    return 0;
}