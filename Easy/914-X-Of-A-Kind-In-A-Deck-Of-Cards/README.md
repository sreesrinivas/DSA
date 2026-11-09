# [914. X of a Kind in a Deck of Cards](https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an integer array `deck` where `deck[i]` represents the number written on the `ith` card.

Partition the cards into **one or more groups** such that:

- Each group has **exactly** `x` cards where `x > 1`, and

- All the cards in one group have the same integer written on them.

Return `true`* if such partition is possible, or *`false`* otherwise*.

 

**Example 1:**

```
Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
```

**Example 2:**

```
Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
```

 

**Constraints:**

- `1 <= deck.length <= 104`

- `0 <= deck[i] < 104`

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
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        map<int,int>mpp;
        for(int i=0;i<deck.size();i++)
        {
            mpp[deck[i]]++;
        }
        int res = 0;
        for(auto it:mpp)
        {
            res = gcd(it.second,res);
        }
        return res>1;
    }
//please upvote...
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
