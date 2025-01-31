class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        dir = 0 
        x = 0
        y = 0
        
        for cmd in instructions * 4:
            if cmd == 'G':
                x += dx[dir]
                y += dy[dir]
            elif cmd == 'R':
                dir = (dir+1) % 4
            elif cmd == 'L':
                dir = (dir+3) % 4
        
        if x==0 and y==0:
            return True
        else:
            return False
        