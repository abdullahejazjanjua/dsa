#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
    Node *head;
    public:
        DoublyLinkedList()
        {
            head = NULL;
        }
        void AddAthead(int val)
        {
            Node* newNode = new Node;
            newNode->val = val;
            newNode->prev = NULL;
            if (head == NULL)
            {
                newNode->next = head;
                head = newNode;
                return;
            }
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }

        void AddAtTail(int val)
        {
            Node *newNode = new Node, *cur = head;
            newNode->val = val;
            newNode->next = NULL;
            if(head == NULL)
            {
                newNode->prev = head;
                head = newNode;
                return;
            }
            while(cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = newNode;
            newNode->prev = cur;
        }
        void Deletekey(int key)
        {
            Node *cur = head;
            if (head == NULL)
            {
                cout << "\nThis list is empty";
                return;
            }
            while(cur != NULL && cur->val != key)
            {
                cur = cur->next;
            }
            if (cur == NULL)
            {
                cout << endl << key << " NOT found\n";
                return;
            }
            if (cur == head)
            {
                head = head->next;
                if (head != NULL)
                {
                    head->prev = NULL;
                }
                
            }
            else if(cur->next == NULL)
            {
                cur->prev->next = NULL;
            }
            else
            {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            delete cur;

        }
        void display()
        {
            Node *cur = head;
            cout << endl;
            while(cur != NULL)
            {
                cout << cur->val << " ";
                cur = cur->next;
            }
        }
};

int main()
{
    DoublyLinkedList dl;
    dl.AddAthead(1);
    dl.AddAthead(2);
    dl.AddAtTail(3);
    dl.display();
    dl.Deletekey(4);
    dl.display();
}