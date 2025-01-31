class Solution:
    def __init__(self):
        self.r = 0
        self.c = 0

    def is_out(self, x, y) -> bool:
        return x < 0 or y <0 or x >=self.r or y >=self.c
    
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        self.r = len(matrix)
        self.c = len(matrix[0])
        visited = [[False] * self.c for _ in range(self.r)]
        
        dx = [0,1,0,-1]
        dy = [1,0,-1,0]
        x,y, d = 0,0,0
        
        cnt = 0
        
        ans = []

        while cnt != self.r*self.c:
            ans.append(matrix[x][y])
            visited[x][y] = True
            nx = x + dx[d]
            ny = y + dy[d]
            
            
            if self.is_out(nx, ny) or visited[nx][ny]:
                d += 1
                d %= 4
                nx = x + dx[d]
                ny = y + dy[d]   
            
            x = nx
            y = ny
            cnt+=1
        
        
        return ans