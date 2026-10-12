class Solution:
    def longestPalindrome(self, s: str) -> int:
        freq = Counter(s)

        res = 0
        for val in freq.values():
            if res & 1 and val & 1:
                val -= 1
            
            res += val
        
        return res
