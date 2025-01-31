class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        rowA = [0,0,0]
        colA = [0,0,0]
        rowB = [0,0,0]
        colB = [0,0,0]
        
        diaA = [0,0]
        diaB = [0,0]
        
        cnt = 1
        
        for r,c in moves:
            if cnt % 2 == 1: # A
                rowA[r]+=1
                colA[c]+=1
                diaA[0] += r==c
                diaA[1] += (r+c == 2) 
                if rowA[r] == 3 or colA[c] ==3 or diaA[0] == 3 or diaA[1] == 3:
                    return 'A'
            elif cnt % 2 == 0: # B
                rowB[r]+=1
                colB[c]+=1
                diaB[0] += r==c
                diaB[1] += (r+c == 2) 
                if rowB[r] == 3 or colB[c] ==3 or diaB[0] == 3 or diaB[1] == 3:
                    return 'B'
            
            cnt+=1
            
        if cnt == 10:
            return 'Draw'
        else:
            return 'Pending'
        
            
                