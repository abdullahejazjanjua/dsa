#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

class Queue
{
    node *front, *rear;
    public:
        Queue()
        {
            front = rear = NULL;
        }
        void enqueue(int val)
        {
            node *newNode = new node;
            newNode->val = val;
            newNode->next = NULL;
            if (front == NULL)
            {
                front = rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
        }
        void dequeue()
        {
            node *tmp = front;
            front = front->next;
            delete tmp;
        }
        void display()
        {
            node *tmp = front;
            cout << endl;
            while(tmp != NULL)
            {
                cout << tmp->val << " ";
                tmp = tmp->next;
            }
        }
};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}