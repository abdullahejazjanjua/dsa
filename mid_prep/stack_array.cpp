#include <iostream>
using namespace std;
#define MAX_SIZE 6
class stack
{
    int *a;
    int top;
    public:
        stack()
        {
            a = new int[MAX_SIZE];
            top = -1;
        }
        void push(int val)
        {
            if(isFull())
            {
                cout << "The stack is FULL\n";
            }
            a[++top] = val;
        }
        void pop()
        {
            top--;
        }
        void display()
        {
            cout << endl;
            for (int i = 0; i <= top; i++)
            {
                cout << a[i] << " ";
            }
        }
        bool isFull()
        {
            if(top != MAX_SIZE)
            {
                return false;
            }
            return true;
        }

};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.display();
    s.pop();
    s.display();
}