class Solution:
    def expressiveWords(self, s: str, words: list[str]) -> int:
        def groups(w):  # "heeello" -> ('h', 'e', 'l', 'o'), (1, 3, 2, 1)
            return zip(*((ch, len(list(gr))) for ch, gr in groupby(w)))

        chars, counts = groups(s)

        def stretchy(word: str) -> bool:
            wchars, wcounts = groups(word)
            return wchars == chars and all(c == w or c >= max(3, w) for c, w in zip(counts, wcounts))

        return sum(map(stretchy, words))
