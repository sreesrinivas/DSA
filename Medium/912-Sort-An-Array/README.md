# [912. Sort an Array](https://leetcode.com/problems/sort-an-array/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an array of integers `nums`, sort the array in ascending order and return it.

You must solve the problem **without using any built-in** functions in `O(nlog(n))` time complexity and with the smallest space complexity possible.

 

**Example 1:**

```
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
```

**Example 2:**

```
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
```

 

**Constraints:**

- `1 <= nums.length <= 5 * 104`

- `-5 * 104 <= nums[i] <= 5 * 104`

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
from random import randint


def partition(array: list[int], low: int, high: int) -> int:
    # this is function for choosing pivot and partitate the array
    pivot: int = array[randint(low, high)]
    write_ind_smaller: int = low  # where to write elements smaller than pivot
    write_ind_greater: int = high  # where to write elements greater than pivot
    cur = low

    while cur < write_ind_greater + 1:
        num = array[cur]
        if num < pivot:
            array[write_ind_smaller], array[cur] = array[cur], array[write_ind_smaller]
            write_ind_smaller += 1
            cur += 1
        elif num > pivot:
            array[write_ind_greater], array[cur] = array[cur], array[write_ind_greater]
            write_ind_greater -= 1
        else:
            cur += 1

    return write_ind_smaller  # return index of the pivot


def quick_sort(array, low, high) -> None:  # [low, high]
    # Base case: if range is empty or contains only 1 element
    if low >= high:
        return

    pivot_ind: int = partition(array, low, high)
    quick_sort(array, low, pivot_ind - 1)  # left part
    quick_sort(array, pivot_ind + 1, high)  # right part


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        quick_sort(nums, 0, len(nums) - 1)
        return nums
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
