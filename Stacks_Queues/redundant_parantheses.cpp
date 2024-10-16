#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperator(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return true;
    }

    return false;
}

bool hasRedundantParantheses(string exp)
{
    stack<char> stk;
    for (auto ch : exp)
    {
        if (ch == ')')
        {
            bool operatorFound = false;
            while (stk.top() != '(')
            {
                if (isOperator(stk.top()))
                {
                    operatorFound = true;
                }
                stk.pop();
            }
            stk.pop();
            if (!operatorFound)
            {
                return true;
            }
        }
        else
        {
            stk.push(ch);
        }
    }
    return false;
}

int main()
{

    string exp;
    getline(cin, exp);
    string ans = hasRedundantParantheses(exp) ? "YES" : "NO";
    cout << "Has redundant parantheses? " << ans;
}