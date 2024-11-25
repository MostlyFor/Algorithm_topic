class Solution:
    def average(self, salary: List[int]) -> float:
        total, min_, max_ = 0, 1e9, 0
        for i in salary:
            total += i
            min_ = min(min_, i)
            max_ = max(max_, i)
            
        return (total-min_-max_) / (len(salary)-2)