// Problem
/*
You are given a binary tree. Return the count of unival sub-trees in the given binary tree. In unival trees, all the nodes, below the root node, have the same value as the data of the root.
*/

// Code

int find(BinaryTreeNode<int>* root, int& count)
{
    if(!root)   return -1;
    if(!root->left && !root->right)
    {
        count ++;
        return root->data;
    }

    int left = (root->left ? find(root->left, count) : root->data);
    int right = (root->right ? find(root->right, count) : root->data);

    if(left == root->data && right == root->data)
    {
        count ++;
        return root->data;
    }
    return -1;
}
int countUnivalTrees(BinaryTreeNode<int> *root)
{
    int count = 0;
    find(root, count);
    return count;
}