class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        start = end = 0
        memo = collections.defaultdict(int)
        for s in s1:
            memo[s] += 1
        counter = len(memo)
        while end < len(s2):
            c = s2[end]
            if c in memo:
                memo[c] -= 1
                if memo[c] == 0:
                    counter -= 1
            end += 1
            while counter == 0:
                t = s2[start]
                if t in memo:
                    memo[t] += 1
                    if memo[t] >0 :
                        counter += 1
                if end - start == len(s1):
                    return True
                start += 1
        return False
