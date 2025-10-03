def solution(today, terms, privacies):
    answer = []
    # 1. terms -> dict
    term_dict = {term.split()[0]: int(term.split()[1]) for term in terms}
    
    # print(term_dict)
    
    # 2. privacies
    for idx, pv in enumerate(privacies):
        date, _type = pv.split(' ')
        
        year, month, day = map(int,date.split('.'))
        
        month += term_dict[_type]
        year += (month-1) // 12
        month = (month-1) % 12 + 1

        
        # print(list(map(int, today.split('.'))))
        # print([year,month,day])
        if list(map(int, today.split('.'))) >= [year,month,day]:
            answer.append(idx+1)
        
        
    return answer

print(solution("2022.05.19", 
               ["A 6", "B 12", "C 3"], 
               ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]))
