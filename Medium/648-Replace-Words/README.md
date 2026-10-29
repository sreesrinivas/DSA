# [648. Replace Words](https://leetcode.com/problems/replace-words/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

In English, we have a concept called **root**, which can be followed by some other word to form another longer word - let's call this word **derivative**. For example, when the **root** `"help"` is followed by the word `"ful"`, we can form a derivative `"helpful"`.

Given a `dictionary` consisting of many **roots** and a `sentence` consisting of words separated by spaces, replace all the derivatives in the sentence with the **root** forming it. If a derivative can be replaced by more than one **root**, replace it with the **root** that has **the shortest length**.

Return *the `sentence`* after the replacement.

 

**Example 1:**

```
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
```

**Example 2:**

```
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
```

 

**Constraints:**

- `1 <= dictionary.length <= 1000`

- `1 <= dictionary[i].length <= 100`

- `dictionary[i]` consists of only lower-case letters.

- `1 <= sentence.length <= 106`

- `sentence` consists of only lower-case letters and spaces.

- The number of words in `sentence` is in the range `[1, 1000]`

- The length of each word in `sentence` is in the range `[1, 1000]`

- Every two consecutive words in `sentence` will be separated by exactly one space.

- `sentence` does not have leading or trailing spaces.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> s(begin(dict), end(dict));
        istringstream iss(sentence);
        vector<string> temp;
        string word, res; 

        while(iss >> word) temp.push_back(word);
        for(string t : temp) {
            int i = 0;
            while(i++ <= t.length()) {
                string curr = t.substr(0, i);
                if(s.find(curr) != s.end()) {
                    res += curr + " ";
                    break;
                }
                
                if(i == t.length()) res += curr + " ";
            }
        }

        res.erase(res.size() - 1);
        return res;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
