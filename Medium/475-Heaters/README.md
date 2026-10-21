# [475. Heaters](https://leetcode.com/problems/heaters/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Python3](https://img.shields.io/badge/Language-Python3-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.

Every house can be warmed, as long as the house is within the heater's warm radius range. 

Given the positions of `houses` and `heaters` on a horizontal line, return *the minimum radius standard of heaters so that those heaters could cover all houses.*

**Notice** that all the `heaters` follow your radius standard, and the warm radius will be the same.

 

**Example 1:**

```
Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
```

**Example 2:**

```
Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heaters were placed at positions 1 and 4. We need to use a radius 1 standard, then all the houses can be warmed.
```

**Example 3:**

```
Input: houses = [1,5], heaters = [2]
Output: 3
```

 

**Constraints:**

- `1 <= houses.length, heaters.length <= 3 * 104`

- `1 <= houses[i], heaters[i] <= 109`

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
def min_range(border_crossings, towers):
    """
    Returns the minimum range needed for a sensor to cover all border crossings.

    Args:
    border_crossings: A list of the border crossing locations.
    towers: A list of the tower locations.

    Returns:
    The minimum range needed for a sensor to cover all border crossings.
    """

    border_crossings.sort()
    towers.sort()
    res = []
    for crossing in border_crossings:
        min_distance = float("inf")
        for tower in towers:
            print('tower', tower)
            distance = abs(crossing - tower)
            min_distance = min(min_distance, distance)
        res.append(min_distance)
    return max(res)


border_crossings = [1, 2, 3, 4, 6, 10, 12]
towers = [1, 4, 6]
print(min_range(border_crossings, towers))
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
