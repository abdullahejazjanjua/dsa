#include <iostream>
using namespace std;

class Node 
{
public:
    int value;
    Node* left;
    Node* right;
    int height;

    Node(int key) 
    {
        value = key;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree 
{
private:
    // Right Rotation (Right-Heavy Tree)
    Node* rotateRight(Node* y) 
    {
        Node* x = y->left;         // Make x the new root
        Node* T2 = x->right;       // Store the right subtree of x

        // Perform the rotation
        x->right = y;              // Make y the right child of x
        y->left = T2;              // Make T2 (x's original right subtree) the left child of y

        // Update the heights of y and x
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;  // Return the new root of the subtree
    }

    // Left Rotation (Left-Heavy Tree)
    Node* rotateLeft(Node* x) 
    {
        Node* y = x->right;        // Make y the new root
        Node* T2 = y->left;        // Store the left subtree of y

        // Perform the rotation
        y->left = x;               // Make x the left child of y
        x->right = T2;             // Make T2 (y's original left subtree) the right child of x

        // Update the heights of x and y
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;  // Return the new root of the subtree
    }

    int getHeight(Node* root) 
    {
        if (root == NULL) return 0;
        return root->height;
    }

    int getBalance(Node* node) 
    {
        if (root == NULL) return 0;
        return getHeight(root->left) - getHeight(root->right);
    }

    Node* insert(Node* root, int key) 
    {
        if (root == NULL) return new Node(key);

        if (key < root->value)
            root->left = insert(root->left, key);
        else if (key > root->value)
            root->right = insert(root->right, key);

        // Update the height 
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Find the balance factor
        int balance = getBalance(root);

        // If this node becomes unbalanced, then there are four cases

        // Case 01: left left
        if (balance > 1 && key < root->left->value)
            return rotateRight(root); // Right rotation to fix the imbalance

        // Case 02: right right 
        if (balance < -1 && key > root->right->value)
            return rotateLeft(root); // Left rotation to fix the imbalance

        // Case 03: left right 
        if (balance > 1 && key > root->left->value) 
        {
            root->left = rotateLeft(root->left); // Left rotation on left child
            return rotateRight(root); // Right rotation on current node
        }

        // Case 04: right left case
        if (balance < -1 && key < root->right->value) 
        {
            root->right = rotateRight(root->right); // Right rotation on right child
            return rotateLeft(root); // Left rotation on current node
        }

        return root;
    }

    Node* inOrderPre(Node* root)
    {
        root = root->left;
        while (root->right != NULL)
        {
            root = root->right; 
        }
        return root;
    }

    Node* deleteNode(Node* root, int key)
    {
        if (root == NULL)
            return root;

        if (key < root->value)
        {
            root->left = deleteNode(root->left, key);
        }   
        else if (key > root->value)
        {
            root->right = deleteNode(root->right, key);
        }   
        else
        {
            // Case 01: No child
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // Case: 02 One child
            if (root->left == NULL)
            {
                Node* tmp = root->right;
                delete root;
                return tmp;
            }
            else if (root->right == NULL)
            {
                Node* tmp = root->left;
                delete root;
                return tmp;
            }
            // Case 03: 2 children
            else
            {
                Node* tmp = inOrderPre(root);
                root->value = tmp->value;
                root->left = deleteNode(root->left, tmp->value);
            }
        }

        // Update the height 
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        // Find the balance factor
        int balance = getBalance(root);

        // If this tree becomes unbalanced, then there are four cases

        // Case 01: left left
        if (balance > 1 && key < root->left->value)
            return rotateRight(root); // Right rotation to fix the imbalance

        // Case 02: right right 
        if (balance < -1 && key > root->right->value)
            return rotateLeft(root); // Left rotation to fix the imbalance

        // Case 03: left right 
        if (balance > 1 && key > root->left->value) 
        {
            root->left = rotateLeft(root->left); // Left rotation on left child
            return rotateRight(root); // Right rotation on current node
        }

        // Case 04: right left case
        if (balance < -1 && key < root->right->value) 
        {
            root->right = rotateRight(root->right); // Right rotation on right child
            return rotateLeft(root); // Left rotation on current node
        }

        return root;
    }

public:
    Node* root;

    AVLTree() 
    {
        root = NULL;
    }

    void insert(int key) 
    {
        root = insert(root, key);
    }

    void deleteKey(int key)
    {
        root = deleteNode(root, key);
    }

    void inOrder(Node* root) 
    {
        if (root != nullptr) 
        {
            inOrder(root->left);
            cout << root->value << " ";
            inOrder(root->right);
        }
    }

    void printInOrder() 
    {
        inOrder(root);
        cout << endl;
    }
};

int main() 
{
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);

    tree.printInOrder(); 

    tree.deleteKey(30);  
    tree.printInOrder(); 

    return 0;
}
