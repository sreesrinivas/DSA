class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        letters = []

        # Store all letters
        for c in s:
            if c.isalpha():
                letters.append(c)

        # Reverse the letters
        letters.reverse()

        # Put reversed letters back
        result = list(s)
        index = 0

        for i in range(len(result)):
            if result[i].isalpha():
                result[i] = letters[index]
                index += 1

        return ''.join(result)
