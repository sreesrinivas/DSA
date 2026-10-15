# [435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given an array of intervals `intervals` where `intervals[i] = [starti, endi]`, return *the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping*.

**Note** that intervals which only touch at a point are **non-overlapping**. For example, `[1, 2]` and `[2, 3]` are non-overlapping.

 

**Example 1:**

```
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
```

**Example 2:**

```
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
```

**Example 3:**

```
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
```

 

**Constraints:**

- `1 <= intervals.length <= 105`

- `intervals[i].length == 2`

- `-5 * 104 <= starti < endi <= 5 * 104`

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
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # sort intervals (meetings) by end time
        intervals.sort(key=lambda x: x[1])
        
        numberOfScheduledMeetings = len(intervals)
        prev = 0

        # We need to keep at least one meeting in our schedule
        meetingsToKeep = 1

        for cur in range(1, numberOfScheduledMeetings):
            '''
            start of second interval >= end of first interval
            i.e. second meeting starts after the first meeting ends
            i.e. NO OVERLAP
            So, we can keep the first meeting and move forward with our comparison 
            We also add this meeting to the tally of how many meetings
            we can keep in our schedule
            '''
            if intervals[cur][0] >= intervals[prev][1]:
                meetingsToKeep += 1

                # we can keep the previous meeting
                # So, now we check if we can keep the current one
                prev = cur

        # subtracting the number of meetings we can keep from total meetings
        # gives us the number of meetings we can remove from our schedule
        meetingsToRemove = numberOfScheduledMeetings - meetingsToKeep
        
        return meetingsToRemove
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
