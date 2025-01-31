/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 8.3 MB, less than 91.53% of C++ online submissions for Binary Tree Inorder Traversal.*/


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




// 중위 순회 -> 왼쪽부터 차례대로
class Solution {
public:
    void f(vector<int>& ans, TreeNode* p){
        if(p->left) 
            f(ans,p->left);
        
        ans.push_back(p->val);
        
        if(p->right)
            f(ans,p->right);
        
        return;
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        f(ans, root);
        
        
        return ans;
    }
};