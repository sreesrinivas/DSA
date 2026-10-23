from collections import namedtuple

Result = namedtuple("Result", ["val", "str"])
ResultCache = {}

class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        if not nums: return ""
        ResultCache.clear()
        return self.getMax(nums, 0, len(nums) - 1).str
    
    def getMax(self, nums, start, end):
        cacheKey = f"max-{start}-{end}"
        if cacheKey in ResultCache:
            return ResultCache[cacheKey]
        
        result = Result(float("-inf"), None)
        
        if start == end:
            result = Result(nums[end], f"{nums[end]}")
        else:
            for idx in range(start, end):
                leftResult = self.getMax(nums, start, idx)
                rightResult = self.getMin(nums, idx + 1, end)
                if leftResult.val / rightResult.val > result.val:
                    resultStr = leftResult.str + "/" + (rightResult.str if end - idx < 2 else f"({rightResult.str})")
                    result = Result(leftResult.val / rightResult.val, resultStr)
        
        ResultCache[cacheKey] = result
        return result

    def getMin(self, nums, start, end):
        cacheKey = f"min-{start}-{end}"
        if cacheKey in ResultCache:
            return ResultCache[cacheKey]
        
        result = Result(float("inf"), None)
        if start == end:
            result = Result(nums[end], f"{nums[end]}")
        else:
            for idx in range(start, end):
                leftResult = self.getMin(nums, start, idx)
                rightResult = self.getMax(nums, idx + 1, end)
                if leftResult.val / rightResult.val < result.val:
                    resultStr = leftResult.str + "/" + (rightResult.str if end - idx < 2 else f"({rightResult.str})")
                    result = Result(leftResult.val / rightResult.val, resultStr)
        
        ResultCache[cacheKey] = result
        return result
