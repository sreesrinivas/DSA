import heapq
class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        freq ={}
        for num in nums:
            freq[num] = freq.get(num,0)+1
        return heapq.nlargest(k,freq.keys(),key = freq.get)
