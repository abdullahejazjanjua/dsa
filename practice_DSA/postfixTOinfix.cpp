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
void postfixTOinfix(string expression);


int main()
{
    string expression = "ab+ef/*";
    postfixTOinfix(expression);
    
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

void postfixTOinfix(string expression)
{
    stack s;
    const char *ptr = expression.c_str();
    int i = 0;
    while (ptr[i] != '\0')
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
            string op(1, ptr[i]);
            string C = B + op + A;
            s.push(C);
            cout << "\nPushed: combined expression: " << C << endl;
        }
        i++;
    }
    cout << "\nThe infix is: " << s.pop();

}