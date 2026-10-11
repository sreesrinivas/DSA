from math import gcd
class Solution:
    def canMeasureWater(self, x: int, y: int, target: int) -> bool:
        if target>x+y:
            return False
        return target%gcd(x,y)==0

        #There's a trick for this : we can say that the jugs can be filled as per the required target only if the target in not greater than sum of containers capacity and also should satisfy the condition that target when divided by gcd of containers capacity should return 0 as remainder!!!!
