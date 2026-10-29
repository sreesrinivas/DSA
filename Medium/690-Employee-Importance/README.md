# [690. Employee Importance](https://leetcode.com/problems/employee-importance/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs.

You are given an array of employees `employees` where:

- `employees[i].id` is the ID of the `ith` employee.

- `employees[i].importance` is the importance value of the `ith` employee.

- `employees[i].subordinates` is a list of the IDs of the direct subordinates of the `ith` employee.

Given an integer `id` that represents an employee's ID, return *the **total** importance value of this employee and all their direct and indirect subordinates*.

 

**Example 1:**

```
Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
Output: 11
Explanation: Employee 1 has an importance value of 5 and has two direct subordinates: employee 2 and employee 3.
They both have an importance value of 3.
Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.
```

**Example 2:**

```
Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
Output: -3
Explanation: Employee 5 has an importance value of -3 and has no direct subordinates.
Thus, the total importance value of employee 5 is -3.
```

 

**Constraints:**

- `1 <= employees.length <= 2000`

- `1 <= employees[i].id <= 2000`

- All `employees[i].id` are **unique**.

- `-100 <= employees[i].importance <= 100`

- One employee has at most one direct leader and may have several subordinates.

- The IDs in `employees[i].subordinates` are valid IDs.

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
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> m;
        for (int i = 0; i < employees.size(); ++i) {
            m[employees[i]->id] = employees[i];
        }
        if (m[id] == NULL) return 0;
        return getImportance(m[id], m);
    }
    
    int getImportance (Employee* curr, unordered_map<int,Employee*>& m) {
        if (curr && curr->subordinates.size() == 0) return curr->importance;
        int totalSubImp = 0;
        for (int i = 0; i < curr->subordinates.size(); ++i) {
            totalSubImp += getImportance(m[curr->subordinates[i]], m);
        }
        return curr->importance + totalSubImp;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
