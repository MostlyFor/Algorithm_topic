def f(x, n):
    s = ""
    
    while x:
        if x % 2 == 1: s+='#'
        else: s+=' '
        x //= 2
    
    s += ' ' * (n - len(s))
    
    
    return s[::-1]

def solution(n, arr1, arr2):
    gold_arr = [arr1[i] | arr2[i] for i in range(n)]
    answer = []
    for x in gold_arr:
        answer.append(f(x, n))
    return answer