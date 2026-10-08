# [260. Single Number III](https://leetcode.com/problems/single-number-iii/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an integer array `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in **any order**.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

**Example 1:**

```
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
```

**Example 2:**

```
Input: nums = [-1,0]
Output: [-1,0]
```

**Example 3:**

```
Input: nums = [0,1]
Output: [1,0]
```

 

**Constraints:**

- `2 <= nums.length <= 3 * 104`

- `-231 <= nums[i] <= 231 - 1`

- Each integer in `nums` will appear twice, only two integers will appear once.

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.py)**

```python
diff = (int) Math.pow(2,Integer.numberOfTrailingZeros(diff));
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
