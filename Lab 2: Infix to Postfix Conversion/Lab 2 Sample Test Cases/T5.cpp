#include <iostream>
#include <string>

using namespace std;

int infixToPostfix(string infix[], int length, string postfix[]);

int main()
{
    string infixExp[] = {"2", "+", "3", "*", "4", "-", "10",
                         "/", "5", "%", "3"};
    string postfixExp[11] = {"2", "3", "4", "*", "+", "10", "5",
                             "/", "3", "%", "-"};
    string postfixTest[11];
    int postfixLength = infixToPostfix(infixExp, 11, postfixTest);

    //ASSERT_THAT(postfixExp, ElementsAreArray(postfixTest));
    for (int i=0; i<11; i++)
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