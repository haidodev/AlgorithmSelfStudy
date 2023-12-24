#include <iostream>
using namespace std;

typedef struct Node
{
    int val;
    Node *left;
    Node *right;
} Node;

Node *newNode(int v)
{
    Node *node = new Node;
    node->val = v;
    node->left = node->right = NULL;
    return node;
}

Node *insert(Node *root, int v)
{
    if (root == NULL)
        return newNode(v);
    if (v < root->val)
        root->left = insert(root->left, v);
    else
        root->right = insert(root->right, v);
}

Node *findMax(Node *root)
{
    if (root == NULL)
        return NULL;
    if (root->right == NULL)
        return root;
    else
        return findMax(root->right);
}

Node *remove(Node *root, int v)
{
    if (root == NULL)
        return root;
    if (v < root->val)
        root->left = remove(root->left, v);
    else if (v > root->val)
        root->right = remove(root->right, v);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = findMax(root->left);
        root->val = temp->val;
        root->left = remove(root->left, temp->val);
    }
}