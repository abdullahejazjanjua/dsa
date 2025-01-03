#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

class SingularList
{
    Node *head;
    public:
        SingularList()
        {
            head = NULL;
        }
        ~SingularList()
        {
            Node *tmp = head;
            while(head != NULL)
            {
                tmp = head;
                head = head->next;
                delete tmp;
            }
        }

        void AddAtHead(int val)
        {
            Node *newNode = new Node;
            newNode->next = head;
            newNode->val = val;
            head = newNode;
        }

        void AddAtTail(int val)
        {
            Node *newNode = new Node;
            newNode->next = NULL;
            newNode->val = val;
            Node *cur = head;
            if (cur == nullptr)
            {
                head = newNode;
            }
            while(cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = newNode;
        }

        void DeleteNode(int key)
        {
            Node *cur = head, *prev;

            if (head == NULL)
            {
                cout << "\nThe Linked List is empty\n";
                return;
            }
            while(cur != NULL && cur->val != key)
            {
                prev = cur;
                cur = cur->next;
            }
            if(cur == head)
            {
                head = head->next;
            }
            else
            {
                prev->next = cur->next;
            }

            delete cur;
        }

        void addATPos(int val, int pos)
        {
            Node *cur = head, *prev = nullptr;
            int i = 0;
            if (pos == 0)
            {
                AddAtHead(val);
            }
            while(cur != nullptr && i < pos)
            {
                prev = cur;
                cur = cur->next;
                i++;
            }
            if (cur == nullptr && i != pos)
            {
                cout << "\nThe position " << pos << " is out of bounds\n";
            }
            else
            {
                Node *newNode = new Node;
                newNode->val = val;
                if(cur == nullptr)
                {
                    prev->next = newNode;
                    newNode->next = nullptr;
                }
                else
                {
                    prev->next = newNode;
                    newNode->next = cur;
                }

            }
        }

        void deleteATPos(int pos)
        {
            Node *cur = head, *prev = nullptr;
            int i = 0;
            while(cur != nullptr && i < pos)
            {
                prev = cur;
                cur = cur->next;
                i++;
            }
            if (cur == nullptr)
            {
                cout << "\nThere is no " << pos << " in the list";
                return;
            }
            else
            {
                if(prev == nullptr)
                {
                    head = head->next;
                }
                else
                {
                    prev->next = cur->next;
                }
                delete cur;
            }
        }



        void display()
        {
            Node *cur = head;
            cout << endl;
            while(cur != NULL)
            {
                cout << cur->val << " ";
                cur = cur->next;
            }
            cout << endl;
        }
        
};

int main() {
    SingularList list;

    // Test Case 1: Deleting at the head
    list.AddAtHead(40);
    list.AddAtHead(30);
    list.AddAtHead(20);
    list.AddAtHead(10);
    cout << "Initial List: ";
    list.display();
    list.deleteATPos(0);  // Delete head
    cout << "After Deleting head: ";
    list.display();

    // Test Case 2: Deleting at a valid position (middle node)
    list.AddAtHead(40);
    list.AddAtHead(30);
    list.AddAtHead(20);
    list.AddAtHead(10);
    cout << "Initial List: ";
    list.display();
    list.deleteATPos(2);  // Delete middle node (30)
    cout << "After Deleting at position 2: ";
    list.display();

    // Test Case 3: Deleting at the tail
    list.AddAtHead(40);
    list.AddAtHead(30);
    list.AddAtHead(20);
    list.AddAtHead(10);
    cout << "Initial List: ";
    list.display();
    list.deleteATPos(3);  // Delete tail node (40)
    cout << "After Deleting at position 3: ";
    list.display();

    // Test Case 4: Deleting from an empty list
    SingularList emptyList;
    cout << "\nEmpty List: ";
    emptyList.display();
    emptyList.deleteATPos(0);  // Try deleting from an empty list

    // Test Case 5: Deleting at an out-of-bounds position
    SingularList list2;
    list2.AddAtHead(40);
    list2.AddAtHead(30);
    list2.AddAtHead(20);
    list2.AddAtHead(10);
    cout << "\nInitial List: ";
    list2.display();
    list2.deleteATPos(5);  // Position out of bounds
    

    // Test Case 6: Deleting when there is only one node
    SingularList singleNodeList;
    singleNodeList.AddAtHead(10);
    cout << "\nSingle Node List: ";
    singleNodeList.display();
    singleNodeList.deleteATPos(0);  // Delete the only node
    cout << "\nAfter Deleting the only node: ";
    singleNodeList.display();

    return 0;
}