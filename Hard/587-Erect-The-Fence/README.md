# [587. Erect the Fence](https://leetcode.com/problems/erect-the-fence/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an array `trees` where `trees[i] = [xi, yi]` represents the location of a tree in the garden.

Fence the entire garden using the minimum length of rope, as it is expensive. The garden is well-fenced only if **all the trees are enclosed**.

Return *the coordinates of trees that are exactly located on the fence perimeter*. You may return the answer in **any order**.

 

**Example 1:**

```
Input: trees = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation: All the trees will be on the perimeter of the fence except the tree at [2, 2], which will be inside the fence.
```

**Example 2:**

```
Input: trees = [[1,2],[2,2],[4,2]]
Output: [[4,2],[2,2],[1,2]]
Explanation: The fence forms a line that passes through all the trees.
```

 

**Constraints:**

- `1 <= trees.length <= 3000`

- `trees[i].length == 2`

- `0 <= xi, yi <= 100`

- All the given positions are **unique**.

---

## 💡 Solution Explanation

Sorting-based greedy or two-pointer approach to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
class Solution:
    def outerTrees(self, points: List[List[int]]) -> List[List[int]]:
        
        def crossProduct(p1,p2,p3):
            ### V1 = (a,b), V2 = (c,d)
            ### V1 X V2 = a*d - b*c
            
            ### V1 = (P2,P3)
            ### V2 = (P1,P2)
            
            a = p3[0]-p2[0]
            b = p3[1]-p2[1]
            c = p2[0]-p1[0]
            d = p2[1]-p1[1]
            
            return  a*d - b*c
        
        def constructHalfHull(points):
            stack = []
            for p in points:
                ### if the chain formed by the current point
                ### and the last two points in the stack is not counterclockwise, pop it
                while len(stack)>=2 and crossProduct(stack[-2],stack[-1],p)>0:
                    stack.pop()
                ### append the current point.
                stack.append(tuple(p))
            return stack
        
        ### sort points by x, so we are moving from left to right
        points.sort()
        leftToRight = constructHalfHull(points)
        ### reverse points, so we are moving from right to left
        rightToLeft = constructHalfHull(points[::-1])
        
        ### it is posible that the top and bottom parts have same points (e.g., all points form a line)
        ### we remove the duplicated points using a set
        return list(set(leftToRight + rightToLeft))
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
