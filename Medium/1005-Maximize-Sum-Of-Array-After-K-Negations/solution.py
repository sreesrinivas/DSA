class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        heapq.heapify(nums)
        while k:
            n = heapq.heappop(nums)
            heapq.heappush(nums, -n)
            k -= 1
        return sum(nums)
