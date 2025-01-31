/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(!root) return 0;
        
        int ans =0;
        queue<pair<TreeNode*,int>> q;
        
        q.push({root,1});
        
        while(!q.empty()){
            auto tmp =q.front();
            auto pp=tmp.first;
            auto d = tmp.second;
            q.pop();
            
            if(pp->left) q.push({pp->left,d+1});
            if(pp->right) q.push({pp->right,d+1});
            
            ans = d;
        }
        
        return ans;
    }
};