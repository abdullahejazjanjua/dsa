#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

class QueueLinkedList
{
    Node *front;
    Node *rear;
    public:
        QueueLinkedList()
        {
            front = rear = NULL;
        }
        void enqueue(int val)
        {
            Node *newNode = new Node;
            newNode->val = val;
            newNode->next = NULL;
            if (front == NULL)
            {
                front = rear = newNode;
            }
            rear->next = newNode;
            rear = newNode;
        }

        void dequeue()
        {
            Node *tmp = front;
            front = front->next;
            delete tmp;
        }

        void display()
        {
            Node *cur = front;
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
    QueueLinkedList ql;
    ql.enqueue(1);
    ql.enqueue(2);
    ql.enqueue(3);
    ql.display();
    ql.dequeue();
    ql.display();

    return 0;
}