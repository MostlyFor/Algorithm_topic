class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i, j = 0, 0
        i_limit = len(word1)
        j_limit = len(word2)
        
        ans = ""
        while i != i_limit and j != j_limit:
            ans += word1[i]
            i+=1
            ans += word2[j]
            j+=1
        
        ans += word1[i:] + word2[j:]
        
        return ans
            