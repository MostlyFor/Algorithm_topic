class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> q;
        
        
        // O(NlogK)
        for(int i = 0; i<nums.size(); i++){
            q.push(-nums[i]);
            
            // pq -> log 1 + log 2 + ... + log K + log K +..
            if(q.size()>k){
                q.pop();
            }
            
        }
        
        return -q.top();
    }
};