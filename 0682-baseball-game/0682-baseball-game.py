class Solution:
    def calPoints(self, operations: List[str]) -> int:
        
        result = [] 
        
        for i in range(len(operations)):
            ch = operations[i]
            if ch == '+':
                result.append(int(result[-1]) + int(result[-2]))
            elif ch == 'D':
                result.append(int(result[-1]) * 2)
            elif ch == 'C':
                result.pop()
            else:
                result.append(int(operations[i]))
                
        ans = sum(result)
        return ans