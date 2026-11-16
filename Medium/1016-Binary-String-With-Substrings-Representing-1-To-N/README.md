# [1016. Binary String With Substrings Representing 1 To N](https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a binary string `s` and a positive integer `n`, return `true`* if the binary representation of all the integers in the range *`[1, n]`* are **substrings** of *`s`*, or *`false`* otherwise*.

A **substring** is a contiguous sequence of characters within a string.

 

**Example 1:**

```
Input: s = "0110", n = 3
Output: true
```

**Example 2:**

```
Input: s = "0110", n = 4
Output: false
```

 

**Constraints:**

- `1 <= s.length <= 1000`

- `s[i]` is either `'0'` or `'1'`.

- `1 <= n <= 109`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
// O(S^3)
class Solution {
    public boolean queryString(String S, int N) {
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < S.length(); i++){
            for(int j = i + 1; j <= S.length(); j++){
                int v = Integer.parseInt(S.substring(i, j), 2);
                
                if(v > 0 && v <= N){
                    set.add(v);
                } else {
                    break;
                }
            }
        }
        
        return set.size() == N;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
