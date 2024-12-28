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


string infixTOpostfix(string exp)
{
    stack<char> s;
    string result = "";
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
            s.pop(); // Remove ( also
        }
        else
        {
            while(!s.empty() && checkPre(c) <= checkPre(s.top()))
            {
                result += s.top();
                s.pop(); // Remove lower prec op
            }
            s.push(c); // Push higher op onto the stack
        }
    
    }

    return result;
}

int main() 
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    string  r = infixTOpostfix(exp);
    cout << r;
    return 0;
}