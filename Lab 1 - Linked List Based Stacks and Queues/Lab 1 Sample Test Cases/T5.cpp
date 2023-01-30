#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    List<string> list2;
    string s[] = {"Sisko", "Janeway", "Picard", "Kirk", "Zoey", "Frodo"};
    for(int i = 0; i < 6; i++) {
        list2.insertEnd(s[i]);
    }

    if (list2.size() != 6)
    {
        cout << "expected/correct value 6, actual value when testing " << list2.size() << ".\n";
        return 1;
    }
    cout << "Passed" << endl;
    return 0;
}