# [447. Number of Boomerangs](https://leetcode.com/problems/number-of-boomerangs/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given `n` `points` in the plane that are all **distinct**, where `points[i] = [xi, yi]`. A **boomerang** is a tuple of points `(i, j, k)` such that the distance between `i` and `j` equals the distance between `i` and `k` **(the order of the tuple matters)**.

Return *the number of boomerangs*.

 

**Example 1:**

```
Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
```

**Example 2:**

```
Input: points = [[1,1],[2,2],[3,3]]
Output: 2
```

**Example 3:**

```
Input: points = [[1,1]]
Output: 0
```

 

**Constraints:**

- `n == points.length`

- `1 <= n <= 500`

- `points[i].length == 2`

- `-104 <= xi, yi <= 104`

- All the points are **unique**.

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size(), booms = 0;
        unordered_map<int, int> distances;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distances[distance(points[i], points[j])]++;
            }
            for (auto& p : distances) {
                booms += p.second * (p.second - 1);
            }
            distances.clear();
        }
        return booms;
    }
private:
    int distance(pair<int, int>& p, pair<int, int>& q) {
        return (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
