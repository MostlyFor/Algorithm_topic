class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        
        if len(nums) == 0: return True
        
        prev = 0
        
        for i in range(len(nums)-1):
            if nums[i+1] == nums[i]: continue
            
            if prev * (nums[i+1] - nums[i]) < 0: return False
            
            prev = nums[i+1] - nums[i]

        
        return True