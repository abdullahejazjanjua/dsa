#include <iostream>
using namespace std;


struct node
{
    int val;
    node *next;
};

class RandomCycle
{
    node *head;
    public:
        RandomCycle()
        {
            head = NULL;
        }
        void add_at_head(int val)
        {
            node *newNode = new node;
            newNode->next = head;
            newNode->val = val;
            head = newNode;
        }
        void display()
        {
            node *cur = head;
            while(cur != NULL)
            {
                cout << cur->val << " ";
                cur = cur->next;
            }
        }
        void addCycle()
        {
            node *cur = head, *cycle;
            int index = 1;
            while(cur != NULL && index <= 3)
            {
                index++;
                cycle = cur;
                cur = cur->next;
            }
            cur = head;
            while(cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = cycle;
        }
        int hasCycle()
        {
            node *slow, *fast, *prev;
            slow = head;
            fast = head->next;
            int index = 1;
            while(fast != NULL && fast->next != NULL && fast != slow)
            {
                index++;
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            cout << "\nIndex of Cycle node: " << index; 
            int val = slow->val;
            node *cur = slow;
            do
            {
                cur = cur->next;
            }
            while(cur->next != slow);
            prev->next = slow->next;
            cur->next = NULL;
            delete slow;
            return val;
        }
};

int main()
{
    RandomCycle rc;
    rc.add_at_head(1);
    rc.add_at_head(2);
    rc.add_at_head(8);
    rc.add_at_head(3);
    rc.add_at_head(11);
    cout << "\nThe original list: ";
    rc.display();
    rc.addCycle();
    cout << "\nThe value in looped node is: " << rc.hasCycle();
    cout << "\nThe list with cycle node removed: ";
    rc.display();

}