/*
 * Name: Russell Welch
 * Date Submitted: 02/06/2023
 * Lab Section: 001
 * Assignment Name: Infix to Postfix Conversion
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Function to check if the character is an operator symbol
bool isOperator(char c) {
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(' || c == ')')
    return true;
  return false;
}

// Function to check the precedence of the operator
int precedence(char c) {
  if (c == '+' || c == '-')
    return 1;
  else if (c == '*' || c == '/' || c == '%')
    return 2;
  return 0;
}

//Converts an infix arithmetic expression into postfix
//The function takes 3 parameters
//First parameter: array of strings for infix expression
//    each string is either an integer number or operator symbol
//Second parameter: number of strings in infix expression
//Third parameter: array of strings for postfix expression
//    generated by function, same format as first parameter
//    assumes that postfix is at least the size of postfix
//Return value: int, number of strings in postfix expression
//    Returns 0 if an error is encountered when converting expression
//    An error occurs with a mismatched parenthesis, e.g. ( ( ) or ( ) ) etc.
//Operator symbols:
// ( : left parenthesis, all operations between this and ")" take place first
// ) : right parenthesis, all op.s back to previous "(" take place first
// * : multiplication, higher precedence - takes place before "+" and "-"
// / : division, higher precedence - takes place before "+" and "-"
// % : remainder, higher precedence - takes place before "+" and "-"
// + : addition, lower precedence - takes place after "*" , "/" , "%"
// - : subtraction, lower precedence - takes place after "*" , "/" , "%"
//The function is not specified to work with any other operator symbols
//Any string in infix may be assumed to be an integer operand if none
// of the above symbols
int infixToPostfix(string infix[], int length, string postfix[]) {
  stack<char> s;
  int j = 0;

  // Count the number of left and right parentheses in the expression
  int left_count = 0, right_count = 0;
  for (int i = 0; i < length; i++)
  {
    if (infix[i] == "(")
      left_count++;
    if (infix[i] == ")")
      right_count++;
  }

  // Check that the number of left parentheses is equal to the number of right parentheses
  if (left_count != right_count)
    return 0;

  for (int i = 0; i < length; i++) {
    // If the current character is an operand, add it to the postfix array
    if (!isOperator(infix[i][0]))
      postfix[j++] = infix[i];

    // If the current character is a left parenthesis, push it to the stack
    else if (infix[i][0] == '(')
      s.push(infix[i][0]);

    // If the current character is a right parenthesis, pop the stack until a left parenthesis is encountered
    else if (infix[i][0] == ')') {
      if (s.empty()) {
        return 0;
      }
      while (s.top() != '(') {
        postfix[j++] = string(1, s.top());
        s.pop();
        if (s.empty()) {
          return 0;
        }
      }
      s.pop();
    } else {
      // If the current character is an operator
      while (!s.empty() && precedence(s.top()) >= precedence(infix[i][0])) {
        postfix[j++] = string(1, s.top());
        s.pop();
      }
      s.push(infix[i][0]);
    }
  }
  
  // Pop any remaining operators from the stack and add them to the postfix array
  while (!s.empty()) {
    postfix[j++] = string(1, s.top());
    s.pop();
  }

  // Return the length of the postfix array
  return j;
}

//Main function to test infixToPostfix()
//Should convert 2 + 3 * 4 + ( 5 - 6 + 7 ) * 8
//            to 2 3 4 * + 5 6 - 7 + 8 * +
// int main()
// {
//     string infixExp[] = {"2", "+", "3", "*", "4", "+", "(",
//                          "5", "-", "6", "+", "7", ")", "*",
//                          "8"};
//     string postfixExp[15];
//     int postfixLength;

//     cout << "Infix expression: ";
//     for (int i=0; i<15; i++)
//     {
//         cout << infixExp[i] << " ";
//     }
//     cout << endl;
//     cout << "Length: 15" << endl << endl;

//     postfixLength = infixToPostfix(infixExp, 15, postfixExp);

//     cout << "Postfix expression: ";
//     for (int i=0; i<postfixLength; i++)
//     {
//         cout << postfixExp[i] << " ";
//     }
//     cout << endl;
//     cout << "Length: " << postfixLength << endl;
    
//     return 0;
// }