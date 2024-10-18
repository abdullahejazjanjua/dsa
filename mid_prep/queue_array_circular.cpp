#include <iostream>
using namespace std;

#define MAX_SIZE 6

class CircularQueue
{
    int *a;
    int front, rear;
    public:
        CircularQueue()
        {
            a = new int[MAX_SIZE];
            front = rear = 0;
        }
        bool isFull()
        {
            return ((rear + 1) % MAX_SIZE == front);
        }
        bool isEmpty()
        {
            return front == rear;
        }
        void enqueue(int val)
        {
            if(isFull())
            {
                cout << "\nThe queue is Full\n";
            }
            else
            {
                a[rear] = val;
                rear = (rear + 1) % MAX_SIZE;
            }
        }

        void dequeue()
        {
            if(isEmpty())
            {
                cout << "The Queue is Empty\n";
            }
            else
            {
                front = (front + 1) % MAX_SIZE;
            }
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
                cout << a[i] << " ";
                i = (i + 1) % MAX_SIZE;
            }
            cout << endl;
        }
};

int main()
{
    CircularQueue cq;
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.display();
    cq.dequeue();
    cq.display();
    cq.enqueue(7);
    cq.display();
    return 0;
}