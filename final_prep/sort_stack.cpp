#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

class stack
{
    node *top;
    public:
        stack()
        {
            top = nullptr;
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
            if(top == nullptr)
            {
                cout << "\nThe stack is empty\n";
                return;
            }
            node *tmp = top;
            top = top->next;
            delete tmp;
        }

        int front()
        {
            if(top == nullptr)
            {
                return -1;
            }
            return top->val;
        }


        void insert_sorted(int val)
        {
            if(top == nullptr || val > front())
            {
                push(val);
            }
            else
            {
                int tmp = front();
                pop();
                insert_sorted(val);
                push(tmp);
            }
        }
        void sort_stack()
        {
            if(top == nullptr)
                return;

            int tmp = front();
            pop();
            sort_stack();
            insert_sorted(tmp);
        }

        void display()
        {
            node *cur = top;
            while(cur != nullptr)
            {
                cout << cur->val << " ";
                cur = cur->next;
            }

        }
};

int main() 
{
    stack s;
    s.push(3);
    s.push(1);
    s.push(4);
    s.push(2);

    cout << "Original Stack: ";
    s.display();

    s.sort_stack();

    cout << "\nSorted Stack: ";
    s.display();

    return 0;
}
