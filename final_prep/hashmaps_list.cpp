#include <iostream>
using namespace std;

struct node
{
    int val;;
    node *next = nullptr;
};

class hashmap
{
    node **map;
    int N;
    public:
        hashmap(int N)
        {
            this->N = N;
            map = new node*[N];
            for (int i = 0; i < this->N; i++)
            {
                map[i] = nullptr;
            }
        }

        int hash(int key)
        {
            return key % this->N;
        }

        void insert(int key)
        {  
            int idx = hash(key);
            node *newNode = new node;
            newNode->val = key;
            newNode->next = map[idx];
            map[idx] = newNode;
        }

        void deleteKey(int key)
        {  
            int idx = hash(key);
            node *cur = map[idx], *prev = nullptr;
            while(cur != nullptr && cur->val != key)
            {
                prev = cur;
                cur = cur->next;
            }
            if(cur != nullptr)
            {
                if (prev == nullptr)
                {
                    map[idx] = cur->next;
                }
                else
                {
                    prev->next = cur->next;
                }
                delete cur;
            }
            else
            {
                cout << "\nThere is no " << key << " in the hashmap\n";
            }
        }

        void display()
        {
            for (int i = 0; i < this->N; i++)
            {
                node *cur = map[i];
                cout << i << " : ";
                if (cur == nullptr)
                {
                    cout << "(empty)";
                }
                while(cur != nullptr)
                {
                    if (cur->next == nullptr)
                    {
                        cout << cur->val;
                    }
                    else
                    {
                        cout << cur->val << " ---> ";
                    }
                    cur = cur->next;
                }
                cout << endl;
            }
        }
};

int main() {
    // Test Case 1: Basic Insertion and Display
    cout << "Test Case 1:\n";
    hashmap hm1(5);
    hm1.insert(10);
    hm1.insert(15);
    hm1.insert(20);
    hm1.insert(25);
    hm1.insert(7);
    hm1.display();
    cout << endl;

    // Test Case 2: Deletion of an Existing Key
    cout << "Test Case 2:\n";
    hashmap hm2(5);
    hm2.insert(10);
    hm2.insert(15);
    hm2.insert(20);
    hm2.deleteKey(15);
    hm2.display();
    cout << endl;

    // Test Case 3: Deletion of a Non-Existent Key
    cout << "Test Case 3:\n";
    hashmap hm3(5);
    hm3.insert(10);
    hm3.insert(15);
    hm3.deleteKey(25);
    cout << endl;

    // Test Case 4: Multiple Collisions
    cout << "Test Case 4:\n";
    hashmap hm4(3);
    hm4.insert(3);
    hm4.insert(6);
    hm4.insert(9);
    hm4.insert(12);
    hm4.display();
    cout << endl;

    // Test Case 5: Edge Case - Empty Hashmap
    cout << "Test Case 5:\n";
    hashmap hm5(5);
    hm5.display();
    cout << endl;

    // Test Case 6: Delete All Elements
    cout << "Test Case 6:\n";
    hashmap hm6(4);
    hm6.insert(4);
    hm6.insert(8);
    hm6.insert(12);
    hm6.deleteKey(4);
    hm6.deleteKey(8);
    hm6.deleteKey(12);
    hm6.display();
    cout << endl;

    // Test Case 7: Single Element Handling
    cout << "Test Case 7:\n";
    hashmap hm7(2);
    hm7.insert(5);
    hm7.deleteKey(5);
    hm7.display();
    cout << endl;

    return 0;
}