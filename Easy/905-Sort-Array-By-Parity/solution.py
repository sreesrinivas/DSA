class Solution(object):
    def sortArrayByParity(self, nums):
        r = 0
        l = len(nums) - 1

        while r < l:
            if nums[r] % 2 == 1 and nums[l] % 2 == 0:
                nums[r], nums[l] = nums[l], nums[r]
                r += 1
                l -= 1
            elif nums[r] % 2 == 0:
                r += 1
            elif nums[l] % 2 == 1:
                l -= 1

        return nums
