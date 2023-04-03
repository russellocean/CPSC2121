#include <vector>

#include "binarySearchTree.h"

//using testing::ElementsAreArray;

int main()
{
    Node *T = nullptr;
    std::vector<int> test{5, 13, 2, 19, 3, 29, 11, 7, 17, 23};
    for (int i=0; i<10; i++) T = insert_random(T, test[i]);
    std::vector<int> inorder = inorder_traversal(T);

    Node *val = select(T, 9);
    //ASSERT_NE(val, nullptr);
    if (val == nullptr)
    {
        std::cout << "val = select(T, 9): val expected to be a valid pointer, val is null (val == nullptr).\n";
        return 1;
    }
    //ASSERT_EQ(val->key, 29);
    if (val->key != 29)
    {
        std::cout << "expected/correct value for val->key is 29, actual value when testing " << val->key << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}