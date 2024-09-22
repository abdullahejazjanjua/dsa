// Scan from right to left
#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;

class stack
{
    public:
        struct node
        {
            string data;
            node *next;
        };
        node *headptr;
        node *tailptr;
        stack()
        {
            headptr = tailptr = NULL;
        }
        void push(string data);
        string pop();
        void display();
};
void prefixTOinfix(string expression);


int main()
{
    string expression = "*+ab/ef";
    prefixTOinfix(expression);
    
}

void stack :: push(string data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    if (headptr == NULL)
        headptr = tailptr = newNode;
    tailptr->next = newNode;
    tailptr = newNode;
}

string stack :: pop()
{
    node *current = headptr;
    string val;
    if (current == tailptr)
    {   
        val = current->data;
        delete current;
        headptr = tailptr = NULL;
    }
    else
    {
        while(current->next != tailptr) 
        {
            current = current->next;
        }
        val = tailptr->data;
        delete tailptr;
        current->next = NULL;
        tailptr = current;
    }
    
    return val;
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

void prefixTOinfix(string expression)
{
    stack s;
    const char *ptr = expression.c_str();
    int length = expression.size();
    
    for (int i = length - 1; i >= 0; i--)
    {
        cout << "\nAt: " << ptr[i];
        if (isalnum(ptr[i]))
        {
            string tmp(1, ptr[i]);
            s.push(tmp);
            cout << "\nPUSHED char: " << tmp << endl;
        }
        else
        {
            string A = s.pop();
            string B = s.pop();
            cout << "\nPOPPED: " << A << "," << B << endl;
            string op(1, ptr[i]);
            string C = "(" + A + op + B + ")";
            s.push(C);
            cout << "\nPushed: combined expression: " << C << endl;
        }
        cout << ptr[i] << " == " << ptr[0];
    }
    cout << "\nThe infix is: " << s.pop();

}