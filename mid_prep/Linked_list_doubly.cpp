#include <iostream> 
using namespace std;


struct node
{
    int val;
    node *next;
    node *prev;
};

class DL
{
    node *head;
    public:
        DL()
        {
            head = NULL;
        }    
        void AddHead(int val)
        {
            node *newNode = new node;
            newNode->val = val;
            newNode->next = head;
            if (head == NULL)
            {
                newNode->prev = NULL;
                head = newNode;
                return;
            }
            newNode->prev = NULL;
            head->prev = newNode;
            head = newNode;
        }    
        void AddTail(int val)
        {
            node *newNode = new node;
            newNode->val = val;
            newNode->next = NULL;
            if (head == NULL)
            {
                newNode->prev = NULL;
                head = newNode;
                return;
            }
            node *cur = head;
            while(cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = newNode;
            newNode->prev = cur;
        }

        void removeByKey(int key)
        {
            node *cur = head;
            if(head == NULL)
            {
                cout << "The list is empty\n";
                return;
            }
            
            while(cur != NULL && cur->val != key)
            {
                cur = cur->next;
            }
            if (cur == NULL)
            {
                cout << endl << key << " NOT found\n";
                return;
            }
            if(cur == head)
            {
                head = head->next;
                if (head != NULL)
                    head->prev = NULL;
            }
            else if (cur->next == NULL)
            {
                cur->prev->next = cur->next;
            }
            else
            {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }

            delete cur;
        }
        void print()
        {
            node *cur = head;
            cout << endl;
            while(cur != NULL)
            {
                cout << cur->val << " ";
                cur = cur->next;
            }

        }       
};
int main()
{
    DL dl;
    dl.AddHead(1);
    dl.removeByKey(1);
    dl.print();
    dl.AddHead(2);
    dl.AddHead(3);
    dl.AddTail(4);
    dl.print();
    dl.removeByKey(9);
    dl.print();
}