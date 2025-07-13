// Problem
/*
Given a binary tree, we need to install cameras on the nodes of the tree. Each camera at a node monitors its parent, itself, and its immediate children. Calculate the minimum number of cameras needed to monitor all nodes of the tree.
*/

// Code

int dfs(TreeNode<int>* root, int& cameraCount)
{
    if(!root)   return 2;

    int left = dfs(root->left, cameraCount);
    int right = dfs(root->right, cameraCount);

    if(left == 0 || right == 0)
    {
        cameraCount++;
        return 1;
    }

    if(left == 1 || right == 1)    return 2;

    return 0;
}
int getMinCamera(TreeNode<int> *root)
{
    int cameraCount = 0;

    if(dfs(root, cameraCount) == 0)  cameraCount ++;

    return cameraCount;
}