#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

class Stack
{
    Node *head;
    public:
        Stack()
        {
            head = NULL;
        }
        void push(int val)
        {
            Node *newNode = new Node;
            newNode->val = val;
            newNode->next = head;
            head = newNode;
        }
        void pop()
        {
            Node *cur = head;
            head = head->next;
            delete cur;
        }

        void display()
        {
            Node *cur = head;
            cout << endl;
            while(cur != NULL)
            {
                cout << cur->val << " ";
                cur = cur->next;
            }
        }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    s.display();
}