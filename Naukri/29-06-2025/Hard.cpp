// Problem
/*
You are given an arbitrary binary tree, a node of the tree, and an integer 'K'. You need to find all such nodes which have a distance K from the given node and return the list of these nodes.



Distance between two nodes in a binary tree is defined as the number of connections/edges in the path between the two nodes.
*/

// Code

#include <bits/stdc++.h>
bool isLeaf(BinaryTreeNode<int>* root)
{
    if(root->left == NULL && root->right == NULL)   return true;

    return false;
}
void inorder(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parent)
{
    if(root == NULL || isLeaf(root))    return;

    inorder(root->left, parent);

    if(root->left)  parent[root->left] = root;
    if(root->right)  parent[root->right] = root;

    inorder(root->right, parent);
}
vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int k)
{    
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent;
    parent[root] = nullptr;

    inorder(root, parent);
    
    vector<BinaryTreeNode<int>*> res;

    int count = 0;
    unordered_map<BinaryTreeNode<int>*, bool> visited;
    queue<pair<BinaryTreeNode<int>*, int>> q;
    q.push({target, count});
    visited[target] = true;

    while(!q.empty())
    {
        auto front = q.front();
        q.pop();

        auto a = front.first;
        auto b = front.second;

        if(b > k)
        {
            break;
        }
        if(b == k)
        {
            res.push_back(a);
            continue;
        }

        if(a->left && !visited[a->left])
        {
            q.push({a->left, b + 1});
            visited[a->left] = true;
        }
        if(a->right && !visited[a->right])
        {
            q.push({a->right, b + 1});
            visited[a->right] = true;
        }
        if(parent[a] != NULL && !visited[parent[a]])
        {
            q.push({parent[a], b + 1});
            visited[parent[a]] = true;
        }
    }

    return res;
}