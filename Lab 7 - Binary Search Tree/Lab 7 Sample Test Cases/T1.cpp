#include <vector>
#include <cstdlib>
#include <algorithm>

#include "binarySearchTree.h"

//using testing::ElementsAreArray;

int main()
{
    Node *T = nullptr;
    std::vector<int> test{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i=9; i>0; i--) swap(test[i], test[rand()%i]);
    for (int i=0; i<10; i++) T = insert_random(T, test[i]);
    std::vector<int> test2{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> inorder = inorder_traversal(T);

    //ASSERT_THAT(inorder, ElementsAreArray(test2));
    for (int i=0; i<10; i++)
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