#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    List<string> list2;
    string s[] = {"Sisko", "Janeway", "Picard", "Kirk", "Zoey", "Frodo"};
    for(int i = 0; i < 6; i++) {
        list2.insertEnd(s[i]);
    }
    list2.insertAt("Worf", 2);

    // This can be an ofstream as well or any other ostream
    stringstream buffer;

    // Save cout's buffer here
    streambuf *sbuf = cout.rdbuf();

    // Redirect cout to our stringstream buffer or any other ostream
    cout.rdbuf(buffer.rdbuf());

    // Use cout as usual
    // cout << "Hello World";
    list2.print("list2-b");

    string test[7];
    string bob;
    // This section skips the info printout 
    // section of the print function
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;

    string test2[] = {"Sisko", "Janeway", "Worf", "Picard", "Kirk", "Zoey", "Frodo"};
    for (int i=0; i<7;i++){
        buffer >> bob;
        test[i] = bob;
        cout << bob << endl;
        // ASSERT_STREQ(test[i],test2[i]);
    }

    // When done redirect cout to its old self
    cout.rdbuf(sbuf);

    for (int i=0; i<7; i++)
    {
        if (test[i] != test2[i])
        {
            cout << "Mismatch at position " << i << ": expected/correct value " << test2[i] << ", actual value when testing " << test[i] << ".\n";
            return 1;
        }
    }
    cout << "Passed" << endl;
    return 0;
}