# [1079. Letter Tile Possibilities](https://leetcode.com/problems/letter-tile-possibilities/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: JavaScript](https://img.shields.io/badge/Language-JavaScript-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You have `n`  `tiles`, where each tile has one letter `tiles[i]` printed on it.

Return *the number of possible non-empty sequences of letters* you can make using the letters printed on those `tiles`.

 

**Example 1:**

```
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
```

**Example 2:**

```
Input: tiles = "AAABBC"
Output: 188
```

**Example 3:**

```
Input: tiles = "V"
Output: 1
```

 

**Constraints:**

- `1 <= tiles.length <= 7`

- `tiles` consists of uppercase English letters.

---

## 💡 Solution Explanation

Sorting-based greedy or two-pointer approach to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.js)**

```javascript
var numTilePossibilities = function(tiles) {
    tiles = tiles.split("").sort().join("");
    let used = new Array(tiles.length).fill(false);
    
    const backtrack = () => {
        let count = 0;
        for (let i = 0; i < tiles.length; i++) {
            if (used[i] || (i > 0 && tiles[i] === tiles[i - 1] && !used[i - 1])) continue;
            used[i] = true;
            count += 1 + backtrack();
            used[i] = false;
        }
        return count;
    };

    return backtrack();
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
