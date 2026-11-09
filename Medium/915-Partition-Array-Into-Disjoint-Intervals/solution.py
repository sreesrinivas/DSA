class Solution(object):
    def partitionDisjoint(self, nums):
        # for x in range(1,len(nums)):
        #     if max(nums[:x])<=min(nums[x:]):
        #         return x
        # return 1
        n=len(nums)
        right=[0]*n
        right[n-1]=nums[n-1]
        for i in range(n-2,-1,-1):
            right[i]=min(nums[i],right[i+1])
        left=nums[0]
        for i in range(1,n):
            if left<=right[i]:
                return i
            left=max(left,nums[i])
