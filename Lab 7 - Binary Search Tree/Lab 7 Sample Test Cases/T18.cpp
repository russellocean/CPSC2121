#include <vector>
#include <cstdlib>
#include <algorithm>

#include "binarySearchTree.h"

//using testing::ElementsAreArray;

int main()
{
    Node *T = nullptr;
    for (int i=0; i<1000000; i++) T = insert_random(T, i);
    std::vector<int> inorder = inorder_traversal(T);

    //ASSERT_EQ(inorder.size(), 1000000);
    if (inorder.size() != 1000000)
    {
        std::cout << "expected/correct value for inorder.size() is 1000000, actual value when testing " << inorder.size() << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}