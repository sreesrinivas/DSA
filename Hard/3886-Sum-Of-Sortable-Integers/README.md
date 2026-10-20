# [3886. Sum of Sortable Integers](https://leetcode.com/problems/sum-of-sortable-integers/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums` of length `n`.

An integer `k` is called **sortable** if `k` **divides** `n` and you can sort `nums` in **non-decreasing** order by sequentially performing the following operations:

- Partition `nums` into **consecutive subarrays** of length `k`.

- **Cyclically rotate each subarray independently** any number of times to the left or to the right.

Return an integer denoting the sum of all possible sortable integers `k`.

 

**Example 1:**

**Input:** nums = [3,1,2]

**Output:** 3

**Explanation:**​​​​​​​

- For `n = 3`, possible divisors are 1 and 3.

- For `k = 1`: each subarray has one element. No rotation can sort the array.

- For `k = 3`: the single subarray `[3, 1, 2]` can be rotated once to produce `[1, 2, 3]`, which is sorted.

- Only `k = 3` is sortable. Hence, the answer is 3.

**Example 2:**

**Input:** nums = [7,6,5]

**Output:** 0

**Explanation:**

- For `n = 3`, possible divisors are 1 and 3.

- For `k = 1`: each subarray has one element. No rotation can sort the array.

- For `k = 3`: the single subarray `[7, 6, 5]` cannot be rotated into non-decreasing order.

- No `k` is sortable. Hence, the answer is 0.

**Example 3:**

**Input:** nums = [5,8]

**Output:** 3

**Explanation:**​​​​​​​

- For `n = 2`, possible divisors are 1 and 2.

- Since `[5, 8]` is already sorted, every divisor is sortable. Hence, the answer is `1 + 2 = 3`.

 

**Constraints:**

- `1 <= n == nums.length <= 105`

- `1 <= nums[i] <= 105`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def operation(self, k, nums):
        n = len(nums)
        chunks = n // k
        minMax = []

        for i in range(chunks):
            start = i * k
            mini = float('inf')
            maxi = float('-inf')
            cnt = 0

            for j in range(k):
                curr = nums[start + j]
                next_val = nums[start + (j + 1) % k]

                mini = min(mini, curr)
                maxi = max(maxi, curr)

                if curr > next_val:
                    cnt += 1

            if cnt > 1:
                return False

            minMax.append((mini, maxi))

        for i in range(chunks - 1):
            if minMax[i][1] > minMax[i + 1][0]:
                return False

        return True

    def sortableIntegers(self, nums):
        n = len(nums)
        ans = 0

        i = 1
        while i * i <= n:
            if n % i == 0:
                if self.operation(i, nums):
                    ans += i

                if i != n // i:
                    if self.operation(n // i, nums):
                        ans += (n // i)
            i += 1

        return ans
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
