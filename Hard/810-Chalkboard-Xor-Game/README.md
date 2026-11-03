# [810. Chalkboard XOR Game](https://leetcode.com/problems/chalkboard-xor-game/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an array of integers `nums` represents the numbers written on a chalkboard.

Alice and Bob take turns erasing exactly one number from the chalkboard, with Alice starting first. If erasing a number causes the bitwise XOR of all the elements of the chalkboard to become `0`, then that player loses. The bitwise XOR of one element is that element itself, and the bitwise XOR of no elements is `0`.

Also, if any player starts their turn with the bitwise XOR of all the elements of the chalkboard equal to `0`, then that player wins.

Return `true` *if and only if Alice wins the game, assuming both players play optimally*.

 

**Example 1:**

```
Input: nums = [1,1,2]
Output: false
Explanation: 
Alice has two choices: erase 1 or erase 2. 
If she erases 1, the nums array becomes [1, 2]. The bitwise XOR of all the elements of the chalkboard is 1 XOR 2 = 3. Now Bob can remove any element he wants, because Alice will be the one to erase the last element and she will lose. 
If Alice erases 2 first, now nums become [1, 1]. The bitwise XOR of all the elements of the chalkboard is 1 XOR 1 = 0. Alice will lose.
```

**Example 2:**

```
Input: nums = [0,1]
Output: true
```

**Example 3:**

```
Input: nums = [1,2,3]
Output: true
```

 

**Constraints:**

- `1 <= nums.length <= 1000`

- `0 <= nums[i] < 216`

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
class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        totalXor = 0
        for value in nums:
            totalXor ^= value
        
        isXorZero = (totalXor == 0)
        hasEvenLength = (len(nums) % 2 == 0)
        
        return isXorZero or hasEvenLength
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
