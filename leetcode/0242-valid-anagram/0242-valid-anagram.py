class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # 모든 문자가 다 포함되어 있다면 count 써서 유니그램 비교할듯
        dict = {}
        
        for ch in s:
            now = dict.get(ch, 0) + 1
            dict[ch] = now
    
        for ch in t:
            now = dict.get(ch, 0) - 1
            dict[ch] = now
            
        
        for key, value in dict.items():
            if value != 0: return False
        
        return True