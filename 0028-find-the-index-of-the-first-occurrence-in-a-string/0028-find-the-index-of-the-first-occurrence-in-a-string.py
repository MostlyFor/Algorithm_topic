class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        
        m = len(needle)
        
        for i in range(len(haystack)):
            if haystack[i:i+m] == needle:
                return i
        
        return -1
