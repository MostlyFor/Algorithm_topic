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
        
        //아마 맨 마지막에 한칸 더 돌려서 느린 거 같음.
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> v(2*n,0);
            
            for(int i=0; i<n; i++){
                TreeNode* p = q.front();
                q.pop();
                if(p->left){
                    q.push(p->left);
                    v[i*2] = p->left->val;
                }
                else v[i*2] = 101;
                
                
                
                if(p->right) {
                    q.push(p->right);
                    v[i*2+1] = p->right->val;
                }
                else v[i*2+1] = 101;
            }
            
            for(auto i : v)
                cout << i << ' ';
            
            for(int i=0; i<n; i++)
                if(v[i]!=v[2*n-1-i]) return false;
        }
        
        return true;
    }
};