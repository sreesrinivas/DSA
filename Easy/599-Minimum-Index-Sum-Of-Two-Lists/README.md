# [599. Minimum Index Sum of Two Lists](https://leetcode.com/problems/minimum-index-sum-of-two-lists/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Given two arrays of strings `list1` and `list2`, find the **common strings with the least index sum**.

A **common string** is a string that appeared in both `list1` and `list2`.

A **common string with the least index sum** is a common string such that if it appeared at `list1[i]` and `list2[j]` then `i + j` should be the minimum value among all the other **common strings**.

Return *all the **common strings with the least index sum***. Return the answer in **any order**.

 

**Example 1:**

```
Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only common string is "Shogun".
```

**Example 2:**

```
Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The common string with the least index sum is "Shogun" with index sum = (0 + 1) = 1.
```

**Example 3:**

```
Input: list1 = ["happy","sad","good"], list2 = ["sad","happy","good"]
Output: ["sad","happy"]
Explanation: There are three common strings:
"happy" with index sum = (0 + 1) = 1.
"sad" with index sum = (1 + 0) = 1.
"good" with index sum = (2 + 2) = 4.
The strings with the least index sum are "sad" and "happy".
```

 

**Constraints:**

- `1 <= list1.length, list2.length <= 1000`

- `1 <= list1[i].length, list2[i].length <= 30`

- `list1[i]` and `list2[i]` consist of spaces `' '` and English letters.

- All the strings of `list1` are **unique**.

- All the strings of `list2` are **unique**.

- There is at least a common string between `list1` and `list2`.

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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> mp1;
    priority_queue<pair<int, string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
    vector<string> ret;
    for (int i = 0; i < list1.size(); i++) {
        mp1.insert(pair<string, int>(list1[i], i));
    }

    for (int i = 0; i < list2.size(); i++) {
        int idx = 0;
        auto found = mp1.find(list2[i]);
        if (found == mp1.end()) {
            continue;
        }
        else {
            pq.push(make_pair(found->second + i, list2[i]));
        }
    }
    auto prev = pq.top();
    while (!pq.empty()) {
        if (pq.top().first == prev.first) {
            ret.push_back(pq.top().second);
            prev = pq.top();
            pq.pop();
        }
        else {
            break;
        }
    }
    return ret;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
