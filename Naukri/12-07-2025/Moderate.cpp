// Problem
/*
You have been given a Binary Tree of 'n' nodes, where the nodes have integer values. Print the left view of the binary tree.
*/

// Code

vector<int> printLeftView(BinaryTreeNode<int>* root) {

    vector<int> res;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {

        int size = q.size();
        
        for(int i = 0; i < size; i ++) {

            BinaryTreeNode<int>* front = q.front();
            q.pop();

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);

            if(i == 0)  res.push_back(front->data);
        }
    }

    return res;
}