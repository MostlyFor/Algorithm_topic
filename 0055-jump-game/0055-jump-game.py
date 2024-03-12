class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_idx = 0
        for i in range(len(nums)):
            if max_idx < i:
                return False
            max_idx = max(i + nums[i], max_idx)
        return True