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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        
        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
        
        if(q.size()==1) return false;
        
        
        
        while(!q.empty()){
            auto l = q.front(); q.pop();
            auto r = q.front(); q.pop();
            
            
            //잘 맞는 정의 : 값이 똑같으면 됨.
            
            if(l->val != r->val) return false;
            
            //이제 자식을 넣으면 됨. 자식이 없으면 그냥 넘어가면 됨.
            if(l->left || r->right){
                if(l->left && r->right){
                    q.push(l->left);
                    q.push(r->right);
                }
                else return false;
            }
            
             if(l->right || r->left){
                if(l->right && r->left){
                    q.push(l->right);
                    q.push(r->left);
                }
                else return false;
            }
                
            
        }
        
        
        return true;
    }
};