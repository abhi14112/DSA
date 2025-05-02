#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class Tree
{
public:
    void BFS(Node *root)
    {
        queue<Node *> q;
        if (root)
        {
            q.push(root);
        }
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    void InOrderTraverse(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        InOrderTraverse(root->left);
        cout << root->data << " ";
        InOrderTraverse(root->right);
    }
    Node *CreateTree(Node *root, int *arr, int index, int size)
    {
        if (index >= size)
        {
            return NULL;
        }
        root = new Node(arr[index]);
        if (index < size)
        {
            root->left = CreateTree(root, arr, (index * 2) + 1, size);
        }
        if (index + 1 < size)
        {
            root->right = CreateTree(root, arr, (index * 2) + 2, size);
        }
        return root;
    }
};
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    Tree tree;
    Node *root = NULL;
    int n = sizeof(arr) / sizeof(int);
    root = tree.CreateTree(root, arr, 0, n);
    // tree.InOrderTraverse(root);
    tree.BFS(root);
    return 0;
}