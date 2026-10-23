# [557. Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `s`, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

**Example 1:**

```
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
```

**Example 2:**

```
Input: s = "Mr Ding"
Output: "rM gniD"
```

 

**Constraints:**

- `1 <= s.length <= 5 * 104`

- `s` contains printable **ASCII** characters.

- `s` does not contain any leading or trailing spaces.

- There is **at least one** word in `s`.

- All the words in `s` are separated by a single space.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
public class Solution {
    public string ReverseWords(string s) {
        char[] chars = s.ToCharArray();
        int start = 0;
        
        for (int i = 0; i < chars.Length; i++) {
            if (chars[i] == ' ' || i == chars.Length - 1) {
                int end = (i == chars.Length - 1 && chars[i] != ' ') ? i + 1 : i;
                while (start < end) {
                    char temp = chars[start];
                    chars[start] = chars[end - 1];
                    chars[end - 1] = temp;
                    start++;
                    end--;
                }
                start = i + 1;
            }
        }
        
        return new string(chars);
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
