#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};

class bst
{
    private:
        node *root;
        
        node *add(node *root, int val)
        {
            if(root == NULL)
            {
                node *newNode = new node;
                newNode->data = val;
                newNode->left = newNode->right = NULL;
                return newNode;
            }

            if (val < root->data)
            {
                root->left = add(root->left, val);
            }
            else if (val > root->data)
            {
                root->right = add(root->right, val);
            }
            return root; 
        }

        node *deleteNode(node *root, int val)
        {
            if (root == NULL)
            {
                return root;
            }

            if (val < root->data)
            {
                root->left = deleteNode(root->left, val);
            }
            else if (val > root->data)
            {
                root->right = deleteNode(root->right, val);
            }
            else
            {
                if (root->left == NULL && root->right == NULL)
                {
                    delete root;
                    root = NULL;
                    return root;
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
                    node *tmp = InOrderPre(root);
                    root->data = tmp->data;
                    root->left = deleteNode(root->left, tmp->data);
                }
            }
            return root;
            
        }
        node *InOrderPre(node *root)
        {
            root = root->left;
            while (root->right != NULL)
            {
                root = root->right;
            }
            return root;
        }

        void preOrder(node *root)
        {
            if (root == NULL)
                return;
            
            cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right); 
        }

        void inOrder(node *root)
        {
            if (root == NULL)
                return;
            
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }

        void postOrder(node *root)
        {
            if (root == NULL)
                return;

            postOrder(root->left);
            postOrder(root->right);
            cout << root->data << " ";
        }
    public:
        bst()
        {
            root = NULL;
        }
        void insert(int val)
        {
            root = add(root, val);
        }
        void deletion(int val)
        {
            root = deleteNode(root, val);
        }

        void traverseTree(int key)
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
    tree.traverseTree(0);
    cout << "\nPost-Order traversal: ";
    tree.traverseTree(1);
    cout << "\nIn-Order traversal: ";
    tree.traverseTree(2);

    
    tree.deletion(4);
    cout << endl;
    tree.traverseTree(2);
    return 0;
}