# [3934. Smallest Unique Subarray](https://leetcode.com/problems/smallest-unique-subarray/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
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

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public int smallestUniqueSubarray(int[] nums) {
        int n = nums.length;
        final long MOD1 = 1000000007L, MOD2 = 1000000009L;
        final long BASE1 = 1000003L, BASE2 = 1000033L;
        long[] h1 = new long[n + 1], h2 = new long[n + 1];
        long[] p1 = new long[n + 1], p2 = new long[n + 1];
        p1[0] = p2[0] = 1;
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2;
            p1[i + 1] = p1[i] * BASE1 % MOD1;
            p2[i + 1] = p2[i] * BASE2 % MOD2;
        }
        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUnique(nums, mid, h1, h2, p1, p2, MOD1, MOD2)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
    private boolean hasUnique(int[] nums, int len, long[] h1, long[] h2, long[] p1, long[] p2, long MOD1, long MOD2) {
        Map<Long, Integer> cnt = new HashMap<>();
        int n = nums.length;
        for (int i = 0; i + len <= n; i++) {
            long a = (h1[i + len] - h1[i] * p1[len] % MOD1 + MOD1) % MOD1;
            long b = (h2[i + len] - h2[i] * p2[len] % MOD2 + MOD2) % MOD2;
            long key = a * MOD2 + b;
            cnt.put(key, cnt.getOrDefault(key, 0) + 1);
        }
        for (int v : cnt.values()) if (v == 1) return true;
        return false;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
