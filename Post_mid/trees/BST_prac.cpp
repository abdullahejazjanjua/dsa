#include <iostream>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
};

class bst
{
    private:
        node *root;
        node *add(node *root, int val)
        {
            if (root == NULL)
            {
                node *newNode = new node;
                newNode->val = val;
                newNode->left = newNode->right = NULL;
                return newNode;
            }

            if (val < root->val)
            {
                root->left = add(root->left, val);
            }
            else if (val > root->val)
            {
                root->right = add(root->right, val);
            }

            return root;
        }
        node *InOrderPre(node *root)
        {
            root = root->left;
            while(root->right != NULL)
            {
                root = root->right;
            }
            return root;
        }
        node *InOrderPost(node *root)
        {
            root = root->right;
            while(root->left != NULL)
            {
                root = root->left;
            }
            return root;
        }

        node *deleteNode(node *root, int key)
        {
            if (root == NULL)
            {
                return NULL;
            }
            // Find the node
            if (key < root->val)
            {
                root->left = deleteNode(root->left, key);
            }
            else if (key > root->val)
            {
                root->right = deleteNode(root->right, key);
            }
            else
            {
                if (root->left == NULL && root->right == NULL)
                {
                    delete root;
                    return NULL;
                }
                else if (root->left == NULL)
                {
                    node *tmp = root->right;
                    delete root;
                    return tmp;
                }
                else if (root->right == NULL)
                {
                    node *tmp = root->left;
                    delete root;
                    return tmp;
                }
                else
                {
                    node *ipre = InOrderPre(root);
                    root->val = ipre->val;
                    root->left = deleteNode(root->left, ipre->val);
                }

                return root; // return the running root
            }
        }

        void postOrder(node *root)
        {
            if (root == NULL)
            {
                return;
            }

            postOrder(root->left);
            postOrder(root->right);
            cout << root->val << " ";
        }

        void preOrder(node *root)
        {
            if (root == NULL)
            {
                return;
            }
            cout << root->val << " ";
            postOrder(root->left);
            postOrder(root->right);
        }

        void inOrder(node *root)
        {
            if (root == NULL)
            {
                return;
            }

            postOrder(root->left);
            cout << root->val << " ";
            postOrder(root->right);
        }
    public:
        bst()
        {
            root = NULL;
        }

        void deletion(int key)
        {
            root = deleteNode(root, key);
        }
        void insert(int key)
        {
            root = add(root, key);
        }

        void traverse(int key)
        {
            switch(key)
            {
                case 0:
                    preOrder(root);
                    break;
                case 1:
                    postOrder(root);
                    break;
                case 2:
                    inOrder(root);
                    break;
            }
        }
};


int main()
{
    bst tree;
    tree.insert(4);
    tree.insert(5);
    tree.insert(3);
    tree.insert(9);
    tree.insert(2);

    cout << "\nPre-Order traversal: ";
    tree.traverse(0);
    cout << "\nPost-Order traversal: ";
    tree.traverse(1);
    cout << "\nIn-Order traversal: ";
    tree.traverse(2);

    cout << "\nAFTER DELETION: ";
    tree.deletion(4);
    cout << "\nIn-Order traversal: ";
    tree.traverse(2);
    cout << "\nPre-Order traversal: ";
    tree.traverse(0);
    return 0;
}