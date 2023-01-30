#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    List<int> list1;
    list1.print("list1");
    for(int i = 1, j = 1; i <= 10; i++){
        j = -2 * j;
        list1.insertStart(j);
    }
    list1.removeEnd();

    if (list1.find(-2) != -1)
    {
        cout << "expected/correct value -1, actual value when testing " << list1.find(-2) << ".\n";
        return 1;
    }
    cout << "Passed" << endl;
    return 0;
}