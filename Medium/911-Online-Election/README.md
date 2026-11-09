# [911. Online Election](https://leetcode.com/problems/online-election/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given two integer arrays `persons` and `times`. In an election, the `ith` vote was cast for `persons[i]` at time `times[i]`.

For each query at a time `t`, find the person that was leading the election at time `t`. Votes cast at time `t` will count towards our query. In the case of a tie, the most recent vote (among tied candidates) wins.

Implement the `TopVotedCandidate` class:

- `TopVotedCandidate(int[] persons, int[] times)` Initializes the object with the `persons` and `times` arrays.

- `int q(int t)` Returns the number of the person that was leading the election at time `t` according to the mentioned rules.

 

**Example 1:**

```
Input
["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
[[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]
Output
[null, 0, 1, 1, 0, 0, 1]

Explanation
TopVotedCandidate topVotedCandidate = new TopVotedCandidate([0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]);
topVotedCandidate.q(3); // return 0, At time 3, the votes are [0], and 0 is leading.
topVotedCandidate.q(12); // return 1, At time 12, the votes are [0,1,1], and 1 is leading.
topVotedCandidate.q(25); // return 1, At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
topVotedCandidate.q(15); // return 0
topVotedCandidate.q(24); // return 0
topVotedCandidate.q(8); // return 1
```

 

**Constraints:**

- `1 <= persons.length <= 5000`

- `times.length == persons.length`

- `0 <= persons[i] < persons.length`

- `0 <= times[i] <= 109`

- `times` is sorted in a strictly increasing order.

- `times[0] <= t <= 109`

- At most `104` calls will be made to `q`.

---

## 💡 Solution Explanation

Optimal iterative solution using a single pass to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
import java.util.Arrays;

class TopVotedCandidate {
    int[] voteCount;
    int[] leaders;
    int[] times;

    public TopVotedCandidate(int[] persons, int[] times) {
        this.times = times;

        int n = persons.length;
        voteCount = new int[n];
        leaders = new int[n];

        int currentLeader = -1;
        int maxVotes = 0;

        for (int i = 0; i < n; i++) {
            int person = persons[i];
            voteCount[person]++;

            if (voteCount[person] >= maxVotes) {
                maxVotes = voteCount[person];
                currentLeader = person;
            }

            leaders[i] = currentLeader;
        }
    }

    public int q(int t) {
        int index = Arrays.binarySearch(times, t);

        if (index < 0) {
            index = -(index + 2);
        }

        return leaders[index];
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
