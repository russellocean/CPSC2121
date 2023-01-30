#include "ListStack.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ListStack<char> stack3;
    char c[] = {'m', 'l', 'k', 'j', 'i', 'h', 'e', 'c', 'b', 'a', 'p', 'z'};
    for(int i = 0; i < 12; i++){
        stack3.push(c[i]);
    }
    stack3.print("list");

    // This can be an ofstream as well or any other ostream
    stringstream buffer;

    // Save cout's buffer here
    streambuf *sbuf = cout.rdbuf();

    // Redirect cout to our stringstream buffer or any other ostream
    cout.rdbuf(buffer.rdbuf());

    // Use cout as usual
    // cout << "Hello World";

    stack3.print("list");

    char test[12];
    char test2[] = {'z', 'p', 'a', 'b', 'c', 'e', 'h', 'i', 'j', 'k', 'l', 'm'};
    string bob;
    // This section skips the info printout 
    // section of the print function
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;

    for (int i=0; i<12;i++){
        buffer >> bob;
        // test[i] = stoi(bob);
        test[i] = bob.at(0);
    }


    // When done redirect cout to its old self
    cout.rdbuf(sbuf);

    for (int i=0; i<12; i++)
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