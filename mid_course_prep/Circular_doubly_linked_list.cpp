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
            tail = NULL;
        }
        void addHead(int val)
        {
            node *newNode = new node;
            newNode->val = val;
            if (head == NULL)
            {
                newNode->next = newNode;
                newNode->prev = newNode;
                head = tail = newNode;
            }
            else
            {
                newNode->next = head;
                newNode->prev = tail;
                head->prev = newNode;
                tail->next = newNode;
                head = newNode;

            }
        }

        void AddTail(int val)
        {
            node *newNode = new node, *tmp = head;
            newNode->val = val;
            if (head == NULL)
            {
                newNode->next = newNode;
                newNode->prev = newNode;
                head = tail = newNode;
                return;
            }
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            tail = newNode;
        }

        void delete_by_key(int key)
        {
            node *cur = head;
            if (head == NULL)
            {
                cout << "\nThe list is empty\n";
                return;
            }
            if (cur->val == key)
            {
                if (cur->next == head)
                {
                    delete head;
                    head = tail = NULL;
                }
                else
                {
                    head = head->next;
                    head->prev = tail;
                    tail->next = head;
                }
            }
            do 
            {
                cur = cur->next;
            }
            while(cur != head && cur->val != key);
            if (cur == head)
            {
                cout << endl << key << " NOT found\n";
            }
            else
            {
                if (cur == tail)
                {
                    tail = tail->prev;
                    tail->next = head;
                    head->prev = tail;
                }
                else
                {
                    cur->next->prev = cur->prev;
                    cur->prev->next = cur->next;
                }
            }
            delete cur;
        }


        void display()
        {
            node *tmp = head;
            cout << endl;
            do
            {
                cout << tmp->val << " ";
                tmp = tmp->next;
            }
            while(tmp != head);
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

    d.delete_by_key(1); // Deleting node with value 1 (head)
    d.display();

    d.delete_by_key(9);
    return 0;
}