# [677. Map Sum Pairs](https://leetcode.com/problems/map-sum-pairs/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Design a map that allows you to do the following:

- Maps a string key to a given value.

- Returns the sum of the values that have a key with a prefix equal to a given string.

Implement the `MapSum` class:

- `MapSum()` Initializes the `MapSum` object.

- `void insert(String key, int val)` Inserts the `key-val` pair into the map. If the `key` already existed, the original `key-value` pair will be overridden to the new one.

- `int sum(string prefix)` Returns the sum of all the pairs' value whose `key` starts with the `prefix`.

 

**Example 1:**

```
Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
```

 

**Constraints:**

- `1 <= key.length, prefix.length <= 50`

- `key` and `prefix` consist of only lowercase English letters.

- `1 <= val <= 1000`

- At most `50` calls will be made to `insert` and `sum`.

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
class MapSum {
public:
    class Trie{
        public:
        int end;
        Trie* child[26];
        Trie(){
            for(int i=0;i<26;i++)child[i]=NULL;
            end=0;
        }
    };
    unordered_map<string,int>m;
    Trie* root;
    
    MapSum() {
        root=new Trie();
    }
    
    void insert(string key, int val) {
        int prev=m[key];
        m[key]=val;
        val-=prev;
        Trie* t=root;
        for(auto &x:key){
            if(t->child[x-'a']==NULL)t->child[x-'a']=new Trie();
            t=t->child[x-'a'];
            t->end+=val;
        }
    }
    
    int sum(string prefix) {
        Trie* t=root;
        for(auto &x:prefix){
            if(t->child[x-'a']==NULL)return 0;
            t=t->child[x-'a'];
        }
        return t->end;
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
