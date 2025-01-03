#include <iostream>
#include <queue>
using namespace std;

/*
Left-Left (LL) Case: BF of the unbalanced node is +2, and BF of its left child is ≥ 0.
This means the left subtree of the left child is heavier.

Left-Right (LR) Case: BF of the unbalanced node is +2, and BF of its left child is < 0.
This means the right subtree of the left child is heavier.

Right-Right (RR) Case: BF of the unbalanced node is -2, and BF of its right child is ≤ 0.
This means the right subtree of the right child is heavier.

Right-Left (RL) Case: BF of the unbalanced node is -2, and BF of its right child is > 0.
This means the left subtree of the right child is heavier.
*/


struct node
{
    int val;
    int height = 1;
    node *left = nullptr;
    node *right = nullptr;
};

class Tree
{
    node *root;

    node *add(node *root, int key)
    {
        if (root == nullptr)
        {
            node *newNode = new node;
            newNode->val = key;
            return newNode;
        }

        if(key < root->val)
        {
            root->left = add(root->left, key);
        }
        else if(key > root->val)
        {
            root->right = add(root->right, key);
        }

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bf = getBalanceFactor(root);

        // Left case
        if(bf > 1 && key < root->left->val)
        {
            return rotateRight(root);
        }

        if(bf > 1 && key > root->left->val)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right cases

        if(bf < -1 && key > root->right->val)
        {
            return rotateLeft(root);
        }

        if(bf < -1 && key < root->right->val)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;

    }
    node *deleteNode(node *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }

        if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            // No child
            if(root->left == nullptr && root->right == nullptr)
            {
                delete root;
                root = nullptr;
                return root;
            }
            // 1 Child
            else if(root->right == nullptr)
            {
                node *tmp = root->left;
                delete root;
                return tmp;
            }

            else if (root->left == nullptr)
            {
                node *tmp = root->right;
                delete root;
                return tmp;
            }
            // 2 children
            else
            {
                node *tmp = InOrderSuc(root);
                root->val = tmp->val;
                root->left = deleteNode(root->left, tmp->val);
            }
        }
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int bf = getBalanceFactor(root);

        // Left case
        if(bf > 1 && key < root->left->val)
        {
            return rotateRight(root);
        }

        if(bf > 1 && key > root->left->val)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        // Right cases

        if(bf < -1 && key > root->right->val)
        {
            return rotateLeft(root);
        }

        if(bf < -1 && key < root->right->val)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }
    node *rotateRight(node *y)
    {
        node *x = y->left;
        node *t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    node *rotateLeft(node *x)
    {
        node *y = x->right;
        node *t2 = y->left;

        y->left = x;
        x->right = t2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return y;
    }

    int getHeight(node *root)
    {
        if(root == nullptr)
        {
            return -1;
        }

        return root->height;
    }

    int getBalanceFactor(node *root)
    {
        if(root == nullptr)
        {
            return 0;
        }

        return getHeight(root->left) - getHeight(root->right);
    }
    
    node *InOrderSuc(node *root)
    {
        root = root->left;
        while(root != nullptr && root->right != nullptr)
        {
            root = root->right;
        }
        return root;
    }

    void InOrder(node *root)
    {
        if(root == nullptr)
        {
            return;
        }

        InOrder(root->left);
        cout << root->val << " ";
        InOrder(root->right);
    }
    
    void levelOrder(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        queue<node *> q;
        q.push(root);

        while(!q.empty())
        {
            node *cur = q.front();
            cout << cur->val << " ";
            q.pop();

            if(cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }

    }
    
    public:
        Tree()
        {
            root = nullptr;
        }

        void insert(int val)
        {
            root = add(root, val);
        }

        void deleteKey(int val)
        {
            root = deleteNode(root, val);
        }

        void traverse(int choice)
        {
            switch(choice)
            {
                case 0: 
                    InOrder(root);
                    break;
                case 1:
                    levelOrder(root);
                    break;
            }
        }

        
};

int main()
{
    Tree tree;
    
    tree.insert(99);
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);

    cout << "\nTraversal: ";
    tree.traverse(0);
    tree.deleteKey(5);
    cout << endl;
    tree.traverse(1);

    return 0;
}