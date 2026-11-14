class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        if A > B:
            numberToLayDown = A
            numberToTopUp = B
            charToLayDown = "a"
            charToTopUp = "b"
        else:
            numberToLayDown = B
            numberToTopUp = A
            charToLayDown = "b"
            charToTopUp = "a"

            
        repetition = int(numberToLayDown / 2)
        remainder = numberToLayDown % 2
        
        stk = []
        for i in range(repetition):
            stk.append(charToLayDown + charToLayDown)
        if remainder:
            stk.append(charToLayDown)
        
        stkSize = len(stk)
        stkIdx = 0
        while numberToTopUp > 0:
            stk[stkIdx] += charToTopUp
            stkIdx = (stkIdx + 1) % stkSize
            numberToTopUp -= 1
            
        return "".join(stk)
