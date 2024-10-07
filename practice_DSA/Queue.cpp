#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

class Queue
{
    private:
        Node* head;
    public:
        Queue()
        {
            head = 0;
        }
        ~Queue()
        {
            Node* cur = head;
            while (cur != nullptr)
            {
                Node* temp = cur;
                cur = cur->next;
                delete temp;
            }
        }

        void push(int data)
        {
            Node *newNode = new Node;
            newNode->val = data;
            newNode->next = head;
            head = newNode;
        }
        void pop()
        {
            if (head == NULL)
            {
                cout << "\nThe Queue is empty\n";
                return;
            }
            else if (head->next == NULL)
            {
                delete head;
                head = NULL;
                return;
            }
            Node* cur = head, *prev;
            while (cur->next != NULL)
            {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            delete cur;
        }

        void print()
        {
            Node* cur = head;
            while (cur != NULL)
            {
                cout << cur->val << " ----> ";
                cur = cur->next;
            }
            cout << "NULL" << endl;
        }
};

int main()
{
    Queue Q;
    Q.pop();
    Q.push(1);
    Q.print();
    Q.pop();
    Q.print();
    Q.push(2);
    Q.push(3);
    Q.print();
    Q.pop();
    Q.print();
}