#include <iostream>
#include <string>

using namespace std;

int infixToPostfix(string infix[], int length, string postfix[]);

int main()
{
    string infixExp[] = {"2", "+", "3", "*", "4", "+", "(",
                         "5", "*", "6", "+", "7", ")", "*", "8"};
    string postfixExp[15] = {"2", "3", "4", "*", "+", "5", "6",
                             "*", "7", "+", "8", "*", "+"};
    string postfixTest[15];
    int postfixLength = infixToPostfix(infixExp, 15, postfixTest);

    //ASSERT_THAT(postfixExp, ElementsAreArray(postfixTest));
    for (int i=0; i<15; i++)
    {
        if (postfixTest[i] != postfixExp[i])
        {
            cout << "Mismatch at position " << i << ": expected/correct value " << postfixExp[i] << ", actual value when testing " << postfixTest[i] << ".\n";
            return 1;
        }
    }
    cout << "Passed" << endl;
    return 0;
}