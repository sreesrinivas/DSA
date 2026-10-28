class MagicDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.m = defaultdict(list)
        
    def calc(self, w1, w2):
        count = 0
        for i in range(len(w1)):
            count += w1[i] != w2[i]
        return count == 1
    
    def buildDict(self, dict: List[str]) -> None:
        """
        Build a dictionary through a list of words
        """
        for w in dict:
            self.m[len(w)].append(w)

    def search(self, word: str) -> bool:
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        """
        if len(word) in self.m:
            for w in self.m[len(word)]:
                if self.calc(w, word): return True
        return False
