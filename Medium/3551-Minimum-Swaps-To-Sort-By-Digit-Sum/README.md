# [3551. Minimum Swaps to Sort by Digit Sum](https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an array `nums` of **distinct** positive integers. You need to sort the array in **increasing** order based on the sum of the digits of each number. If two numbers have the same digit sum, the **smaller** number appears first in the sorted order.

Return the **minimum** number of swaps required to rearrange `nums` into this sorted order.

A **swap** is defined as exchanging the values at two distinct positions in the array.

 

**Example 1:**

**Input:** nums = [37,100]

**Output:** 1

**Explanation:**

- Compute the digit sum for each integer: `[3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]`

- Sort the integers based on digit sum: `[100, 37]`. Swap `37` with `100` to obtain the sorted order.

- Thus, the minimum number of swaps required to rearrange `nums` is 1.

**Example 2:**

**Input:** nums = [22,14,33,7]

**Output:** 0

**Explanation:**

- Compute the digit sum for each integer: `[2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]`

- Sort the integers based on digit sum: `[22, 14, 33, 7]`. The array is already sorted.

- Thus, the minimum number of swaps required to rearrange `nums` is 0.

**Example 3:**

**Input:** nums = [18,43,34,16]

**Output:** 2

**Explanation:**

- Compute the digit sum for each integer: `[1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]`

- Sort the integers based on digit sum: `[16, 34, 43, 18]`. Swap `18` with `16`, and swap `43` with `34` to obtain the sorted order.

- Thus, the minimum number of swaps required to rearrange `nums` is 2.

 

**Constraints:**

- `1 <= nums.length <= 105`

- `1 <= nums[i] <= 109`

- `nums` consists of **distinct** positive integers.

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
    def minSwaps(self, nums: List[int]) -> int:
        digit_sum = lambda x: sum(map(int, str(x)))
        rank = {x: k for k, x in enumerate(sorted(nums, key=lambda x: (digit_sum(x), x)))}  # final position of each value
        home = [rank[x] for x in nums]  # where the value at each position must go

        swaps = 0
        for i in range(len(home)):
            while home[i] != i:  # send the value at i home, take that spot's value in exchange
                j = home[i]
                home[i], home[j] = home[j], home[i]
                swaps += 1

        return swaps
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
