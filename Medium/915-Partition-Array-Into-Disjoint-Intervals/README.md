# [915. Partition Array into Disjoint Intervals](https://leetcode.com/problems/partition-array-into-disjoint-intervals/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer array `nums`, partition it into two (contiguous) subarrays `left` and `right` so that:

- Every element in `left` is less than or equal to every element in `right`.

- `left` and `right` are non-empty.

- `left` has the smallest possible size.

Return *the length of *`left`* after such a partitioning*.

Test cases are generated such that partitioning exists.

 

**Example 1:**

```
Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
```

**Example 2:**

```
Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
```

 

**Constraints:**

- `2 <= nums.length <= 105`

- `0 <= nums[i] <= 106`

- There is at least one valid answer for the given input.

---

## 💡 Solution Explanation

Binary search approach dividing the search range logarithmically to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution(object):
    def partitionDisjoint(self, nums):
        # for x in range(1,len(nums)):
        #     if max(nums[:x])<=min(nums[x:]):
        #         return x
        # return 1
        n=len(nums)
        right=[0]*n
        right[n-1]=nums[n-1]
        for i in range(n-2,-1,-1):
            right[i]=min(nums[i],right[i+1])
        left=nums[0]
        for i in range(1,n):
            if left<=right[i]:
                return i
            left=max(left,nums[i])
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
