// Problem
/*
You have been given a Binary Search Tree of integers. You are supposed to return the k-th (1-indexed) smallest element in the tree.
*/

// Code

void inorder(TreeNode<int>* root, int& curr, int& k, TreeNode<int>*& ans)
{
    if(!root)   return;

    inorder(root->left, curr, k, ans);

    curr ++;
    if(curr == k)   ans = root;
    
    inorder(root->right, curr, k, ans);
}
int kthSmallest(TreeNode<int> *root, int& k)
{
    TreeNode<int>* ans = NULL;
    int curr = 0;

    inorder(root, curr, k, ans);
    
    return ans->data;
}