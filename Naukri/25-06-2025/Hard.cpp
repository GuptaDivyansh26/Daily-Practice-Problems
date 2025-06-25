// Problem
/*
Ninja is learning tree data structure these days. While learning, she came across learn about the Binary Search tree. She found BST quite interesting. She decided to make her own Binary Search Tree. Being a newbie, she made a mistake and swap two nodes of the Binary Search Tree.

Your responsibility being an expert and a good friend is to correct the Binary Search Tree made by Ninja and recover the correct Binary Search Tree.
*/

// Code

void inorder(TreeNode*& root, vector<TreeNode*>& nodes){

    if(!root)  return;

    inorder(root->left, nodes);
    nodes.push_back(root);
    inorder(root->right, nodes);
}
void recoverTree(TreeNode* root) {
    
    vector<TreeNode*> nodes;
    inorder(root, nodes);
    
    TreeNode* first = NULL;
    TreeNode* mid = NULL;
    TreeNode* last = NULL;

    for(int i = 0; i < nodes.size() - 1; i ++)
    {
        if(nodes[i]->data > nodes[i+1]->data) {

            if(!first)
            {
                first = nodes[i];
                mid = nodes[i+1];
            }
            else {

                last = nodes[i];
            }
        }
    }

    if(!last)   swap(first->data, mid->data);
    else    swap(first->data, last->data);

    return;
}