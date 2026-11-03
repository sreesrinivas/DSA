class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        s_length = 0
        
        # use set to remove duplicated words
        words_set = set(words)
        
        # sort by length in descending order
        sorted_words = sorted(words, key=len, reverse=True)
        
        # check from the longest word
        for word in sorted_words:
            print(word)
            if word in words_set:
                # add length of word + '#' char
                s_length += len(word) + 1
        
            # for all suffix words of current word
            for i in range(0, len(word) + 1):
                # remove suffix word since it does not affect to the final length
                if word[-i:] in words_set:
                    words_set.remove(word[-i:])
        
        return s_length
