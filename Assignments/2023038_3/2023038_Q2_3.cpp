#include <iostream>
using namespace std;

struct Node
{
    string val;
    int id;
    Node *next;
};

class SingularList
{
    Node *head;
    public:
        SingularList()
        {
            head = nullptr;
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
        bool isEmpty() 
        {
            return head == nullptr;
        }

        void deleteList()
        {
            Node *tmp = head;
            while(head != NULL)
            {
                tmp = head;
                head = head->next;
                delete tmp;
            }
            head = nullptr;
        }

        void AddAtHead(string val, int id)
        {
            Node *newNode = new Node;
            newNode->next = head;
            newNode->val = val;
            newNode->id = id;
            head = newNode;
        }

        SingularList& operator=(const SingularList &other)
        {
            if (this != &other)  
            {
                deleteList();

                Node *tmp = other.head;
                while (tmp != nullptr)
                {
                    this->AddAtHead(tmp->val, tmp->id);
                    tmp = tmp->next;
                }
            }
            return *this;
        }


        void DeleteNode(int key)
        {
            Node *cur = head, *prev;

            if (head == NULL)
            {
                cout << "\nThe Linked List is empty\n";
                return;
            }
            while(cur != NULL && cur->id != key)
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

        void display()
        {
            Node *cur = head;
            cout << endl;
            
            if (cur == nullptr) {
                cout << "No incidents to display." << endl;
                return;
            }

            cout << "Incident List: " << endl;
            while (cur != NULL)
            {
                cout << "------------------------------" << endl;
                cout << "Incident ID: " << cur->id << endl;
                cout << "Description: " << cur->val << endl;
                
                if (cur->next != nullptr)
                    cout << "------------------------------" << endl; 
                cur = cur->next;
            }

            cout << "------------------------------" << endl;
        }

        
};



struct Node_tree 
{
    int key;
    string area;
    string city;
    SingularList L;
    Node_tree* left;
    Node_tree* right;
    int height;
};


class AVL 
{
private:
    Node_tree* root;

    int getHeight(Node_tree* node) 
    {
        return node ? node->height : 0;
    }

    int getBalanceFactor(Node_tree* node) 
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node_tree* leftRotate(Node_tree* x) 
    {
        Node_tree* y = x->right;
        Node_tree* T2 = y->left;

        y->left = x;
        x->right = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return y;
    }


    Node_tree* rightRotate(Node_tree* y) 
    {
        Node_tree* x = y->left;
        Node_tree* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    // Searching to add a new location at a location id
    Node_tree *addIncident(Node_tree *root, int id, string incident, int incident_id)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (root->key == id)
        {
            root->L.AddAtHead(incident, incident_id);
        }
        else if (id < root->key)
        {
            return addIncident(root->left, id, incident, incident_id);
        }
        else
        {
            return addIncident(root->right, id, incident, incident_id);
        }

    }

    Node_tree *deleteIncident(Node_tree *root, int id, int incident_id)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (root->key == id)
        {
            return root;
        }
        else if (id < root->key)
        {
            return deleteIncident(root->left, id, incident_id);
        }
        else
        {
            return deleteIncident(root->right, id, incident_id);
        }

    }



    Node_tree* add(Node_tree* node, string incident, int key, string area, string city, int incident_id) 
    {
        if (node == nullptr)
        {
            Node_tree *newNode = new Node_tree;
            newNode->key = key;
            newNode->area = area;
            newNode->city = city;
            newNode->left = newNode->right = nullptr;
            newNode->L.AddAtHead(incident, incident_id);
            return newNode;
        }

        if (key < node->key) 
        {
            node->left = add(node->left, incident, key, area, city, incident_id);
        } 
        else if (key > node->key)
        {
            node->right = add(node->right, incident, key, area, city, incident_id);
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        if (balance > 1 && key < node->left->key) 
        {
            return rightRotate(node);
        }
        if (balance > 1 && key > node->left->key) 
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key > node->right->key) 
        {
            return leftRotate(node);
        }
        if (balance < -1 && key < node->right->key) 
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }


    void InOrder(Node_tree* node) 
    {
        if (node == nullptr) 
        {
            return;
        }
        
        InOrder(node->left);
        cout << "\nAt " << node->key << " Incidents list: ";
        node->L.display();
        cout << endl;
        InOrder(node->right);
    }

    Node_tree* deleteNode(Node_tree* node, int key) 
    {
        if (!node) return node;

        if (key < node->key) 
        {
            node->left = deleteNode(node->left, key);
        } 
        else if (key > node->key) 
        {
            node->right = deleteNode(node->right, key);
        } 
        else 
        {
            node->L.deleteList();
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return nullptr;
            }
            else if (node->left == NULL)
            {
                Node_tree* tmp = node->right;
                delete node;
                return tmp;
            }
            else if (node->right == NULL)
            {
                Node_tree* tmp = node->left;
                delete node;
                return tmp;
            }
            else
            {
                Node_tree* tmp = inOrderPredecessor(node);
                node->key = tmp->key;
                node->L = tmp->L;
                node->left = deleteNode(node->left, tmp->key);
            }
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalanceFactor(node);

        if (balance > 1 && getBalanceFactor(node->left) >= 0)
        {
            return rightRotate(node);
        }
        if (balance > 1 && getBalanceFactor(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && getBalanceFactor(node->right) <= 0)
        {
            return leftRotate(node);
        }
        if (balance < -1 && getBalanceFactor(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }


    Node_tree* inOrderPredecessor(Node_tree* node) 
    {
        node = node->left;
        while (node != nullptr && node->right != NULL) 
        {
            node = node->right;
        }
        return node;
    }

public:

    AVL() : root(nullptr) {}

    void insert(string incident, int incident_id, int key, string area, string city) 
    {
        root = add(root, incident, key, area, city, incident_id);
    }

    void traverseTree() 
    {
        InOrder(root);
    }

    void deletion(int key) 
    {
        root = deleteNode(root, key);
    }

    void addNewIncident(string incident, int id, int incident_id)
    {
        Node_tree *node = addIncident(root, id, incident, incident_id);
        if(node != nullptr)
        {
            node->L.AddAtHead(incident, incident_id);
        }
        else
        {
            cout << "\nThe location doesnt exist in the tree\n";
        }
    }
    void deleteOldIncident(int id, int incident_id)
    {
        Node_tree *node = deleteIncident(root, id, incident_id);
        if(node != nullptr)
        {
            node->L.DeleteNode(incident_id);
        }
        else
        {
            cout << "\nThe location doesnt exist in the tree\n";
        }
    }

};



int main()
{
    AVL tree;

    cout << "Inserting first set of incidents..." << endl;
    tree.insert("Fire Near bank", 1, 120, "Zro-pt", "ISB");
    tree.addNewIncident("Traffic Accident", 120, 2);
    tree.addNewIncident("People fighting at street 3", 120, 3);
    tree.insert("Main road Suicide Attack", 1, 115, "F-7", "ISB");
    tree.addNewIncident("Gun fire", 115, 2);
    tree.insert("blast near Centaurus", 1, 125, "F-8", "ISB");
    
    cout << "\nTree after inserting first set of incidents:" << endl;
    tree.traverseTree();

    cout << "\nAdding new incidents to existing locations..." << endl;
    tree.addNewIncident("Explosion near restaurant", 120, 4);
    tree.addNewIncident("Car crash", 115, 3);

    tree.traverseTree();

    cout << "\nDeleting incident 3 in tree at location 115..."<<endl;
    tree.deleteOldIncident(115, 3);
    tree.traverseTree();


    

    cout << "\nTree after adding new incidents to existing locations:" << endl;
    tree.traverseTree();

    cout << "\nDeleting location with key 120..." << endl;
    tree.deletion(120);
    
    cout << "\nTree after deleting location with key 120:" << endl;
    tree.traverseTree();

    cout << "\nDeleting location with key 115 (single child)..." << endl;
    tree.deletion(115);
    
    cout << "\nTree after deleting location with key 115:" << endl;
    tree.traverseTree();

    cout << "\nDeleting location with key 125 (leaf node)..." << endl;
    tree.deletion(125);

    cout << "\nTree after deleting location with key 125:" << endl;
    tree.traverseTree();

    cout << "\nInserting new location with key 130..." << endl;
    tree.insert("Road collapsed near river", 1, 130, "Sector G", "ISB");
    tree.addNewIncident("Flooding", 130, 2);
    tree.addNewIncident("Bridge collapse", 130, 3);

    cout << "\nTree after inserting location with key 130:" << endl;
    tree.traverseTree();

   
}