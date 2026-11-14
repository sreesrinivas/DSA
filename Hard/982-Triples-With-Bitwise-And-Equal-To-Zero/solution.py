class Solution(object):
    def countTriplets(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        cnt = collections.defaultdict(int)
        for x in A:
            for y in A:
                cnt[x & y] += 1
        res = 0
        for num in A:
            for key in cnt.keys():
                if num&key == 0:
                    res += cnt[key]
        return res
