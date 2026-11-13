# [3420. Count Non-Decreasing Subarrays After K Operations](https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an array `nums` of `n` integers and an integer `k`.

For each subarray of `nums`, you can apply **up to** `k` operations on it. In each operation, you increment any element of the subarray by 1.

**Note** that each subarray is considered independently, meaning changes made to one subarray do not persist to another.

Return the number of subarrays that you can make **non-decreasing** ​​​​​after performing at most `k` operations.

An array is said to be **non-decreasing** if each element is greater than or equal to its previous element, if it exists.

 

**Example 1:**

**Input:** nums = [6,3,1,2,4,4], k = 7

**Output:** 17

**Explanation:**

Out of all 21 possible subarrays of `nums`, only the subarrays `[6, 3, 1]`, `[6, 3, 1, 2]`, `[6, 3, 1, 2, 4]` and `[6, 3, 1, 2, 4, 4]` cannot be made non-decreasing after applying up to k = 7 operations. Thus, the number of non-decreasing subarrays is `21 - 4 = 17`.

**Example 2:**

**Input:** nums = [6,3,1,3,6], k = 4

**Output:** 12

**Explanation:**

The subarray `[3, 1, 3, 6]` along with all subarrays of `nums` with three or fewer elements, except `[6, 3, 1]`, can be made non-decreasing after `k` operations. There are 5 subarrays of a single element, 4 subarrays of two elements, and 2 subarrays of three elements except `[6, 3, 1]`, so there are `1 + 5 + 4 + 2 = 12` subarrays that can be made non-decreasing.

 

**Constraints:**

- `1 <= nums.length <= 105`

- `1 <= nums[i] <= 109`

- `1 <= k <= 109`

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
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), head = n, tail = n, r = n - 1;
        vector<int> starts(n);  // where each plateau starts, left to right: starts[head..tail)
        long long ans = 0, water = 0;
        for (int l = n - 1; l >= 0; --l) {
            int x = nums[l];
            while (head < tail && nums[starts[head]] <= x) {  // x floods the plateau that starts at starts[head]
                int s = starts[head++];
                int end = head < tail ? starts[head] : r + 1;
                water += 1LL * (x - nums[s]) * (end - s);
            }
            starts[--head] = l;
            while (water > k) {  // the right end leaves with its water
                water -= nums[starts[tail - 1]] - nums[r];
                if (starts[tail - 1] == r)
                    --tail;
                --r;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
