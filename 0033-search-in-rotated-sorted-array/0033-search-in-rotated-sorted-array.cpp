
class Solution {
public:
    int binary_search(vector<int>& nums, int st, int ed, int target){
        while(st <= ed){
                int mid = (st+ed)/2;
                
                if(nums[mid] == target) return mid;
                else if(nums[mid] < target) st = mid+1;    
                else ed = mid-1;
        }
            
        return -1;
    }
    
    // log n이면 원소를 생략하면 봐야함
    int search(vector<int>& nums, int target) {
        int st = 0;
        int ed = nums.size()-1;
        
        // 꺾이는 지점이 없는 경우
        if(nums[st] <= nums[ed])
            return binary_search(nums, st, ed, target);
        
        // 꺾이는 지점이 있는 경우 -> lowest 지점 찾기
        int lowest = -1;
        while(nums[st] > nums[ed]){
            
            int mid = (st+ed)/2;

            // st와 mid 사이 증가 -> lowest는 mid+1 부터 후보
            if(nums[mid] >= nums[st]) st = mid+1;
            
            // st가 mid 보다 높음 -> ed 이전에 꺾임 -> lowest 후보 mid부터 후보
            else if(nums[mid] < nums[st]) ed = mid;
        }
        
        lowest = st;
        cout << lowest;
        
        if(target < nums[0] && target > nums.back()) return -1;
        // lowest ~ end 사이에 있는 경우
        else if(nums[lowest] <= target && target <= nums.back()) return binary_search(nums,lowest, nums.size()-1,target);
        else return binary_search(nums, 0, lowest-1,target);
        
            
    }
};