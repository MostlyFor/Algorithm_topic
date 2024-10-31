class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr = sorted(arr)
        dt = arr[1] - arr[0] 

        for i in range(len(arr)-1):
            if arr[i+1] - arr[i] != dt:
                return False
            
        return True
        