#include <iostream>
using namespace std;

struct Node 
{
    int val;
    Node *next;
};

class CircularList
{
    Node *head;
    public:
        CircularList()
        {
            head = NULL;
        }
        ~CircularList()
        {
            if (head == NULL)
                return;

            Node *cur = head;
            Node *nextNode;
            do
            {
                nextNode = cur->next;
                delete cur;
                cur = nextNode;
            } 
            while (cur != head);
        }

        void AddAthead(int val)
        {
            Node *newNode = new Node;
            newNode->val = val;
            if (head == NULL)
            {
                newNode->next = newNode;
                head = newNode;
                return;
            }
            Node *cur = head;
            while(cur->next != head)
            {
                cur = cur->next;
            }
            newNode->next = head;
            cur->next = newNode;
            head = newNode;
        }

        void AddAtTail(int val)
        {
            Node *newNode = new Node, *cur = head;
            newNode->val = val;
            if (head == NULL)
            {
                newNode->next = newNode;
                head = newNode;
                return;
            }
            newNode->next = head;
            while(cur->next != head)
            {
                cur = cur->next;
            }
            cur->next = newNode;
            
        }

        void DeleteKey(int key)
        {
            Node *cur = head, *prev;
            if (head == NULL)
            {
                cout << "\nThe list is empty\n";
                return;
            }
            if(cur->val == key)
            {
                if(cur->next == head)
                {
                    delete head;
                    head = NULL;
                    return;
                }
                Node *run = head;
                while(run->next != head)
                {
                    run = run->next;
                }
                head = head->next;
                run->next = head;
                delete cur;
                return;

            }
            do
            {
                prev = cur;
                cur = cur->next;
            }
            while(cur != head && cur->val != key);
            if (cur->val == key)
            {
                prev->next = cur->next;
                delete cur;

            }
            else
            {
                cout << key << " NOT found\n";
            }
        }

        void display()
        {
            Node *cur = head;
            cout << endl;
            do
            {
                cout << cur->val << " ";
                cur = cur->next;
            } 
            while (cur != head);
            
        }
};

int main()
{
    CircularList cl;
    cl.AddAthead(1);
    cl.AddAthead(2);
    cl.AddAtTail(3);
    cl.display();
    cl.DeleteKey(1);
    cl.display();
}