# [524. Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `s` and a string array `dictionary`, return *the longest string in the dictionary that can be formed by deleting some of the given string characters*. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

 

**Example 1:**

```
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
```

**Example 2:**

```
Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
```

 

**Constraints:**

- `1 <= s.length <= 1000`

- `1 <= dictionary.length <= 1000`

- `1 <= dictionary[i].length <= 1000`

- `s` and `dictionary[i]` consist of lowercase English letters.

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:

    string findLongestWord(string s, vector<string>& dictionary) {
        
        int n(size(s));
        auto check = [&](string& str, int len) {
            for (int i=n-1; ~i and len-1>=0; i--)
                if (s[i] == str[len-1]) len--;
            return (len == 0);
        };
        
        string res;
        int maxLen(0);
        
        for (auto& word : dictionary) {
            int len(size(word));
            if (check(word, len) and (maxLen < len or (len == maxLen and (word < res or res.empty())))) {
                maxLen = len;
                res = word;
            }
        }
        return res;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
