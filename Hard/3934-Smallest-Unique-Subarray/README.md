# [3934. Smallest Unique Subarray](https://leetcode.com/problems/smallest-unique-subarray/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums`.

Find the **minimum **length of a subarray that is **not** **identical** to any other **subarray** in `nums`.

Return an integer denoting the **minimum possible length** of such a **subarray**.

Two **subarrays** are considered identical if they have the same length and the same elements in corresponding positions.

 

**Example 1:**

**Input:** nums = [3,3,3]

**Output:** 3

**Explanation:**

- Subarrays of length 1: `[3]` → appears 3 times

- Subarrays of length 2: `[3, 3]` → appears 2 times

- Subarrays of length 3: `[3, 3, 3]` → appears once

The subarray `[3, 3, 3]` is unique, so the smallest unique subarray length is 3.

**Example 2:**

**Input:** nums = [2,1,2,3,3]

**Output:** 1

**Explanation:**

Subarrays of length 1:

- `[2]` → appears 2 times

- `[1]` → appears once

- `[3]` → appears 2 times

The subarray `[1]` is unique, so the smallest unique subarray length is 1.

**Example 3:**

**Input:** nums = [1,1,2,2,1]

**Output:** 2

**Explanation:**

Subarrays of length 1:

- `[1]` → appears 3 times

- `[2]` → appears 2 times

Subarrays of length 2:

- `[1, 1]` → appears once

- `[1, 2]` → appears once

- `[2, 2]` → appears once

- `[2, 1]` → appears once

There is at least one subarray of length 2 that is unique, so the smallest unique subarray length is 2.

 

**Constraints:**

- `1 <= nums.length <= 105`

- `1 <= nums[i] <= 105`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        MOD1, MOD2 = 10**9 + 7, 10**9 + 9
        BASE1, BASE2 = 1000003, 1000033
        h1 = [0] * (n + 1)
        h2 = [0] * (n + 1)
        p1 = [1] * (n + 1)
        p2 = [1] * (n + 1)
        for i in range(n):
            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2
            p1[i + 1] = p1[i] * BASE1 % MOD1
            p2[i + 1] = p2[i] * BASE2 % MOD2
        def has_unique(length):
            cnt = {}
            for i in range(n - length + 1):
                a = (h1[i + length] - h1[i] * p1[length] % MOD1 + MOD1) % MOD1
                b = (h2[i + length] - h2[i] * p2[length] % MOD2 + MOD2) % MOD2
                key = (a, b)
                cnt[key] = cnt.get(key, 0) + 1
            return any(v == 1 for v in cnt.values())
        lo, hi, ans = 1, n, n
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            if has_unique(mid):
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        return ans
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
