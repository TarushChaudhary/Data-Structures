#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
typedef struct node * nodeAddress;

int height(nodeAddress N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

nodeAddress newNode(int key)
{
    nodeAddress node = (nodeAddress)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}

nodeAddress rightRotate(nodeAddress y)
{
    nodeAddress x = y->left;
    nodeAddress T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

nodeAddress leftRotate(nodeAddress x)
{
    nodeAddress y = x->right;
    nodeAddress T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

int getBalance(nodeAddress N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

nodeAddress insert(nodeAddress node, int key)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

nodeAddress minValueNode(nodeAddress node)
{
    nodeAddress current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

nodeAddress deleteNode(nodeAddress root, int key)
{
    if (root == NULL)
        return root;

    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            nodeAddress temp = root->left ? root->left :
                                             root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
             *root = *temp; 
            free(temp);
        }
        else
        {
            nodeAddress temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
      return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(nodeAddress root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    nodeAddress root = NULL;

    root = insert(root, 12);
    root = insert(root, 25);
    root = insert(root, 32);
    root = insert(root, 40);
    root = insert(root, 52);
    root = insert(root, 23);

    printf("Preorder traversal of the constructed AVL tree is \n");
    preOrder(root);

    root = deleteNode(root, 25);

    printf("\nPreorder traversal after deletion of 25 \n");
    preOrder(root);

    return 0;
}
