#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    List<char> list3;
    if (list3.empty() != true)
    {
        cout << "expected/correct value true, actual value when testing " << list3.empty() << ".\n";
        return 1;
    }

    char c[] = {'z', 'p', 'r', 'p', 'd', 'a', 'h', 'q', 'o', 'r', 'r', 'r'};
    for(int i = 0; i < 12; i++){
        list3.insertEnd(c[i]);
    }

    if (list3.find('r') != 2)
    {
        cout << "expected/correct value 2, actual value when testing " << list3.find('r') << ".\n";
        return 1;
    }
    cout << "Passed" << endl;
    return 0;
}