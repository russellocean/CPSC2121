#include <iostream>
#include <string>

using namespace std;

int infixToPostfix(string infix[], int length, string postfix[]);

int main()
{
    string infixExp[] = {"2", "*", "(", "3", "+", "4", "*",
                         "(", "5", "+", "6", "/", "2", ")",
                         "+", "7", ")", "-", "8", "*", "9",
                         "%", "10"};
    string postfixExp[23] = {"2", "3", "4", "5", "6", "2", "/",
                             "+", "*", "+", "7", "+", "*", "8",
                             "9", "*", "10", "%", "-"};
    string postfixTest[23];
    int postfixLength = infixToPostfix(infixExp, 23, postfixTest);

    //ASSERT_THAT(postfixExp, ElementsAreArray(postfixTest));
    for (int i=0; i<23; i++)
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