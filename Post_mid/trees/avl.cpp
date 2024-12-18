#include <iostream>
using namespace std;


struct node
{
    int val;
    node *left;
    node *right;
    int height;
};
class AVL
{
    private:
        node *root;

        int getHeight(node *root)
        {
            if (root == nullptr)
            {
                return 0;
            }
            return root->height;
        }

        int getBalanceFactor(node *root)
        {
            if (root == nullptr)
            {
                return 0;
            }

            return getHeight(root->left) - getHeight(root->right);
        }

        node *leftRotate(node *x)
        {
            node *y = x->right;
            node *T2 = y->left;

            y->left = x;
            x->right = T2;

            y->height = 1 + max(getHeight(y->right), getHeight(y->left));
            x->height = 1 + max(getHeight(x->right), getHeight(x->left));


            return y;
        }

        node *rightRotate(node *y)
        {
            node *x = y->left;
            node *T2 = x->right;

            x->right = y;
            y->left = T2;

            y->height = 1 + max(getHeight(y->right), getHeight(y->left));
            x->height = 1 + max(getHeight(x->right), getHeight(x->left));

            return x; 
        }

        node *add(node *root, int val)
        {
            if (root == nullptr)
            {   
                node *newNode = new node;
                newNode->left = newNode->right = nullptr;
                newNode->val = val;
                newNode->height = 1;
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


            root->height = 1 + max(getHeight(root->left), getHeight(root->right));

            int balancefactor = getBalanceFactor(root);
            
            // Left-Left Case
            if (balancefactor > 1 && val < root->left->val)
            {
                return rightRotate(root);
            }

            // Left-Right Case
            if(balancefactor > 1 && val > root->left->val)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            // Right-Right Case
            if (balancefactor < -1 && val > root->right->val)
            {
                return leftRotate(root);
            }

            // Right-Left Case
            if (balancefactor < -1 && val < root->right->val)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;
        }

        void preOrder(node *root)
        {
            if (root == NULL)
                return;
            
            cout << root->val << " ";
            preOrder(root->left);
            preOrder(root->right); 
        }

        void inOrder(node *root)
        {
            if (root == NULL)
                return;
            
            inOrder(root->left);
            cout << root->val << " ";
            inOrder(root->right);
        }

        void postOrder(node *root)
        {
            if (root == NULL)
                return;

            postOrder(root->left);
            postOrder(root->right);
            cout << root->val << " ";
        }

        node *deleteNode(node *root, int val)
        {
            if (root == NULL)
            {
                return root;
            }

            if (val < root->val)
            {
                root->left = deleteNode(root->left, val);
            }
            else if (val > root->val)
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
                    root->val = tmp->val;
                    root->left = deleteNode(root->left, tmp->val);
                }
            }

            root->height = 1 + max(getHeight(root->left), getHeight(root->right));
            int balanceFactor = getBalanceFactor(root);

            // Left-Left Case
            if (balanceFactor > 1 && val < root->left->val)
            {
                return rightRotate(root);
            }

            // left-Right Case
            if (balanceFactor > 1 && val > root->left->val)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            // Right-Right Case
            if (balanceFactor < -1 && val > root->right->val)
            {
                return leftRotate(root);
            }

            // Right-Left Case
            if (balanceFactor < -1 && val < root->right->val)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
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
    
    public:
        AVL()
        {
            root = nullptr;
        }

        void insert(int val)
        {
            root = add(root, val);
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

        void deletion(int val)
        {
            root = deleteNode(root, val);
        }
};

int main()
{

    AVL tree;
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