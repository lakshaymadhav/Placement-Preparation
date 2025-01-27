/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) 
{
    if(root == NULL)
        return vector<vector<int>> ();
    
    vector<vector<int>> ans;
    
    queue<TreeNode *> q;
    q.push(root);
    
    int idx = 0;

    while(!q.empty())
    {
        int qsize = q.size();
        
        vector<int> each;
        stack<int> s;
        
        while(qsize--)
        {
            TreeNode *temp = q.front();
            q.pop();
            
            if(idx % 2 == 0)
                each.push_back(temp->val);
            else
                s.push(temp->val);
            
            if(temp->left != NULL)
                q.push(temp->left);
            
            if(temp->right != NULL)
                q.push(temp->right);
        }
        
        while(!s.empty())
        {
            each.push_back(s.top());
            s.pop();
        }
        
        ans.push_back(each);
        
        idx++;
    }

    return ans;
}
