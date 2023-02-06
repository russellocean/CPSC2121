#include <iostream>
#include <string>

using namespace std;

int infixToPostfix(string infix[], int length, string postfix[]);

int main()
{
    string infixExp[] = {"5", "+", "42", "/", "(", "30", "/",
                         "(", "20", "/", "(", "12", "/", "(",
                         "6", "/", "(", "4", "/", "2", ")",
                         ")", ")", ")", ")"};
    string postfixExp[25] = {"5", "42", "30", "20", "12", "6", "4",
                             "2", "/", "/", "/", "/", "/", "/",
                             "+"};
    string postfixTest[25];
    int postfixLength = infixToPostfix(infixExp, 25, postfixTest);

    //ASSERT_THAT(postfixExp, ElementsAreArray(postfixTest));
    for (int i=0; i<25; i++)
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