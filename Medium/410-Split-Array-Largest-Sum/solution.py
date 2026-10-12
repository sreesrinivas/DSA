from typing import List

class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        def pieces(limit):
            count, total = 1, 0
            for x in nums:
                if total + x > limit:
                    count += 1
                    total = x
                else:
                    total += x
            return count
        left, right = max(nums), sum(nums)
        while left < right:
            mid = (left + right) // 2
            if pieces(mid) > k:
                left = mid + 1
            else:
                right = mid
        return left
