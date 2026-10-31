class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        res = []

        for i in range(left, right + 1):
            num = i

            while num != 0:
                divisor = num % 10

                if divisor == 0 or i % divisor != 0:
                    break

                num //= 10

            if num == 0:
                res.append(i)
                
        return res
