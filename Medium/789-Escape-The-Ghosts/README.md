# [789. Escape The Ghosts](https://leetcode.com/problems/escape-the-ghosts/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are playing a simplified PAC-MAN game on an infinite 2-D grid. You start at the point `[0, 0]`, and you are given a destination point `target = [xtarget, ytarget]` that you are trying to get to. There are several ghosts on the map with their starting positions given as a 2D array `ghosts`, where `ghosts[i] = [xi, yi]` represents the starting position of the `ith` ghost. All inputs are **integral coordinates**.

Each turn, you and all the ghosts may independently choose to either **move 1 unit** in any of the four cardinal directions: north, east, south, or west, or **stay still**. All actions happen **simultaneously**.

You escape if and only if you can reach the target **before** any ghost reaches you. If you reach any square (including the target) at the **same time** as a ghost, it **does not** count as an escape.

Return `true`* if it is possible to escape regardless of how the ghosts move, otherwise return *`false`*.*

 

**Example 1:**

```
Input: ghosts = [[1,0],[0,3]], target = [0,1]
Output: true
Explanation: You can reach the destination (0, 1) after 1 turn, while the ghosts located at (1, 0) and (0, 3) cannot catch up with you.
```

**Example 2:**

```
Input: ghosts = [[1,0]], target = [2,0]
Output: false
Explanation: You need to reach the destination (2, 0), but the ghost at (1, 0) lies between you and the destination.
```

**Example 3:**

```
Input: ghosts = [[2,0]], target = [1,0]
Output: false
Explanation: The ghost can reach the target at the same time as you.
```

 

**Constraints:**

- `1 <= ghosts.length <= 100`

- `ghosts[i].length == 2`

- `-104 <= xi, yi <= 104`

- There can be **multiple ghosts** in the same location.

- `target.length == 2`

- `-104 <= xtarget, ytarget <= 104`

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution 
{
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target)
    {
        int my_distance_from_target = abs(target[0]) + abs(target[1]);
        
        for( auto &g : ghosts )
        {
            if( my_distance_from_target >= ( abs(g[0] - target[0]) + abs(g[1] - target[1])) )return false;
        }
        
        return true;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
