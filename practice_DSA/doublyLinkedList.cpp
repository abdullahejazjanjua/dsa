#include <iostream>
using namespace std;

class doublylist
{
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

}

void doublylist :: addAthead(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = headptr;
    newNode->prev = NULL;
}

void doublylist :: addAtTail(int data)
{
    node *newNode = new node;
    
}