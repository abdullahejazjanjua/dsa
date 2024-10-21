#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};

class CL
{
    node *head;
    public:
        CL()
        {
            head = NULL;
        }
        void AddHead(int val)
        {
            node *newNode = new node;
            newNode->val = val;
            if (head == NULL)
            {
                newNode->next = newNode;
                head = newNode;
                return;
            }
            newNode->next = head;
            node *cur = endNode();
            cur->next = newNode;
            head = newNode;
        }

        void AddTail(int val)
        {
            node *newNode = new node;
            newNode->val = val;
            newNode->next = head;
            node *cur = endNode();
            cur->next = newNode;
        }
        node *endNode()
        {
            node *cur = head;
            while(cur->next != head)
            {
                cur = cur->next;
            }
            return cur;
        }

        void removeByKey(int key)
        {
            node *cur = head, *prev;
            if (head == NULL)
            {
                cout << "\nThe linked list is empty";
                return;
            }
            if (cur->val == key)
            {
                if (cur->next == head) 
                { 
                    delete head;
                    head = NULL;
                    return;
                }
                node* end = endNode();
                head = head->next;
                end->next = head;
                return;
            }
            do
            {
                prev = cur;
                cur = cur->next;
            }
            while(cur != head && cur->val != key);
            if (cur == head)
            {
                cout << endl << key << " NOT found";
                return;
            }            
            else if(cur->next == head)
            {
                prev->next = head;
            }
            else
            {
                prev->next = cur->next;
            }
            delete cur;
        }

        void print()
        {
            node *cur = head;
            cout << endl;
            do
            {
                cout << cur->val << " ";
                cur = cur->next;
            }
            while(cur != head);
        }
};
int main()
{
    CL cl;
    cl.AddHead(1);
    cl.AddHead(2);
    cl.AddHead(3);
    cl.AddTail(4);
    cl.print();
    cl.removeByKey(1);
    cl.print();
}