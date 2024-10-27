#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

class Stack
{
    node *top;
    public:
        Stack()
        {
            top = NULL;
        }
        void push(int val)
        {
            node *newNode = new node;
            newNode->val = val;
            newNode->next = top;
            top = newNode;
        }
        void pop()
        {
            node *tmp = top;
            top = top->next;
            delete tmp;
        }
        int peek()
        {
            return top->val;
        }
        void insert_sorted(int val)
        {
            if (top == NULL || val > top->val)
            {
                push(val);
            }
            else
            {
                int tmp = peek();
                pop();
                insert_sorted(val);
                push(tmp);
            }
        }
        void sort_stack()
        {
            if (top != NULL)
            {
                int tmp = peek();
                pop();
                sort_stack();
                insert_sorted(tmp);
            }
        }
        void display()
        {
            node *ptr = top;
            cout << "\nStack elements are: ";
            while (ptr != NULL) 
            {
                cout << ptr->val << " ";
                ptr = ptr->next;
            }
        }
};
int main()
{
    Stack s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);
    s.display();
    s.sort_stack();
    s.display();
    return 0;
}