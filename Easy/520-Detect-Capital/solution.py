class Solution:
    def detectCapitalUse(self, s: str) -> bool:
        return bool(fullmatch(r'[a-z]+|[A-Z]+|[A-Z][a-z]*',s))
