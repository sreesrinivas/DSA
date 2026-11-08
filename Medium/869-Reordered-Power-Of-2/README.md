# [869. Reordered Power of 2](https://leetcode.com/problems/reordered-power-of-2/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer `n`. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return `true` *if and only if we can do this so that the resulting number is a power of two*.

 

**Example 1:**

```
Input: n = 1
Output: true
```

**Example 2:**

```
Input: n = 10
Output: false
```

 

**Constraints:**

- `1 <= n <= 109`

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
public:
    // Count digit frequencies of a non-negative integer n
    vector<int> digitFreq(int n) {
        vector<int> freq(10, 0);
        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }
        return freq;
    }

    // Compare two frequency arrays (size 10) for equality
    bool equalFreq(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < 10; ++i)
            if (a[i] != b[i]) return false;
        return true;
    }

    bool reorderedPowerOf2(int N) {
        // Frequency of digits in the input number N
        vector<int> target = digitFreq(N);

        // Check all powers of two up to 2^30 (fits in 32-bit signed int ie till limit ie 10^9)
        for (int i = 0; i <= 30; ++i) {
            int powerof2 = (int)pow(2, i);; // 2^i
            if (equalFreq(target, digitFreq(powerof2)))
                return true;
        }
        return false;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
