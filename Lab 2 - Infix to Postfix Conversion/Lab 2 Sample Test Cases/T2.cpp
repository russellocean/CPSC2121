#include <iostream>
#include <string>

using namespace std;

int infixToPostfix(string infix[], int length, string postfix[]);

int main()
{
    string infixExp[] = {"2", "+", "3", "*", "5"};
    string postfixExp[] = {"2", "3", "5", "*", "+"};
    string postfixTest[5];
    int postfixLength = infixToPostfix(infixExp, 5, postfixTest);

    //ASSERT_THAT(postfixExp, ElementsAreArray(postfixTest));
    for (int i=0; i<5; i++)
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