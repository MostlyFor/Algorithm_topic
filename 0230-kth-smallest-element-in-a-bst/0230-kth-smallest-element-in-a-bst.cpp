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
    void f(TreeNode* root, int k, priority_queue<int>& pq){
        
        if(root == nullptr) return;
        cout << root->val << ' ';
        if (pq.size() < k) pq.push(root->val);
        // k 개의 원소만 가지고 있는 pq 만들기
        else if(pq.size() == k && pq.top() > root->val) { pq.pop(); pq.push(root->val); }
        f(root->left, k, pq);
        f(root->right, k, pq);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        // 트리 순회 ->  k개의 원소만 가지고 있는 pq 정의 후 해결
        priority_queue<int> pq;
        
        f(root,k,pq);
        
        return pq.top();
    }
};