#include <iostream>
using namespace std;

class stack
{
    public:
        struct node
        {
            int data;
            node *next;
        };
        node *headptr;
        node *tailptr;
        stack()
        {
            headptr = tailptr = NULL;
        }
        void push(int data);
        void pop();
        void display();
};

int main()
{

    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();

}

void stack :: push(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    if (headptr == NULL)
        headptr = tailptr = newNode;
    tailptr->next = newNode;
    tailptr = newNode;
}

void stack :: pop()
{
    node *current = headptr;
    if (current == tailptr)
    {   
        delete current;
        headptr = tailptr = NULL;
    }
    else
    {
        while(current->next != tailptr) 
        {
            current = current->next;
        }
        delete tailptr;
        current->next = NULL;
        tailptr = current;
    }

}

void stack :: display()
{
    node *runner = headptr;
    cout << endl;
    while(runner != NULL)
    {
        cout << runner->data << "----->";
        runner = runner->next;
    }
    cout << "NULL";

}