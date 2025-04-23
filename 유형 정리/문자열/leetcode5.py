class Solution:
    def longestPalindrome(self, s: str) -> str:
        # 가장 단순한 풀이는 window를 s의 길이부터 잡으면서 확인 후 찾으면 종료 O(N^3)
        
        # 펠린드롬을 확인하는 과정에서 중복되는 연산 = abcde 확인 과정에서 bcd도 확인 가능 
        # 바깥에서 안쪽으로 가는 방식 말고 안쪽에서 바깥쪽으로 가는 방식으로 바꾸면 완전히 포함됨
        
        # 그렇다면 안쪽에서 바깥쪽으로 확장하는 방식 채택 O(N^2)


        ans = ""

        def find_palindrome(left :int, right :int):
            nonlocal ans
            while left >=0 and right < len(s) and s[left] == s[right]:
                if len(ans) < right - left + 1:
                    ans = s[left : right+1]
                left-=1
                right +=1

        for i in range(0, len(s)):
            find_palindrome(i,i) # 홀수 펠린드롬
            find_palindrome(i,i+1) # 짝수
                
        return ans