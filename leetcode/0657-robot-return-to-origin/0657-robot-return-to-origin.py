class Solution:
    def judgeCircle(self, moves: str) -> bool:
        x, y = 0, 0
        for move in moves:
            if move == 'U': x+=1
            elif move == 'D': x-=1
            elif move == 'R': y+=1
            elif move == 'L': y-=1
        
        return x == 0 and y == 0