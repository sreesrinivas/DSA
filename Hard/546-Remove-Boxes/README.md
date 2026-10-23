# [546. Remove Boxes](https://leetcode.com/problems/remove-boxes/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given several `boxes` with different colors represented by different positive numbers.

You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of `k` boxes, `k >= 1`), remove them and get `k * k` points.

Return *the maximum points you can get*.

 

**Example 1:**

```
Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
```

**Example 2:**

```
Input: boxes = [1,1,1]
Output: 9
```

**Example 3:**

```
Input: boxes = [1]
Output: 1
```

 

**Constraints:**

- `1 <= boxes.length <= 100`

- `1 <= boxes[i] <= 100`

---

## 💡 Solution Explanation

Dynamic programming / memoized recursion approach storing overlapping subproblems to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
def removeBoxes(self, boxes: List[int]) -> int:
        memo={}
        def dp(l, r, k):
            if l>r: return 0
            if (l,r,k) in memo: return memo[(l,r,k)]
            # while l<r and boxes[l]==boxes[l+1]: #got TLE
            #     l+=1
            #     k+=1
            ans = (k+1)*(k+1) + dp(l+1, r, 0)
            for m in range(l+1, r+1):
                if boxes[m]==boxes[l]:
                    ans = max(ans, dp(l+1, m-1, 0)+dp(m, r, k+1))
            memo[(l,r,k)]=ans
            return ans
        return dp(0, len(boxes)-1, 0)
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
