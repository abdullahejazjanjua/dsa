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
        void swap(int a, int b)
        {
            node *cur = head, *node_a = NULL, *node_b = NULL;
            if (head == nullptr) 
            {
                cout << "The list is empty." << endl;
                return;
            }

            while(cur != NULL)
            {
                if (cur->val == a)
                {
                    node_a = cur;
                }
                else if (cur->val == b)
                {
                    node_b = cur;
                }
                cur = cur->next;
            }
            if (node_a == nullptr || node_b == nullptr) 
            {
                cout << "One or both nodes not found." << endl;
                return;
            }
            if (node_a == node_b) 
            {
                cout << "\nNode a and Node b are same\n";
                return; 
            }
            // Case 01: Node a and Node b are adjacent
            if (node_a->next == node_b)
            {
                node_b->next->prev = node_a;
                if (node_a->prev)
                {
                    node_a->prev->next = node_b;
                }
                else
                {
                    head = node_b;
                }
                node_a->next = node_b->next;
                if (node_b->prev)
                {
                    node_b->prev = node_a->prev;
                    node_a->prev = node_b;
                }
                node_b->next = node_a;
            }
            else if (node_b->next == node_a)
            {
                swap(b,a);
            }
            
            // Case 02: Node A and Node B are NOT adjacent
            else
            {
                // Re-linking node_a
                if (node_a->prev)
                    node_a->prev->next = node_b;
                else
                    head = node_b; // node_a was head

                if (node_a->next)
                    node_a->next->prev = node_b;

                // Re-linking node_b
                if (node_b->prev)
                    node_b->prev->next = node_a;
                else
                    head = node_a; // node_b was head

                if (node_b->next)
                    node_b->next->prev = node_a;

                std::swap(node_a->next, node_b->next);
                std::swap(node_a->prev, node_b->prev);
            }
            
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
    dll.add(5);
    dll.add(4);
    dll.add(3);
    dll.add(2);
    dll.add(1);
    dll.display();
    dll.swap(1,4);
    dll.display();
    return 0;
}