#include <iostream>
#include <string>

using namespace std;

int infixToPostfix(string infix[], int length, string postfix[]);

int main()
{
    string infixExp[] = {"5", "+", "42", "/", "(", "30", "/",
                         "(", "20", "/", "(", "12", "/", "(",
                         "6", "/", "(", "4", "/", "2", ")",
                         ")", ")", ")", ")", ")"}; //one more right parenthesis
    string postfixExp[26] = {"5", "42", "30", "20", "12", "6", "4",
                             "2", "/", "/", "/", "/", "/", "/",
                             "+"};
    string postfixTest[26];
    int postfixLength = infixToPostfix(infixExp, 26, postfixTest);

    //ASSERT_EQ(postfixLength, 0);
    if (postfixLength != 0)
    {
        cout << "expected/correct value for postfixLength 0, actual value when testing " << postfixLength << ".\n";
        return 1;
    }
    cout << "Passed" << endl;
    return 0;
}