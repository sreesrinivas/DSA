class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        if name[0] != typed[0]: return False
        if name == typed: return True
        i = 0
        for ch in typed:
            if i < len(name) and name[i] == ch: i += 1
            else:
                if name[i-1] != ch: return False
        return i == len(name)
