#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isParenthesesBalanced(string exp)
{

    stack<char> stk;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '[' or exp[i] == '(' or exp[i] == '{')
        {
            stk.push(exp[i]);
        }
        else if (exp[i] == ']' and !stk.empty() and '[' == stk.top())
        {
            stk.pop();
        }
        else if (exp[i] == ')' and !stk.empty() and '(' == stk.top())
        {
            stk.pop();
        }
        else if (exp[i] == '}' and !stk.empty() and '{' == stk.top())
        {
            stk.pop();
        }
        else if (exp[i] == ']' or exp[i] == ')' or exp[i] == '}')
        {
            return false;
        }
    }
    return stk.empty();
}

int main()
{

    string exp;
    getline(cin, exp);

    string ans = isParenthesesBalanced(exp) ? "YES" : "NO";
    cout << "Is Parentheses Balanced? " << ans;
}