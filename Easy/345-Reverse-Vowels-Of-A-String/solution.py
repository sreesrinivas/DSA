class Solution:
    def reverseVowels(self, s: str) -> str:
        s = list(s)
        i=0
        j=len(s)-1
        vowels={'a','e','i','o','u','A','E','I','O','U'}
        while i<=j:
            if  s[i] in vowels and s[j] in vowels:
                s[i], s[j] = s[j], s[i]
                i=i+1
                j=j-1
            elif s[i] in vowels:
                j=j-1
            elif s[j] in vowels:
                i=i+1
            else:
                i=i+1
                j=j-1
        return "".join(s)
