#include <iostream>
using namespace std;

#define MAX_SIZE 4
class Q
{
    int front, rear;
    int *q;
    public:
        Q()
        {
            front = rear = 0;
            q = new int[MAX_SIZE];
        }
        bool isFull()
        {
            return ((rear + 1) % MAX_SIZE == front);
        }
        bool isEmpty()
        {
            return (front == rear);
        }
        void enqueue(int val)
        {
            if (isFull())
            {
                cout << "\nThe queue is FULL";
            }
            else
            {
                q[rear] = val;
                rear = (rear + 1) % MAX_SIZE;
            }
        }
        void dequeue()
        {
            if (isEmpty())
            {
                cout << "\nThe queue is Empty\n";
            }
            else
            {
                front = (front + 1) % MAX_SIZE;
            }
        }

        void print()
        {
            int i = front;
            cout << endl;
            while(i != rear)
            {
                cout <<  q[i] << " ";
                i = (i + 1) % MAX_SIZE;
            }
        }
};

int main()
{
    Q q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(4);
    q.print();

}