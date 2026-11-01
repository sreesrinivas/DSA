# [767. Reorganize String](https://leetcode.com/problems/reorganize-string/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `s`, rearrange the characters of `s` so that any two adjacent characters are not the same.

Return *any possible rearrangement of* `s` *or return* `""` *if not possible*.

 

**Example 1:**

```
Input: s = "aab"
Output: "aba"
```

**Example 2:**

```
Input: s = "aaab"
Output: ""
```

 

**Constraints:**

- `1 <= s.length <= 500`

- `s` consists of lowercase English letters.

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
    string reorganizeString(string s) {
        unordered_map<char, int> charFreq;
        for (char c : s) {
            charFreq[c]++;
        }

        auto comp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> maxHeap(comp);
        for (const auto& entry : charFreq) {
            maxHeap.push({entry.first, entry.second});
        }

        string res = "";
        pair<char, int> prev = {'#', 0};

        while (!maxHeap.empty()) {
            pair<char, int> current = maxHeap.top();
            maxHeap.pop();
            res += current.first;

            if (prev.second > 0) {
                maxHeap.push(prev);
            }

            current.second--;
            prev = current;
        }

        if (res.size() != s.size()) {
            return "";
        }

        return res;        
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
