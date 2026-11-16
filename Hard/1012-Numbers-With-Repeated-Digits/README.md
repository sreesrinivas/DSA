# [1012. Numbers With Repeated Digits](https://leetcode.com/problems/numbers-with-repeated-digits/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer `n`, return *the number of positive integers in the range *`[1, n]`* that have **at least one** repeated digit*.

 

**Example 1:**

```
Input: n = 20
Output: 1
Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
```

**Example 2:**

```
Input: n = 100
Output: 10
Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
```

**Example 3:**

```
Input: n = 1000
Output: 262
```

 

**Constraints:**

- `1 <= n <= 109`

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
private:
    int permutation(int m, int n) {
        return n == 0 ? 1 : permutation(m, n - 1) * (m - n + 1);
    }
public:
    int numDupDigitsAtMostN(int N) {
        vector<int> digit;
        for (int i = N + 1; i > 0; i /= 10) {
            digit.push_back(i % 10);
        }
        reverse(digit.begin(), digit.end());
        
        int result = 0;
        int n = digit.size();
        for (int i = 1; i < n; i++) {
            result += 9 * permutation(9, i - 1);
        }
        
        // Count the number with same prefix
        unordered_set<int> seen;
        for (int i = 0; i < n; i++) {
            for (int j = i > 0 ? 0 : 1; j < digit[i]; j++) {
                if (seen.find(j) == seen.end()) {
                    result += permutation(9 - i, n - i - 1);
                }
            }
            if (seen.find(digit[i]) != seen.end()) {
                break;
            }
            seen.insert(digit[i]);
        }
        return N - result;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
