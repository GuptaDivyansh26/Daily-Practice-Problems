// Problem
/*
Given a binary tree, return the vertical order traversal of the values of the nodes of the given tree.

For each node at position (X, Y), (X-1, Y-1) will be its left child position while (X+1, Y-1) will be the right child position.

Running a vertical line from X = -infinity to X = +infinity, now whenever this vertical line touches some nodes, we need to add those values of the nodes in order starting from top to bottom with the decreasing ‘Y’ coordinates.

Note:
If two nodes have the same position, then the value of the node that is added first will be the value that is on the left side.
*/

// Code

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    	map<int, map<int, multiset<int>>> nodes;

    	queue<pair<TreeNode<int>*, pair<int, int>>> todo;

    	todo.push({root, {0, 0}});
        
    	while(!todo.empty())
	{
        	auto p = todo.front();
        	todo.pop();
        	TreeNode<int> *temp = p.first;
            
            	int x = p.second.first;
            	int y = p.second.second;

            	nodes[x][y].insert(temp->data);

            	if(temp->left)	todo.push({temp->left, {x-1, y+1}});

            	if(temp->right)	todo.push({temp->right, {x+1, y+1}});
        }
        
        vector<vector<int>> ans;

        for(auto p: nodes)
	{
            	vector<int> col;

            	for(auto q: p.second)
		{
                	col.insert(col.end(), q.second.begin(), q.second.end());
            	}

            	ans.push_back(col);
        }

        return ans;
}