def transform(s):
    return int(s[:2]) * 60 + int(s[3:])

def solution(fees, records):
    
    table = {} # 차량 번호 : 주차 시간
    car_table = {} # 차량 번호 : 최근 주차 시간
    
    for rec in records:
        time, number, inout = rec.split()
        time = transform(time)
        last_time = car_table.get(number, -1)
        
        if inout == "IN":
            car_table.update({number : time})
        else:
            car_table.pop(number)
            prev = table.get(number, 0)
            table.update({number:prev + time - last_time})
    
    
    for k, v in car_table.items():
        time = transform('23:59')
        last_time = car_table.get(k, -1)
        # car_table.pop(number)
        prev = table.get(k, 0)
        table.update({k: prev + time - last_time})
    

    tup = []
    # 테이블 비용 업데이트
    for k, v in table.items():
        if v <= fees[0]:
            tup.append((k, fees[1]))
        else:
            tup.append((k, fees[1] + ((v-fees[0]) //fees[2] + (((v-fees[0]) % fees[2]) != 0 )) *fees[3] ))
    
    tup.sort()
    
    answer = [x[1] for x in tup]
    
    return answer