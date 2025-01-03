#include <iostream>
#include <stack>
using namespace std;

int checkpre(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string convert(string s)
{
    string result = "";
    stack<char> op;
    for (char c : s)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <='Z') || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            op.push(c);
        else if (c == ')')
        {
            while(op.top() != '(')
            {
                result += op.top();
                op.pop();
            }
            op.pop();
        }
        else
        {
            while(!op.empty() && checkpre(op.top()) >= checkpre(c))
            {
                result += op.top();
                op.pop();
            }
            op.push(c);
        }

    }
    while (!op.empty())
    {
        result += op.top();
        op.pop();
    }
    return result;
}
int main() 
{
    string exp = "m+(n*p-q)*r/s+t";
    string r = convert(exp);
    cout << r;
    return 0;
}