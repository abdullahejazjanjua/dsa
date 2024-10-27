#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
    node *prev;
};

class Doubly_linked_list
{
    node *head;
    node *tail;
    public:
        Doubly_linked_list()
        {
            head = NULL;
        }
        void addHead(int val)
        {
            node *newNode = new node;
            newNode->val = val;
            newNode->next = head;
            newNode->prev = NULL;
            if (head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                head->prev = newNode;
                head = newNode;
            }
        }

        void AddTail(int val)
        {
            node *newNode = new node, *tmp = head;
            newNode->val = val;
            newNode->next = NULL;
            if (head == NULL)
            {
                newNode->prev = NULL;
                head = newNode;
                return;
            }
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        void display()
        {
            node *tmp = head;
            cout << endl;
            while(tmp != NULL)
            {
                cout << tmp->val << " ";
                tmp = tmp->next;
            }
        }

        void delete_by_key(int val)
        {
            node *cur = head;
            if (cur == NULL)
            {
                cout << "\nThe list is empty\n";
                return;
            }
            while(cur != NULL && cur->val != val)
            {
                cur = cur->next;
            }
            if (cur == NULL)
            {
                cout << endl << val << " NOT found";
                return;
            }
            if (cur == head)
            {
                head = head->next;
                if (head != NULL)
                {
                    head->prev = NULL;
                }
                else
                {
                    tail = NULL;
                }
            }
            else if (cur->next == NULL)
            {
                tail = tail->prev;
                tail->next = NULL; 
            }
            else
            {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            delete cur;
        }
};

int main()
{
    Doubly_linked_list d;
    d.addHead(1);
    d.addHead(2);
    d.addHead(3);
    d.AddTail(4);
    d.display();
    d.delete_by_key(2); // Deleting node with value 2
    d.display();

    d.delete_by_key(4); // Deleting node with value 4 (tail)
    d.display();

    d.delete_by_key(3); // Deleting node with value 1 (head)
    d.display();

    d.delete_by_key(5);
    return 0;
}