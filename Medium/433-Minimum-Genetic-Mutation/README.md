# [433. Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

A gene string can be represented by an 8-character long string, with choices from `'A'`, `'C'`, `'G'`, and `'T'`.

Suppose we need to investigate a mutation from a gene string `startGene` to a gene string `endGene` where one mutation is defined as one single character changed in the gene string.

- For example, `"AACCGGTT" --> "AACCGGTA"` is one mutation.

There is also a gene bank `bank` that records all the valid gene mutations. A gene must be in `bank` to make it a valid gene string.

Given the two gene strings `startGene` and `endGene` and the gene bank `bank`, return *the minimum number of mutations needed to mutate from *`startGene`* to *`endGene`. If there is no such a mutation, return `-1`.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

**Example 1:**

```
Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
```

**Example 2:**

```
Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
```

 

**Constraints:**

- `0 <= bank.length <= 10`

- `startGene.length == endGene.length == bank[i].length == 8`

- `startGene`, `endGene`, and `bank[i]` consist of only the characters `['A', 'C', 'G', 'T']`.

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
int minMutation(string start, string end, vector<string>& bank) {
	//st holds all valid mutations
	unordered_set<string> st{bank.begin(),bank.end()};
	//if end mutaion is not in list return -1;
	if(!st.count(end)) return -1;
	//start BFS by pushing the starting mutation
	queue<string> Q;
	Q.push(start);
	int steps=0,s;
	string cur,t;
	while(!Q.empty()){
		s=Q.size();
		while(s--){
			cur=Q.front();
			Q.pop();
			//If we reach end mutation
			if(cur==end) return steps;
			//We erase the cur mutation in order to avoid redundant checking
			st.erase(cur);
			//as the length of mutation is 8 and it can take A,C,G,T
			//at each index we check the possibility of mutation by replcaing it with A,C,G,T
			for(int i=0;i<8;i++){
				t=cur;
				t[i]='A';
				if(st.count(t)) Q.push(t);
				t[i]='C';
				if(st.count(t)) Q.push(t);
				t[i]='G';
				if(st.count(t)) Q.push(t);
				t[i]='T';
				if(st.count(t)) Q.push(t);
			}
		}
		steps++;
	}
	return -1;
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
