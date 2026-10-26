# [621. Task Scheduler](https://leetcode.com/problems/task-scheduler/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given an array of CPU `tasks`, each labeled with a letter from A to Z, and a number `n`. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of **at least** `n` intervals between two tasks with the same label.

Return the **minimum** number of CPU intervals required to complete all tasks.

 

**Example 1:**

**Input:** tasks = ["A","A","A","B","B","B"], n = 2

**Output:** 8

**Explanation:** A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

**Example 2:**

**Input:** tasks = ["A","C","A","B","D","B"], n = 1

**Output:** 6

**Explanation:** A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

**Example 3:**

**Input:** tasks = ["A","A","A", "B","B","B"], n = 3

**Output:** 10

**Explanation:** A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

 

**Constraints:**

- `1 <= tasks.length <= 104`

- `tasks[i]` is an uppercase English letter.

- `0 <= n <= 100`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.cpp)**

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int>mp(26,0);

        for(char i:tasks){
            mp[i-'A']++;  // count the number of times a task needs to be done
        }   
        for(int i=0;i<26;++i){
            if(mp[i]) 
            pq.push(mp[i]);
        }

        int time=0; // stores the total time taken 
        while(!pq.empty()){
            vector<int>remain;
            int cycle=n+1;  // n+1 is the CPU cycle length, if n is the cooldown period then after a task A there will be n more tasks. Hence n+1.

            while(cycle and !pq.empty()){
                int max_freq=pq.top(); // the task at the top should be first assigned the CPU as it has highest frequency
                pq.pop();
                if(max_freq>1){ // task with more than one occurrence, the next occurrence will be done in the next cycle 
                    remain.push_back(max_freq-1); // add it to remaining task list
                }
                ++time; 
                --cycle; 
            }

            for(int count:remain){
                pq.push(count); 
            }
            if(pq.empty())break; // if the priority queue is empty than all tasks are completed and we don't need to include the idle time
            time+=cycle; // this counts the idle time 
        }
        return time;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
