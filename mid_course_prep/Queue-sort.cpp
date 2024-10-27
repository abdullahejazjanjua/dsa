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
        int dequeue()
        {
            node *tmp = front;
            front = front->next;
            int val = tmp->val;
            delete tmp;
            return val;
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
        void insert_sorted(int val)
        {
            if (front == NULL || val > front->val)
            {
                enqueue(val);
            }
            else
            {
                int tmp = dequeue();
                insert_sorted(val);
                enqueue(tmp);
            }
        }
        void sort_queue()
        {
            if (front != NULL)
            {
                int tmp = dequeue();
                sort_queue();
                insert_sorted(tmp);
            }
        }
};
int main()
{
    Queue q;
    q.enqueue(4);
    q.enqueue(2);
    q.enqueue(1);
    q.enqueue(3);
    //q.sort_queue();
    q.display();
    return 0;
}