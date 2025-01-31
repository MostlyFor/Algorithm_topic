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
    bool ans = true;
    // INT_MIN = -2147483648
    long long level =  -2147483649;
    
    void f(TreeNode* root){
        if(!ans) return;
        
        if(root->left) f(root->left);
        
        
        if(level >= root->val) ans = false;
        else level = root->val;
        
        
        if(root->right) f(root->right);
    }
    
    
    bool isValidBST(TreeNode* root) {
        
        
        f(root);
        
        
        return ans;
    }
};