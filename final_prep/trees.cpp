#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int val;
    int height = 1;
    node *left = nullptr;
    node *right = nullptr;
};

class tree
{
    private:
        node *root;
        node *add(node *root, int key)
        {
            if (root == nullptr)
            {
                node *newNode = new node;
                newNode->val = key;
                return newNode;
            }

            if (key < root->val)
            {
                root->left = add(root->left, key);
            }
            else if (key > root->val)
            {
                root->right = add(root->right, key);
            }

            root->height = 1 + max(getHeight(root->left), getHeight(root->right));

            int bf = getBalanceFactor(root);


            if (bf > 1 && key < root->left->val)
            {   
                return rightRotate(root);
            }

            if (bf > 1 && key > root->left->val)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            if (bf < -1 && key > root->right->val)
            {   
                return leftRotate(root);
            }

            if (bf < -1 && key < root->right->val)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;
        }

        node *deleteNode(node *root, int key)
        {
            if (root == nullptr)
            {
                return root;
            }

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
                if(root->left == nullptr && root->right == nullptr)
                {
                    delete root;
                    root = nullptr;
                    return root;
                }
                else if (root->left == nullptr)
                {
                    node *tmp = root->right;
                    delete root;
                    return tmp;
                }
                else if (root->right == nullptr)
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

            int bf = getBalanceFactor(root);


            if (bf > 1 && key < root->left->val)
            {   
                return rightRotate(root);
            }

            if (bf > 1 && key > root->left->val)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }

            if (bf < -1 && key > root->right->val)
            {   
                return leftRotate(root);
            }

            if (bf < -1 && key < root->right->val)
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root;

        }
        

        node *InOrderPre(node *root)
        {
            root = root->left;
            while (root != nullptr && root->right != nullptr)
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
        void PostOrder(node *root)
        {
            if(root == nullptr)
            {
                return;
            } 

            PostOrder(root->left);
            PostOrder(root->right);
            cout << root->val << " ";

        }

        void PreOrder(node *root)
        {
            if(root == nullptr)
            {
                return;
            } 
            
            cout << root->val << " ";
            PreOrder(root->left);
            PreOrder(root->right);
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
                if (cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }

        node *leftRotate(node *x)
        {
            node *y = x->right;
            node *t2 = y->left;

            y->left = x;
            x->right = t2;

            y->height = 1 + max(getHeight(y->left), getHeight(y->right));
            x->height = 1 + max(getHeight(x->left), getHeight(x->right));

            return y;
            
        }
        node *rightRotate(node *y)
        {
            node *x = y->left;
            node *t2 = x->right;

            x->right = y;
            y->left = t2;

            y->height = 1 + max(getHeight(y->left), getHeight(y->right));
            x->height = 1 + max(getHeight(x->left), getHeight(x->right));

            return x;
        }

        

    public:
        tree()
        {
            root = nullptr;
        }

        int getHeight(node *root)
        {
            if (root == nullptr)
                return -1;

            return root->height;
        }

        int getBalanceFactor(node *root)
        {
            if (root == nullptr)
                return 0;
            
            return getHeight(root->left) - getHeight(root->right);
        }

        void traverse(int choice)
        {
            switch(choice)
            {
                case 0:
                    InOrder(root);
                    break;
                case 1:
                    PreOrder(root);
                    break;
                case 2:
                    PostOrder(root);
                    break;
                case 3:
                    levelOrder(root);
                    break;
            }
        }
        void deletion(int val)
        {
            root = deleteNode(root, val);
        }

        void insert(int val)
        {
            root = add(root, val);
        }


        
};

int main()
{
    tree tree;
    tree.insert(4);
    tree.insert(5);
    tree.insert(3);
    tree.insert(9);
    tree.insert(2);


    cout << "\nPre-Order traversal: ";
    tree.traverse(1);
    cout << "\nPost-Order traversal: ";
    tree.traverse(2);
    cout << "\nIn-Order traversal: ";
    tree.traverse(0);
    cout << "\nLevel traversal: ";
    tree.traverse(3);

    tree.deletion(4);
    cout << endl;
    tree.traverse(0);

    return 0;
}