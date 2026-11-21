# [1109. Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

There are `n` flights that are labeled from `1` to `n`.

You are given an array of flight bookings `bookings`, where `bookings[i] = [firsti, lasti, seatsi]` represents a booking for flights `firsti` through `lasti` (**inclusive**) with `seatsi` seats reserved for **each flight** in the range.

Return *an array *`answer`* of length *`n`*, where *`answer[i]`* is the total number of seats reserved for flight *`i`.

 

**Example 1:**

```
Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10,55,45,25,25]
Explanation:
Flight labels:        1   2   3   4   5
Booking 1 reserved:  10  10
Booking 2 reserved:      20  20
Booking 3 reserved:      25  25  25  25
Total seats:         10  55  45  25  25
Hence, answer = [10,55,45,25,25]
```

**Example 2:**

```
Input: bookings = [[1,2,10],[2,2,15]], n = 2
Output: [10,25]
Explanation:
Flight labels:        1   2
Booking 1 reserved:  10  10
Booking 2 reserved:      15
Total seats:         10  25
Hence, answer = [10,25]
```

 

**Constraints:**

- `1 <= n <= 2 * 104`

- `1 <= bookings.length <= 2 * 104`

- `bookings[i].length == 3`

- `1 <= firsti <= lasti <= n`

- `1 <= seatsi <= 104`

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
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        result = [0] * (n+1)
        #mark the range with the deltas (head and tail)
        for booking in bookings:
            #start
            result[booking[0]-1] += booking[2]
            #end
            result[booking[1]] -= booking[2]
        #cumulative sum processing
        tmp = 0
        for i in range(n):
            tmp += result[i]
            result[i] = tmp
        return result[:n]
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
