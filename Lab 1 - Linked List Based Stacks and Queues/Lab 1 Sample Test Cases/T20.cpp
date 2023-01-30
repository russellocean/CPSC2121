#include "ListQueue.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ListQueue<int> queue1;
    queue1.print("queue1");
    for(int i = 1, j = 1; i <= 10; i++){
        j = -2 * j;
        queue1.enqueue(j);
    }

    queue1.dequeue();
    queue1.dequeue();
    queue1.dequeue();

    // This can be an ofstream as well or any other ostream
    stringstream buffer;

    // Save cout's buffer here
    streambuf *sbuf = cout.rdbuf();

    // Redirect cout to our stringstream buffer or any other ostream
    cout.rdbuf(buffer.rdbuf());

    // Use cout as usual
    // cout << "Hello World";

    queue1.print("queue1-b");

    int test[7];
    string bob;
    // This section skips the info printout 
    // section of the print function
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;

    int test2[] = {16,-32,64,-128,256,-512,1024};
    for (int i=0; i<7;i++){
        buffer >> bob;
        test[i] = stoi(bob);
        // ASSERT_EQ(test[i],test2[i]);
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