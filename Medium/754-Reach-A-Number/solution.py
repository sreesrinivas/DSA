class Solution:
    def reachNumber(self, target: int) -> int:
        
        target = abs(target)

        step = 0
        _sum = 0
        
        while True:
            step += 1
            _sum += step
            
            if _sum == target:
                return step
            elif _sum > target and (_sum - target) % 2 == 0:
                return step
