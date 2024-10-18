#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

class SingularList
{
    Node *head;
    public:
        SingularList()
        {
            head = NULL;
        }
        ~SingularList()
        {
            Node *tmp = head;
            while(head != NULL)
            {
                tmp = head;
                head = head->next;
                delete tmp;
            }
        }

        void AddAtHead(int val)
        {
            Node *newNode = new Node;
            newNode->next = head;
            newNode->val = val;
            head = newNode;
        }

        void AddAtTail(int val)
        {
            Node *newNode = new Node;
            newNode->next = NULL;
            newNode->val = val;
            Node *cur = head;
            while(cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = newNode;
        }

        void DeleteNode(int key)
        {
            Node *cur = head, *prev;

            if (head == NULL)
            {
                cout << "\nThe Linked List is empty\n";
                return;
            }
            while(cur != NULL && cur->val != key)
            {
                prev = cur;
                cur = cur->next;
            }
            if(cur == head)
            {
                head = head->next;
            }
            else
            {
                prev->next = cur->next;
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
    SingularList l;
    l.DeleteNode(0);
    l.AddAtHead(1);
    l.AddAtHead(2);
    l.AddAtTail(3);
    l.display();
    l.DeleteNode(3);
    l.display();
}