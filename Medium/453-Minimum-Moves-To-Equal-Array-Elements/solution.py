class Solution:
    def minMoves(self, nums: List[int]) -> int:       
        minElement = min(nums)
        targetSum = len(nums) * minElement
        totalSum = sum(nums)
        return totalSum-targetSum
