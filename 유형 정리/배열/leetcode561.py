class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        # O(N) 풀이 - 배열의 범위가 한정되었다는 것 이용
        bucket = [0] * 20001
        for x in nums: bucket[x + 10000]+=1

        cnt = 0 # 짝수 번째 다 더함
        ans = 0
        for i, c in enumerate(bucket):
            if c == 0: continue
            v = i - 10000
            ans += c // 2 * v
            if c % 2==0: continue
            cnt += c % 2
            if cnt % 2: ans += v

        return ans