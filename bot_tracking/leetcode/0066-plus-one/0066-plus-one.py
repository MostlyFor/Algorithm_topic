class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        tmp = int("".join(str(ch) for ch in digits))+1
        return [int(i) for i in str(tmp)]
        
        