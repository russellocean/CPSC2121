#include <iostream>
#include <string>

using namespace std;

int infixToPostfix(string infix[], int length, string postfix[]);

int main()
{
    string infixExp[] = {"5", "+", "42", "/", "(", "30", "/",
                         "(", "20", "/", ")", "12", "/", ")",
                         "6", "/", ")", "4", "/", "2", "(",
                         "(", "(", ")", ")"}; //right parenthesis without matching left parenthesis
    string postfixExp[24] = {"5", "42", "30", "20", "12", "6", "4",
                             "2", "/", "/", "/", "/", "/", "/",
                             "+"};
    string postfixTest[24];
    int postfixLength = infixToPostfix(infixExp, 25, postfixTest);

    //ASSERT_EQ(postfixLength, 0);
    if (postfixLength != 0)
    {
        cout << "expected/correct value for postfixLength 0, actual value when testing " << postfixLength << ".\n";
        return 1;
    }
    cout << "Passed" << endl;
    return 0;
}