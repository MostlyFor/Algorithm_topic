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
    vector<int> inorderTraversal(TreeNode* root) {
        
        
        stack<TreeNode*> s;
        s.push(root);
        
        vector<int> ans;
        if(!root) return ans;
        
        
        unordered_set<TreeNode*> map;
        
        
        while(!s.empty()){
            TreeNode* p = s.top();
            s.pop();
            
            if(map.find(p)!=map.end()) {
                ans.push_back(p->val); continue;
            }
            
            if(!p->left && !p->right){
                ans.push_back(p->val); continue;
            }
            
            if(p->right){
                s.push(p->right);
            }
            
            s.push(p);
            
            
            if(p->left)
                s.push(p->left);
            
            
            map.insert(p);
            
        }
        
        
        
        return ans;
    }
};