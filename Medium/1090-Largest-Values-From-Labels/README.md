# [1090. Largest Values From Labels](https://leetcode.com/problems/largest-values-from-labels/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You are given `n` item's value and label as two integer arrays `values` and `labels`. You are also given two integers `numWanted` and `useLimit`.

Your task is to find a subset of items with the **maximum sum** of their values such that:

- The number of items is **at most** `numWanted`.

- The number of items with the same label is **at most** `useLimit`.

Return the maximum sum.

 

**Example 1:**

**Input:** values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1

**Output:** 9

**Explanation:**

The subset chosen is the first, third, and fifth items with the sum of values 5 + 3 + 1.

**Example 2:**

**Input:** values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2

**Output:** 12

**Explanation:**

The subset chosen is the first, second, and third items with the sum of values 5 + 4 + 3.

**Example 3:**

**Input:** values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1

**Output:** 16

**Explanation:**

The subset chosen is the first and fourth items with the sum of values 9 + 7.

 

**Constraints:**

- `n == values.length == labels.length`

- `1 <= n <= 2 * 104`

- `0 <= values[i], labels[i] <= 2 * 104`

- `1 <= numWanted, useLimit <= n`

---

## 💡 Solution Explanation

Exhaustive / multi-pass search across candidate elements to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.java)**

```java
class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int num_wanted, int use_limit) {
        HashMap<Integer, Integer> hash_label = new HashMap<Integer, Integer>();

        // create a hashmap for maintaining the use_limit of each label group
		for (int i : labels) {
			hash_label.put(i, 0);
		}

		int size = values.length;
		int[][] val_lab = new int[size][2];

        // creating a 2D array which has values and labels corresponding to the values
		for (int i = 0; i < size; i++) {
			val_lab[i][0] = values[i];
			val_lab[i][1] = labels[i];
		}

        // sorting the array in descending order based on the values from column 0
		Arrays.sort(val_lab, new Comparator<int[]>() {
			public int compare(final int[] entry1, final int[] entry2) {

				if (entry1[0] < entry2[0])
					return 1;
				else
					return -1;
			}
		});
		int sum = 0;

		for (int i = 0; i < size; i++) {
			int val = val_lab[i][0];
			int lab = val_lab[i][1];
        // if label usage less than use_limit and subset size is less than num_wanted, include array item in the subset
			if (num_wanted > 0 && hash_label.get(lab) < use_limit) {

				sum += val;
				hash_label.put(lab, hash_label.get(lab) + 1);
				num_wanted--;
			}
		}

		return sum;
    }
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
