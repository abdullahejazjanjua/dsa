#include <iostream>
using namespace std;

#define MAX_SIZE 6

class queue
{
    public:
    int *q;
    int rear;
    int front;
    queue()
    {
        q = new int[MAX_SIZE];
        rear = front = 0;
    }

    bool isFull()
    {
        return ((rear + 1) % MAX_SIZE) == front;
    }

    bool isEmpty()
    {
        return rear == front;
    }

    void push(int val)
    {
        if(isFull())
        {
            cout << "\nThe queue is Full\n";
            return;
        }
        q[rear] = val;
        rear = (rear + 1) % MAX_SIZE;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout << "\nThe queue is empty\n";
            return;
        }
        front = (front + 1 ) % MAX_SIZE;
    }

    void display()
        {
            if(isEmpty())
            {
                cout << "The queue is empty\n";
            }
            int i = front;
            while(i != rear)
            {
                cout << q[i] << " ";
                i = (i + 1) % MAX_SIZE;
            }
            cout << endl;
        }
};

int main()
{
    queue cq;
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);
    cq.display();
    cq.pop();
    cq.display();
    cq.push(7);
    cq.display();
    return 0;
}