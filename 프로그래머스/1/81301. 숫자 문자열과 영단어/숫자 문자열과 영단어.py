dict1 = {'zero' : '0', 'one' : '1'}
def solution(s):
    
    for k, v in dict1.items():
        s = s.replace(k, v);
    s = s.replace('two', '2')
    s = s.replace('three', '3')
    s = s.replace('four', '4')
    s = s.replace('five', '5')
    s = s.replace('six', '6')
    s = s.replace('seven', '7')
    s = s.replace('eight', '8')
    s = s.replace('nine', '9')
    
    return int(s)