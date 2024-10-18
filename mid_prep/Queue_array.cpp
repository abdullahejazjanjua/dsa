#include <iostream>
using namespace std;
#define MAX_SIZE 6
class Queue
{
    int *a;
    int top, rear;
    public:
        Queue()
        {
            a = new int[MAX_SIZE];
            top = 0;
            rear = 0;
        }

        void enqueue(int val)
        {
            a[rear++] = val;
        }
        void dequeue()
        {
            top++;
        }
        void display()
        {
            cout << endl;
            for(int i = top; i < rear; i++)
            {
                cout << a[i] << " ";
            }
        }
};


int main()
{
    Queue Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.display();
    Q.dequeue();
    Q.display();
}