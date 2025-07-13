// Problem
/*
Ninja and his girlfriend want to shift to a new locality and want their houses distant. The homes in that locality are like nodes of a “Binary Search Tree.”

The distance between the houses is the difference between the house numbers.

Help Ninja and his girlfriend find the required location.

So, your task is to find the minimum absolute difference between any two nodes.
*/

// Code

oid inorder(TreeNode<int>* root, TreeNode<int>*& prev, int& res)
{
	if(!root)	return;

	inorder(root->left, prev, res);

	if(prev)	res = min(res, root->data - prev->data);
	prev = root;

	inorder(root->right, prev, res);
}
int ninjaGf(TreeNode<int> *root)
{
	int res = INT_MAX;
	TreeNode<int>* prev = NULL;
	inorder(root, prev, res);
	return res;
}
