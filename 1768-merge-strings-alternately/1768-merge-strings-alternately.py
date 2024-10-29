class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        
        ans = ""
        
        for a,b in zip(word1, word2):
            ans+=a + b
        
        ans += word1[len(ans)//2:] + word2[len(ans)//2:]
        
        return ans