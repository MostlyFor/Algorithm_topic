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


// O(nlogk) : log1 + log2 + log 3 + log k + log k + .... -> nlogk
// class Solution {
// public:
//     void f(TreeNode* root, int k, priority_queue<int>& pq){
        
//         if(!root) return;
//         if (pq.size() < k) pq.push(root->val);
//         // k 개의 원소만 가지고 있는 pq 만들기
//         else if(pq.size() == k && pq.top() > root->val) { pq.pop(); pq.push(root->val); }
//         f(root->left, k, pq);
//         f(root->right, k, pq);
//     }
    
//     int kthSmallest(TreeNode* root, int k) {
//         // 트리 순회 ->  k개의 원소만 가지고 있는 pq 정의 후 해결
//         priority_queue<int> pq;
//         f(root,k,pq);
//         return pq.top();
//     }
// };


//O(n) : BST는 이미 정렬 + O(1) : vector 공간

// class Solution {
// public:
//     void f(TreeNode* root, int k, vector<int>& ans){
        
//         if(!root) return;
//         f(root->left, k, ans);
//         ans.push_back(root->val);
//         f(root->right, k, ans);
//     }
    
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> ans;
//         f(root,k,ans);
//         return ans[k-1];
//     }
// };



// O(n) + O(1)

class Solution {
    int ans = 0;
    int cnt = 0;
public:
    void f(TreeNode* root, int k){
        if(root->left) f(root->left, k);
        cnt++;
        if(k==cnt) ans = root->val;
        if(root->right) f(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        f(root,k);
        return ans; 
    }
};


