# [301. Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `s` that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return *a list of **unique strings** that are valid with the minimum number of removals*. You may return the answer in **any order**.

 

**Example 1:**

```
Input: s = "()())()"
Output: ["(())()","()()()"]
```

**Example 2:**

```
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
```

**Example 3:**

```
Input: s = ")("
Output: [""]
```

 

**Constraints:**

- `1 <= s.length <= 25`

- `s` consists of lowercase English letters and parentheses `'('` and `')'`.

- There will be at most `20` parentheses in `s`.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> ans = new ArrayList<>();
        remove(s, ans, 0, 0, new char[]{'(', ')'});
        return ans;
    }

    void remove(String s, List<String> ans, int i, int j, char[] p) {
        int count = 0;

        for (int k = i; k < s.length(); k++) {
            if (s.charAt(k) == p[0]) count++;
            if (s.charAt(k) == p[1]) count--;

            if (count < 0) {
                for (int x = j; x <= k; x++) {
                    if (s.charAt(x) == p[1] &&
                        (x == j || s.charAt(x - 1) != p[1])) {

                        remove(s.substring(0, x) +
                               s.substring(x + 1),
                               ans, k, x, p);
                    }
                }
                return;
            }
        }

        String rev = new StringBuilder(s).reverse().toString();

        if (p[0] == '(')
            remove(rev, ans, 0, 0, new char[]{')', '('});
        else
            ans.add(rev);
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
