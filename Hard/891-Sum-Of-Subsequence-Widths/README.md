# [891. Sum of Subsequence Widths](https://leetcode.com/problems/sum-of-subsequence-widths/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

The **width** of a sequence is the difference between the maximum and minimum elements in the sequence.

Given an array of integers `nums`, return *the sum of the **widths** of all the non-empty **subsequences** of *`nums`. Since the answer may be very large, return it **modulo** `109 + 7`.

A **subsequence** is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, `[3,6,2,7]` is a subsequence of the array `[0,3,1,6,2,2,7]`.

 

**Example 1:**

```
Input: nums = [2,1,3]
Output: 6
Explanation: The subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.
```

**Example 2:**

```
Input: nums = [2]
Output: 0
```

 

**Constraints:**

- `1 <= nums.length <= 105`

- `1 <= nums[i] <= 105`

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
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        long long MOD = 1e9 + 7;
        int n = nums.size();
        
        // Precompute powers of 2
        vector<long long> pow2(n);
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i-1] * 2) % MOD;
        }
        
        long long result = 0;
        
        for (int i = 0; i < n; i++) {
            // nums[i] as maximum contributes: nums[i] * 2^i
            // nums[i] as minimum contributes: -nums[i] * 2^(n-1-i)
            long long contribution = (nums[i] * pow2[i]) % MOD;
            contribution = (contribution - nums[i] * pow2[n-1-i]) % MOD;
            result = (result + contribution) % MOD;
        }
        
        // Handle negative result from modulo
        result = (result + MOD) % MOD;
        
        return (int)result;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
