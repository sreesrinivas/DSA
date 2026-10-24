# [564. Find the Closest Palindrome](https://leetcode.com/problems/find-the-closest-palindrome/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a string `n` representing an integer, return *the closest integer (not including itself), which is a palindrome*. If there is a tie, return ***the smaller one***.

The closest is defined as the absolute difference minimized between two integers.

 

**Example 1:**

```
Input: n = "123"
Output: "121"
```

**Example 2:**

```
Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
```

 

**Constraints:**

- `1 <= n.length <= 18`

- `n` consists of only digits.

- `n` does not have leading zeros.

- `n` is representing an integer in the range `[1, 1018 - 1]`.

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def nearestPalindromic(self, n: str) -> str:
        if int(n) <= 10 or (
            int(n) % 10 == 0 and int(n[1:]) == 0
        ):  # <= 10 or equal to 100, 1000, 10000, ... 
            return str(int(n) - 1)
        elif int(n) == 11 or (
            int(n) % 10 == 1 and n[0] == "1" and int(n[1:-1]) == 0
        ):  # 11 or 101, 1001, 10001, 100001, ... 
            return str(int(n) - 2)
        elif n[0] == "9" and n[0] * len(n) == n:  # 99, 999, 9999, 99999, ... 
            return str(int(n) + 2)
        else:
            def build_palindrome(base: str, is_even_length = True) -> str:
                """
                Build a palindrome using the given base.
                
                e.g.
                build_palindrome("123", True) = "123321"
                build_palindrome("123", False) = "12321"
                """
                if is_even_length:
                    return base + ''.join(reversed(base))
                else:
                    return base[:-1] + base[-1] + ''.join(reversed(base[:-1]))
                
            is_n_even = len(n) % 2 == 0
            palindrome_base = int(n[0: len(n) // 2]) if is_n_even else int(n[0: len(n) // 2 + 1])

            is_n_palindrome = build_palindrome(str(palindrome_base), is_n_even) == n
            base_candidates = [palindrome_base - 1, palindrome_base + 1] if is_n_palindrome \
                else [palindrome_base - 1, palindrome_base, palindrome_base + 1]  # Maintains increasing order
            # print(f"base_candidates: {base_candidates}")

            min_diff = float("inf")
            for base_candidate in base_candidates:
                candidate = int(build_palindrome(str(base_candidate), is_n_even))
                # print(f"candidate: {candidate} diff: {abs(candidate - int(n))}")
                if abs(candidate - int(n)) < min_diff:
                    min_diff = abs(candidate - int(n))
                    min_base_candidate = str(base_candidate)
            
            return build_palindrome(min_base_candidate, is_n_even)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
