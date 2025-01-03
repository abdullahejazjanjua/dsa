#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

class queue
{
    node *front;
    node *rear;
    public:
        queue()
        {
            front = rear = nullptr;
        }
        void push(int val)
        {
            node *newNode = new node;
            newNode->val = val;
            newNode->next = nullptr;
            if (rear == nullptr)
            {
                rear = front = newNode;
            }
            rear->next = newNode;
            rear = newNode;
        }

        void pop()
        {
            if(front == nullptr)
            {
                cout << "\nThe queue is empty\n";
                return;
            }
            node *cur = front;
            front = front->next;
            delete cur;

        }
        void display()
        {
            node *cur = front;
            while(cur != NULL)
            {
                cout << cur->val << " ";
                cur = cur->next;
            }
            cout << endl;
        }
};

int main()
{
    queue ql;
    ql.push(1);
    ql.push(2);
    ql.push(3);
    ql.display();
    ql.pop();
    ql.display();

    return 0;
}