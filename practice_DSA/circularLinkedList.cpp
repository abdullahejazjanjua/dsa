#include <iostream>
using namespace std;

class circularList
{
    public:
        struct node
        {
            int data;
            node *next;
        };
        node *headptr, *tailptr;
        
        circularList()
        {
            headptr = tailptr = NULL;
        }

        void addAthead(int data);
        void addAtTail(int data);
        void display();
        void RemoveByKey(int data);
    
};

int main()
{
    circularList cl;
    cl.addAthead(1);
    cl.addAthead(2);
    cl.addAtTail(3);
    cl.display();
    cl.RemoveByKey(3);
    cl.display();
}

void circularList :: addAthead(int data)
{
    node *newNode = new node;
    newNode->data = data;
    if (headptr == NULL)
    {
        newNode->next = newNode;
        headptr = tailptr = newNode;
    }
    else
    {
        newNode->next = headptr;
        headptr = newNode;
        tailptr->next = headptr;
    }
}

void circularList :: addAtTail(int data)
{
    node *newNode = new node;
    newNode->data = data;
    if (headptr == NULL)
    {
        newNode->next = newNode;
        headptr = tailptr = newNode;
    }
    else
    {
        tailptr->next = newNode;
        newNode->next = headptr;
        tailptr = newNode;
    }
}

void circularList :: display()
{
    node *traversor = headptr;
    cout << "\n";
    do
    {
        cout << traversor->data << "----->";
        traversor = traversor->next; 
    }
    while (traversor != headptr);
    cout << "NULL";
}

void circularList :: RemoveByKey(int data)
{
    node *current = headptr, *prev;

    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\n" << data << " NOT found\n";
    }
    else if (current == headptr)
    {
        headptr = headptr->next;
        tailptr->next = headptr;
    }
    else
    {
        prev->next = current->next;
    }

    delete current;
}

