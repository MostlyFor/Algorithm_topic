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
    pair<int,int> f(TreeNode*root, int& res){
        
        //자식이 없다면 0,0 리턴
        if(!root->left && !root->right){
            return {0,0};
        }  
        
        // 왼쪽 자식만 있는 경우
        if(root->left && !root->right){
            pair<int,int> tmp = f(root->left,res);
            int m = max(tmp.first,tmp.second);
            
            res = max(m+1,res);
            return {m+1,0};
        }
        // 오른쪽 자식만 있는 경우
        
        if(!root->left && root->right){
            pair<int,int> tmp = f(root->right,res);
            int m = max(tmp.first,tmp.second);
            res = max(m+1,res);
            
            return {0,m+1};
        }
        
        // 양쪽 자식이 모두 있는 경우
        else{
            pair<int,int> tmp_l = f(root->left,res);
            pair<int,int> tmp_r = f(root->right,res);
            
            int ml = max(tmp_l.first,tmp_l.second);
            int mr = max(tmp_r.first,tmp_r.second);

            
            res = max(ml+mr+2 ,res);
            return {ml+1,mr+1};
        }
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        
        pair<int,int> a =f(root,res);
        
        return res;
    }
};

//
