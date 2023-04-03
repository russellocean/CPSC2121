#include <vector>
#include <cstdlib>
#include <algorithm>

#include "binarySearchTree.h"

//using testing::ElementsAreArray;

int main()
{
    Node *T = nullptr;
    std::vector<int> test;
    for (int i=0; i<1000; i++) test.push_back(i);
    for (int i=999; i>0; i--) swap(test[i], test[rand()%i]);
    for (int i=0; i<1000; i++) T = insert(T, test[i]);
    std::vector<int> test2;
    for (int i=0; i<144; i++) test2.push_back(i);
    for (int i=145; i<233; i++) test2.push_back(i);
    for (int i=234; i<377; i++) test2.push_back(i);
    for (int i=378; i<610; i++) test2.push_back(i);
    for (int i=611; i<987; i++) test2.push_back(i);
    for (int i=988; i<1000; i++) test2.push_back(i);
    remove(T, 144);
    remove(T, 233);
    remove(T, 377);
    remove(T, 610);
    remove(T, 987);
    std::vector<int> inorder = inorder_traversal(T);

    //ASSERT_THAT(inorder, ElementsAreArray(test2));
    for (int i=0; i<995; i++)
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