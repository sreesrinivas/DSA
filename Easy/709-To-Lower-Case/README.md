# [709. To Lower Case](https://leetcode.com/problems/to-lower-case/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `s`, return *the string after replacing every uppercase letter with the same lowercase letter*.

 

**Example 1:**

```
Input: s = "Hello"
Output: "hello"
```

**Example 2:**

```
Input: s = "here"
Output: "here"
```

**Example 3:**

```
Input: s = "LOVELY"
Output: "lovely"
```

 

**Constraints:**

- `1 <= s.length <= 100`

- `s` consists of printable ASCII characters.

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public String toLowerCase(String s) {
        return s.toLowerCase();
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
