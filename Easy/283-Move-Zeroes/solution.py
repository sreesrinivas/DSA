class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        snowBallSize = 0
        for i in range(0, len(nums)):
            if nums[i] == 0:
                snowBallSize += 1
            elif snowBallSize > 0:
                t = nums[i]
                nums[i] = 0
                nums[i - snowBallSize] = t
