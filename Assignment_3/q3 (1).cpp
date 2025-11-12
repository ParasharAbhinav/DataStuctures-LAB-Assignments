#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')')
        return true;
    else if (char1 == '{' && char2 == '}')
        return true;
    else if (char1 == '[' && char2 == ']')
        return true;
    else
        return false;
}

bool areParenthesesBalanced(string expr) {
    stack<char> s;
    for (char ch : expr) {

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {
  
            if (s.empty()) {
                return false;
            }
 
            if (!isMatchingPair(s.top(), ch)) {
                return false;
            }
            s.pop(); 
        }
    }

    return s.empty();
}

int main() {
    string expr1 = "{[()]}";
    string expr2 = "([{}])";
    string expr3 = "([)]";
    string expr4 = "{[()";

    cout << expr1 << ": " << (areParenthesesBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << expr2 << ": " << (areParenthesesBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;
    cout << expr3 << ": " << (areParenthesesBalanced(expr3) ? "Balanced" : "Not Balanced") << endl;
    cout << expr4 << ": " << (areParenthesesBalanced(expr4) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}
