#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    List<int> list1;
    for (int i=1, j = 1; i <= 10; i++){
        j = -2*j;
        list1.insertEnd(j);
    }
    list1.removeStart();

    // This can be an ofstream as well or any other ostream
    stringstream buffer;

    // Save cout's buffer here
    streambuf *sbuf = cout.rdbuf();

    // Redirect cout to our stringstream buffer or any other ostream
    cout.rdbuf(buffer.rdbuf());

    // Use cout as usual
    // cout << "Hello World";

    list1.print("list");

    int test[9];
    string bob;
    // This section skips the info printout 
    // section of the print function
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;

    int test2[] = {4,-8,16,-32,64,-128,256,-512,1024};
    for (int i=0; i<9;i++){
        buffer >> bob;
        test[i] = stoi(bob);
        // ASSERT_EQ(test[i],test2[i]);
    }

    // When done redirect cout to its old self
    cout.rdbuf(sbuf);

    for (int i=0; i<9; i++)
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