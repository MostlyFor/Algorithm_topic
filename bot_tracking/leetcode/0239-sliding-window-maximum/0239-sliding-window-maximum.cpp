class Solution {
    
public:
    
    int init(int node, int s, int e, vector<int>& nums, vector<int>& tree){
        if(s==e)
            return tree[node] = nums[s];
        
        int mid = (s+e) / 2;
        
        tree[node * 2]= init(node*2, s, mid, nums, tree);
        tree[node *2 +1] = init(node*2+1, mid+1, e, nums,tree);
        
        return tree[node] = max(tree[node*2], tree[node*2+1]);
    }
    
    int max_el(int l, int r, int node, int s, int e,vector<int>& tree){
        if(s > r || e < l) return -1e9;
        
        if(l<=s && r>=e) {
            return tree[node];
        }
        
        int mid = (s+e) / 2;
        
        return max(max_el(l,r,node*2,s,mid,tree), max_el(l,r,node*2+1,mid+1,e,tree));
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nums2(1,0);
        for(int i=0; i<nums.size(); i++)
            nums2.push_back(nums[i]);
        vector<int> tree(n* 4,0);
        init(1, 1, n, nums2, tree); // nlogn 소요
        
        vector<int> answer;
        
        for (int i = 0; k + i <= n; i++) {
            answer.push_back(max_el(1 + i, k + i, 1, 1, n, tree));
        }
        
        return answer;
    }
};