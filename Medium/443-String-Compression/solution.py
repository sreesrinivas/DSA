class Solution:
    def compress(self, chars: list[str]) -> int:
        
        count, i, out = 1, 0, ""

        while i < len(chars) - 1:
            if chars[i] == chars[i + 1]:
                count += 1
            else:
                if count > 1:
                    out += chars[i] + str(count)
                else:
                    out += chars[i]
                count = 1
            i += 1

        if count > 1:
            out += chars[i] + str(count)
        else:
            out += chars[i]

        chars[:len(out)] = out
        return len(out)
