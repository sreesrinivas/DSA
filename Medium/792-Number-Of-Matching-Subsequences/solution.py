class Solution:
    def isSubsequence(self, s, t):  # Return true if `t` is a subsequence of `s`
        i = 0
        for c in s:
            if i == len(t): return True
            if c == t[i]: i += 1    
        return i == len(t)
        
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        ans = 0
        for word in words:
            if self.isSubsequence(s, word):
                ans += 1
        return ans
