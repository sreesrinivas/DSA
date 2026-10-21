# [479. Largest Palindrome Product](https://leetcode.com/problems/largest-palindrome-product/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer n, return *the **largest palindromic integer** that can be represented as the product of two `n`-digits integers*. Since the answer can be very large, return it **modulo** `1337`.

 

**Example 1:**

```
Input: n = 2
Output: 987
Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
```

**Example 2:**

```
Input: n = 1
Output: 9
```

 

**Constraints:**

- `1 <= n <= 8`

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
int largestPalindrome(int n) {
    if (n == 1) {
        return 9;
    }
    int maxFactor = pow(10, n) - 1; // max n digit number
    int minFactor = maxFactor / 10; // min n digit number - 1
    long maxProduct = (long) maxFactor * (long) maxFactor;
    int firstHalf = maxProduct / pow(10, n);
    while (firstHalf > minFactor) {
        long palindrome = createPalindrome(firstHalf);
        for (int i = maxFactor; palindrome / i <= maxFactor && (long)i * (long)i >= palindrome; --i) {
            if (palindrome % i == 0) {
                return palindrome % 1337;
            }
        }
        --firstHalf;
    }
    return -1;
}

long createPalindrome(long firstHalf) {
    std::string str = std::to_string(firstHalf);
    str += str;
    std::reverse(str.begin() + str.length() / 2, str.end());
    return stol(str);
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
