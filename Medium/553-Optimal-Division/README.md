# [553. Optimal Division](https://leetcode.com/problems/optimal-division/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `nums`. The adjacent integers in `nums` will perform the float division.

- For example, for `nums = [2,3,4]`, we will evaluate the expression `"2/3/4"`.

However, you can add any number of parenthesis at any position to change the priority of operations. You want to add these parentheses such the value of the expression after the evaluation is maximum.

Return *the corresponding expression that has the maximum value in string format*.

**Note:** your expression should not contain redundant parenthesis.

 

**Example 1:**

```
Input: nums = [1000,100,10,2]
Output: "1000/(100/10/2)"
Explanation: 1000/(100/10/2) = 1000/((100/10)/2) = 200
However, the bold parenthesis in "1000/((100/10)/2)" are redundant since they do not influence the operation priority.
So you should return "1000/(100/10/2)".
Other cases:
1000/(100/10)/2 = 50
1000/(100/(10/2)) = 50
1000/100/10/2 = 0.5
1000/100/(10/2) = 2
```

**Example 2:**

```
Input: nums = [2,3,4]
Output: "2/(3/4)"
Explanation: (2/(3/4)) = 8/3 = 2.667
It can be shown that after trying all possibilities, we cannot get an expression with evaluation greater than 2.667
```

 

**Constraints:**

- `1 <= nums.length <= 10`

- `2 <= nums[i] <= 1000`

- There is only one optimal division for the given input.

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
from collections import namedtuple

Result = namedtuple("Result", ["val", "str"])
ResultCache = {}

class Solution:
    def optimalDivision(self, nums: List[int]) -> str:
        if not nums: return ""
        ResultCache.clear()
        return self.getMax(nums, 0, len(nums) - 1).str
    
    def getMax(self, nums, start, end):
        cacheKey = f"max-{start}-{end}"
        if cacheKey in ResultCache:
            return ResultCache[cacheKey]
        
        result = Result(float("-inf"), None)
        
        if start == end:
            result = Result(nums[end], f"{nums[end]}")
        else:
            for idx in range(start, end):
                leftResult = self.getMax(nums, start, idx)
                rightResult = self.getMin(nums, idx + 1, end)
                if leftResult.val / rightResult.val > result.val:
                    resultStr = leftResult.str + "/" + (rightResult.str if end - idx < 2 else f"({rightResult.str})")
                    result = Result(leftResult.val / rightResult.val, resultStr)
        
        ResultCache[cacheKey] = result
        return result

    def getMin(self, nums, start, end):
        cacheKey = f"min-{start}-{end}"
        if cacheKey in ResultCache:
            return ResultCache[cacheKey]
        
        result = Result(float("inf"), None)
        if start == end:
            result = Result(nums[end], f"{nums[end]}")
        else:
            for idx in range(start, end):
                leftResult = self.getMin(nums, start, idx)
                rightResult = self.getMax(nums, idx + 1, end)
                if leftResult.val / rightResult.val < result.val:
                    resultStr = leftResult.str + "/" + (rightResult.str if end - idx < 2 else f"({rightResult.str})")
                    result = Result(leftResult.val / rightResult.val, resultStr)
        
        ResultCache[cacheKey] = result
        return result
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
