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
    public:
        Doubly_linked_list()
        {
            head = NULL;
        }
        void add(int val)
        {
            node *newNode = new node;
            newNode->val = val;
            newNode->next = head;
            newNode->prev = NULL;
            if(head != NULL)
            {
                head->prev = newNode;
            }
            head = newNode;
        }
        void display()
        {
            node *cur = head;
            cout << endl;
            while(cur != NULL)
            {
                cout << cur->val << " ";
                cur = cur->next;
            }
        }
        void positionHead(int index)
        {
            node *cur = head;
            int count = 0;
            if (head == NULL)
            {
                cout << "\nThe list is empty\n";
                return;
            }
            while(cur != NULL && count < index)
            {
                count++;
                cur = cur->next;
            }
            if (cur == NULL)
            {
                cout << index << " is out of bounds\n";
                return;
            }
            node *tmp = head;
            // Link tmp
            cur->prev->next = NULL;
            cur->prev = NULL;
            head = cur;
            node *run = head;
            while(run->next != NULL)
            {
                run = run->next;
            } 
            run->next = tmp;
            tmp->prev = run;

        }

        node *endNode()
        {
            node *cur = head;
            while(cur->next != NULL)
            {
                cur = cur->next;
            }
            return cur;
        }
};
int main()
{
    Doubly_linked_list dll;
    dll.add(1);
    dll.add(2);
    dll.add(8);
    dll.add(3);
    dll.add(11);
    dll.display();
    dll.positionHead(2);
    dll.display();
    return 0;
}