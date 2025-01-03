#include <iostream>
#include <stack>


using namespace std;


int checkPre(char op)
{
    if(op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

string conversion(string exp)
{
    string result = "";
    stack<char> s;
    for (char c : exp)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            while(s.top() != '(')
            {
                result += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(!s.empty() && checkPre(c) <= checkPre(s.top())) // Lower prec cannot come on top of higher so we pop and add to the result
            {
                result += s.top();
                s.pop();
            }
            s.push(c); // Higher prec can come on top of lower prec
        }

    }

    return result + s.top();
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    string r = conversion(exp);
    cout << r;
    return 0;
}