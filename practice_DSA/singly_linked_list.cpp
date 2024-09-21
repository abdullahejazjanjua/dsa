#include <iostream>
using namespace std;

class LinkedList
{
    public:
        struct node
        {
            int data;
            node *next;
        };
        node *headptr;
        LinkedList()
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
    LinkedList L;
    L.addAthead(1);
    L.addAtTail(2);
    L.addAthead(3);
    L.display();
    L.RemoveByKey(1);
    L.display();
}

void LinkedList :: addAthead(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = headptr;
    headptr = newNode;
    cout << "\nAdded " << data << " at the head\n";

}

void LinkedList :: addAtTail(int data)
{
    node* newNode = new node;
    node* traversor = headptr;
    newNode->data = data;
    newNode->next = NULL;
    while(traversor->next != NULL)
    {
        traversor = traversor->next;
    }
    traversor->next = newNode;
    cout << "\nAdded " << data << " at the end\n";
}

void LinkedList :: display()
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

void LinkedList :: RemoveByKey(int data)
{
    node *current = headptr;
    node *prev;

    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        cout << "\nThe list is empty";
    }
    else if (current == headptr)
    {
        headptr = headptr->next;
    }
    else
    {
        prev->next = current->next;
    } 

    delete current;
}