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
    // Iterative PostOrder Traversal.
    stack<Node *> IterativePostOrder(Node *root)
    {
        stack<Node *> st;
        stack<Node *> ans;
        if (root)
        {
            st.push(root);
        }
        while (!st.empty())
        {
            Node *temp = st.top();
            st.pop();
            ans.push(temp);
            if (temp->left)
            {
                st.push(temp->left);
            }
            if (temp->right)
            {
                st.push(temp->right);
            }
        }
        return ans;
    }
    // Iterative InOrder Traversal.
    void IterativeInOrder(Node *root)
    {
        stack<Node *> st;
        Node *temp = root;
        while (true)
        {
            if (temp)
            {
                st.push(temp);
                temp = temp->left;
            }
            else
            {
                if (st.empty())
                {
                    break;
                }
                Node *node = st.top();
                st.pop();
                cout << node->data << " ";
                if (node->right)
                {
                    st.push(node->right);
                }
            }
        }
    }
    // Iterative PreOrder Traversal using Stack.
    void IterativePreOrder(Node *root)
    {
        stack<Node *> st;
        if (root)
        {
            st.push(root);
        }
        while (!st.empty())
        {
            Node *temp = st.top();
            st.pop();
            cout << temp->data << " ";
            if (temp->right)
            {
                st.push(temp->right);
            }
            if (temp->left)
            {
                st.push(temp->left);
            }
        }
    }
    // Level Order Traversal
    vector<vector<int>> BFS(Node *root)
    {
        queue<Node *> q;
        vector<vector<int>> ans;
        if (root)
        {
            q.push(root);
        }
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                Node *temp = q.front();
                q.pop();
                level.push_back(temp->data);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            ans.push_back(level);
        }
    }
    // Inorder Traversal using Recursion
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

    // Creating Tree from given array
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
    int arr[] = {1, 2, 3};
    Tree tree;
    Node *root = NULL;
    int n = sizeof(arr) / sizeof(int);
    root = tree.CreateTree(root, arr, 0, n);
    // tree.InOrderTraverse(root);
    // tree.BFS(root);
    // tree.IterativePreOrder(root);
    // tree.IterativeInOrder(root);
    stack<Node *> result = tree.IterativePostOrder(root);
    while (!result.empty())
    {
        cout << result.top()->data << " ";
        result.pop();
    }
    return 0;
}