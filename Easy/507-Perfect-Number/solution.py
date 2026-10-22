class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        sum_divisor = 0
        for i in range(1, num//2+1):
            if num%i == 0:
                sum_divisor += i
        return sum_divisor == num
