// Problem
/*
You are given a binary tree. You have to find all the duplicate sub-trees of the binary tree. For every duplicate subtree, you just have to return the root of the sub-tree. Two sub-trees are duplicates or the same if the nodes have the same value and the same structure.
*/

// Code

#include <bits/stdc++.h> 

string serialize(TreeNode<int> *root, vector<TreeNode<int>*>& res, unordered_map<string, int>& mpp){

    if(!root)   return "#";

    string left = serialize(root->left, res, mpp);
    string right = serialize(root->right, res, mpp);
    string current = to_string(root->data) + "," + left + "," + right;

    if(++mpp[current] == 2) res.push_back(root);

    return current;
}
vector<TreeNode<int>*> duplicate_subtree(TreeNode<int> *root){
    
    vector<TreeNode<int>*> res;
    unordered_map<string, int> mpp;

    serialize(root, res, mpp);
    return res;
}