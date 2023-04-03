#include <vector>
#include <cstdlib>
#include <algorithm>

#include "binarySearchTree.h"

//using testing::ElementsAreArray;

int main()
{
    Node *T = nullptr;
    std::vector<int> test;
    for (int i=0; i<10; i++) test.push_back(i);
    for (int i=9; i>0; i--) swap(test[i], test[rand()%i]);
    for (int i=0; i<10; i++) T = insert(T, test[i]);
    std::vector<int> test2;
    for (int i=0; i<10; i++) test2.push_back(i);
    std::vector<int> inorder = inorder_traversal(T);

    Node *found = find(T, 5);
    //ASSERT_NE(found, nullptr);
    if (found == nullptr)
    {
        std::cout << "found = find(T, 5): found expected to be a valid pointer, found is null (found == nullptr).\n";
        return 1;
    }
    //ASSERT_EQ(found->key, 5);
    if (found->key != 5)
    {
        std::cout << "expected/correct value for found->key is 5, actual value when testing " << found->key << ".\n";
        return 1;
    }
    std::cout << "Passed" << std::endl;
    return 0;
}