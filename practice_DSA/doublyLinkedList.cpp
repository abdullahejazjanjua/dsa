#include <iostream>
using namespace std;

class doublylist
{
    public:
        struct node
        {
            int data;
            node *next;
            node *prev;
        };
        node *headptr;
        doublylist()
        {
            headptr = NULL;
        }
        void addAthead(int data);
        void addAtTail(int data);
        void display();
        void RemoveByKey(int data);

};

int main()
{
    doublylist dl;
    dl.addAthead(1);
    dl.addAthead(2);
    dl.addAtTail(3);
    dl.display();
    dl.RemoveByKey(3);
    dl.display();
    
}

void doublylist :: addAthead(int data)
{
    node *newNode = new node;
    newNode->data = data;
    if (headptr != NULL)
        headptr->prev = newNode;
    newNode->next = headptr;
    newNode->prev = NULL;
    headptr = newNode;
    cout << "\nAdded " << data << " at head\n";
}

void doublylist :: addAtTail(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    node *current = headptr;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    
}

void doublylist :: display()
{
    node *traversor = headptr;
    cout << "\n";
    while (traversor != NULL)
    {
        cout << traversor->data << "----->";
        traversor = traversor->next; 
    }
    cout << "NULL";

}

void doublylist :: RemoveByKey(int data)
{
    node* current = headptr;
    while (current != NULL && current->data != data)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\nThe list's empty\n";
    }
    else if (current == headptr)
    {
        headptr = headptr->next;
        if (headptr != NULL)
            headptr->prev = NULL;
    }
    else if (current->next == NULL)
    {
        current->prev->next = NULL;

    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    delete current;
}