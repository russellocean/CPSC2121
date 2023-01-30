#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    List<char> list3;
    char c[] = {'z', 'p', 'r', 'p', 'd', 'a', 'h', 'q', 'o', 'r', 'r', 'r'};
    for(int i = 0; i < 12; i++){
        list3.insertEnd(c[i]);
    }

    if (list3.getFirst() != 'z')
    {
        cout << "expected/correct value 'z', actual value when testing " << list3.getFirst() << ".\n";
        return 1;
    }
    cout << "Passed" << endl;
    return 0;
}