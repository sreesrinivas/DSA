# [864. Shortest Path to Get All Keys](https://leetcode.com/problems/shortest-path-to-get-all-keys/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an `m x n` grid `grid` where:

- `'.'` is an empty cell.

- `'#'` is a wall.

- `'@'` is the starting point.

- Lowercase letters represent keys.

- Uppercase letters represent locks.

You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.

If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.

For some `1 <= k <= 6`, there is exactly one lowercase and one uppercase letter of the first `k` letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.

Return *the lowest number of moves to acquire all keys*. If it is impossible, return `-1`.

 

**Example 1:**

```
Input: grid = ["@.a..","###.#","b.A.B"]
Output: 8
Explanation: Note that the goal is to obtain all the keys not to open all the locks.
```

**Example 2:**

```
Input: grid = ["@..aA","..B#.","....b"]
Output: 6
```

**Example 3:**

```
Input: grid = ["@Aa"]
Output: -1
```

 

**Constraints:**

- `m == grid.length`

- `n == grid[i].length`

- `1 <= m, n <= 30`

- `grid[i][j]` is either an English letter, `'.'`, `'#'`, or `'@'`.

- There is exactly one `'@'` in the grid.

- The number of keys in the grid is in the range `[1, 6]`.

- Each key in the grid is **unique**.

- Each key in the grid has a matching lock.

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
class State {
public:
    int keys, i, j;
    State(int keys, int i, int j) {
        this->keys = keys;
        this->i = i;
        this->j = j;
    }
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int x = -1, y = -1, m = grid.size(), n = grid[0].size(), max_len = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = grid[i][j];
                if (c == '@') {
                    x = i;
                    y = j;
                }
                if (c >= 'a' && c <= 'f') {
                    max_len = max(c - 'a' + 1, max_len);
                }
            }
        }
        State start = State(0, x, y);
        queue<State> q;
        unordered_set<string> visited;
        visited.insert(to_string(0) + " " + to_string(x) + " " + to_string(y));
        q.push(start);
        int step = 0;
        vector<vector<int>> dirs {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                State curr = q.front();
                q.pop();
                if (curr.keys == (1 << max_len) - 1)
                    return step;
                for (auto &d : dirs) {
                    int i = curr.i + d[0];
                    int j = curr.j + d[1];
                    int keys = curr.keys;
                    if (i >= 0 && i < m && j >= 0 && j < n) {
                        char c = grid[i][j];
                        if (c == '#') continue;
                        if (c >= 'a' && c <= 'f') 
                            keys |= 1 << (c - 'a');
                        if (c >= 'A' && c <= 'F' && ((keys >> (c - 'A')) & 1) == 0) {
                            continue;
                        }
                        if (!visited.count(to_string(keys) + " " + to_string(i) + " " + to_string(j))) {
                            visited.insert(to_string(keys) + " " + to_string(i) + " " + to_string(j));
                            q.push(State(keys, i, j));
                        }
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
