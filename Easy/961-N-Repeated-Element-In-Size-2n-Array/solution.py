class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        
        mp = {}
        for i in nums:
            if i in mp:
                return i
        
            mp[i] = 1
