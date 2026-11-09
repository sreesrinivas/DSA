# [910. Smallest Range II](https://leetcode.com/problems/smallest-range-ii/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums` and an integer `k`.

For each index `i` where `0 <= i < nums.length`, change `nums[i]` to be either `nums[i] + k` or `nums[i] - k`.

The **score** of `nums` is the difference between the maximum and minimum elements in `nums`.

Return *the minimum **score** of *`nums`* after changing the values at each index*.

 

**Example 1:**

```
Input: nums = [1], k = 0
Output: 0
Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
```

**Example 2:**

```
Input: nums = [0,10], k = 2
Output: 6
Explanation: Change nums to be [2, 8]. The score is max(nums) - min(nums) = 8 - 2 = 6.
```

**Example 3:**

```
Input: nums = [1,3,6], k = 3
Output: 3
Explanation: Change nums to be [4, 6, 3]. The score is max(nums) - min(nums) = 6 - 3 = 3.
```

 

**Constraints:**

- `1 <= nums.length <= 104`

- `0 <= nums[i] <= 104`

- `0 <= k <= 104`

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
    def smallestRangeII(self, nums: List[int], k: int) -> int:

        # Number of Elements
        N  = len(nums)
      
        # Sort so that we can have partition
        nums.sort()

        # Trivial Case, all incremented OR all decremented
        score = nums[-1] - nums[0]

        # To store minimum score
        ans   = score

        # Check all N-1 Non-Trivial partitions/walls. 
        # Both sets will be non-empty   
        for divider in range(0, N-1):

            # Compute maximum and minimum after partitioning
            # Kudos! We only have two candidates for each
            maximumAfterDivision = max(nums[divider]    + k , nums[-1] - k)
            minimumAfterDivision = min(nums[divider+1]  - k , nums[0]  + k)

            # Score after dividing here
            score = maximumAfterDivision - minimumAfterDivision

            # ans will be minimum score
            ans = min(ans, score)
        
        # return answer
        return ans
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
