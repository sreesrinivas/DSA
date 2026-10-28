# [676. Implement Magic Dictionary](https://leetcode.com/problems/implement-magic-dictionary/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Design a data structure that is initialized with a list of **different** words. Provided a string, you should determine if you can change exactly one character in this string to match any word in the data structure.

Implement the `MagicDictionary` class:

- `MagicDictionary()` Initializes the object.

- `void buildDict(String[] dictionary)` Sets the data structure with an array of distinct strings `dictionary`.

- `bool search(String searchWord)` Returns `true` if you can change **exactly one character** in `searchWord` to match any string in the data structure, otherwise returns `false`.

 

**Example 1:**

```
Input
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
Output
[null, null, false, true, false, false]

Explanation
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // return False
magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
magicDictionary.search("hell"); // return False
magicDictionary.search("leetcoded"); // return False
```

 

**Constraints:**

- `1 <= dictionary.length <= 100`

- `1 <= dictionary[i].length <= 100`

- `dictionary[i]` consists of only lower-case English letters.

- All the strings in `dictionary` are **distinct**.

- `1 <= searchWord.length <= 100`

- `searchWord` consists of only lower-case English letters.

- `buildDict` will be called only once before `search`.

- At most `100` calls will be made to `search`.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
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
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
