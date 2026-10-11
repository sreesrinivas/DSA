# [352. Data Stream as Disjoint Intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given a data stream input of non-negative integers `a1, a2, ..., an`, summarize the numbers seen so far as a list of disjoint intervals.

Implement the `SummaryRanges` class:

- `SummaryRanges()` Initializes the object with an empty stream.

- `void addNum(int value)` Adds the integer `value` to the stream.

- `int[][] getIntervals()` Returns a summary of the integers in the stream currently as a list of disjoint intervals `[starti, endi]`. The answer should be sorted by `starti`.

 

**Example 1:**

```
Input
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
Output
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

Explanation
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // return [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
```

 

**Constraints:**

- `0 <= value <= 104`

- At most `3 * 104` calls will be made to `addNum` and `getIntervals`.

- At most `102` calls will be made to `getIntervals`.

 

**Follow up:** What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?

---

## 💡 Solution Explanation

Sorting-based greedy or two-pointer approach to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
import java.util.*;

class Pair implements Comparable<Pair>{
    int x, y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if(o == this) return true;
        if(!(o instanceof Pair)) return false;
        Pair pr = (Pair) o;
        return pr.x == x && pr.y == y;
    }

    @Override
    public int hashCode() {
        int result = x;
        return result * 31 + y;
    }

    @Override
    public int compareTo(Pair p) {
        if(this.x < p.x) return -1;
        else if(this.x > p.x) return 1;
        else{
            if(this.y == p.y) return 0;
            else if(this.y < p.y) return -1;
            else return 1;
        }
    }
}

class SummaryRanges {
    TreeSet<Pair> ranges;

    public SummaryRanges() {
        // maintain a sortedset of pairs
        ranges = new TreeSet<>();
    }
    
    public void addNum(int value) {
        // find lower and higher pairs and try to merge them
        Pair current = new Pair(value, value);
        int currLow = value, currHigh = value;
        Pair lower = ranges.lower(current);
        Pair higher = ranges.higher(current);
        boolean deleteLower = false, deleteUpper = false;
        if(lower != null && lower.y >= value - 1 && lower.x < value) {
            currLow = lower.x;
            currHigh = Math.max(lower.y, value);
            deleteLower = true;
        }
        if(higher != null && higher.x <= value + 1 && higher.y > value) {
            currHigh = higher.y;
            currLow = Math.min(currLow, higher.x);
            currLow = Math.min(currLow, value);
            deleteUpper = true;
        }
        // ranges.add(new Pair(value, value));
        if(deleteLower) ranges.remove(lower);
        if(deleteUpper) ranges.remove(higher);
        ranges.add(new Pair(currLow, currHigh));
    }
    
    public int[][] getIntervals() {
        // iterate over sorted set
        int[][] ans = new int[ranges.size()][2];
        int i = 0;
        for(Pair p: ranges) {
            ans[i][0] = p.x;
            ans[i++][1] = p.y;
        }
        return ans;
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(value);
 * int[][] param_2 = obj.getIntervals();
 */
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
