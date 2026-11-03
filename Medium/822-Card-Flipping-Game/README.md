# [822. Card Flipping Game](https://leetcode.com/problems/card-flipping-game/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given two **0-indexed** integer arrays `fronts` and `backs` of length `n`, where the `ith` card has the positive integer `fronts[i]` printed on the front and `backs[i]` printed on the back. Initially, each card is placed on a table such that the front number is facing up and the other is facing down. You may flip over any number of cards (possibly zero).

After flipping the cards, an integer is considered **good** if it is facing down on some card and **not** facing up on any card.

Return *the minimum possible good integer after flipping the cards*. If there are no good integers, return `0`.

 

**Example 1:**

```
Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
Output: 2
Explanation:
If we flip the second card, the face up numbers are [1,3,4,4,7] and the face down are [1,2,4,1,3].
2 is the minimum good integer as it appears facing down but not facing up.
It can be shown that 2 is the minimum possible good integer obtainable after flipping some cards.
```

**Example 2:**

```
Input: fronts = [1], backs = [1]
Output: 0
Explanation:
There are no good integers no matter how we flip the cards, so we return 0.
```

 

**Constraints:**

- `n == fronts.length == backs.length`

- `1 <= n <= 1000`

- `1 <= fronts[i], backs[i] <= 2000`

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
    int flipgame(vector<int>& front, vector<int>& back) 
    {
        int n = front.size(), ans = INT_MAX;
        unordered_map<int, int> um;
        for(int i = 0; i < n; i++)
        {
            if(front[i] == back[i])
                um[front[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            if(!um.count(front[i]))
            {
                ans = min(ans, front[i]);
                um[front[i]]++;
            }
            if(!um.count(back[i]))
            {
                ans = min(ans, back[i]);
                um[back[i]]++;
            }
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
