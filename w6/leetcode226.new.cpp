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
    //안에 값만 바꿔도 맞는 문제 -> 이렇게 풀면 개복잡함 그냥 자식을 바꾸는게 제일 빠름
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()){
            auto p = q.front(); q.pop();
            auto tmp = p->left;
            p->left = p->right;
            p->right = tmp;
            
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        
        
        
        return root;
    }
};