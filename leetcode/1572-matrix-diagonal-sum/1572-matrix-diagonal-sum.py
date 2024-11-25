class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        ans = 0
        n = len(mat[0])
        for i in range(n):
            ans += mat[i][i]
            ans += mat[i][n-1-i]
        
        if n % 2 != 0:
             ans -= mat[n // 2][n // 2]

        return ans