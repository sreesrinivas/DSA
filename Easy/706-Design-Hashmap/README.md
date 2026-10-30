# [706. Design HashMap](https://leetcode.com/problems/design-hashmap/)

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Language: Java](https://img.shields.io/badge/Language-Java-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Design a HashMap without using any built-in hash table libraries.

Implement the `MyHashMap` class:

- `MyHashMap()` initializes the object with an empty map.

- `void put(int key, int value)` inserts a `(key, value)` pair into the HashMap. If the `key` already exists in the map, update the corresponding `value`.

- `int get(int key)` returns the `value` to which the specified `key` is mapped, or `-1` if this map contains no mapping for the `key`.

- `void remove(key)` removes the `key` and its corresponding `value` if the map contains the mapping for the `key`.

 

**Example 1:**

```
Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
```

 

**Constraints:**

- `0 <= key, value <= 106`

- At most `104` calls will be made to `put`, `get`, and `remove`.

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
class MyHashMap{
        final ListNode[] nodes = new ListNode[10_000];

        public void put(int key, int value){
            int i = idx(key);
            if(nodes[i] == null)
                nodes[i] = new ListNode(-1, -1);
            ListNode prev = find(nodes[i], key);
            if(prev.next == null)
                prev.next = new ListNode(key, value);
            else prev.next.val = value;
        }

        public int get(int key){
            int i = idx(key);
            if(nodes[i] == null)
                return -1;
            ListNode node = find(nodes[i], key);
            return node.next == null ? -1 : node.next.val;
        }

        public void remove(int key){
            int i = idx(key);
            if(nodes[i] != null){
                ListNode prev = find(nodes[i], key);
                if(prev.next != null)
                    prev.next = prev.next.next;
            }
        }

        int idx(int key){return Integer.hashCode(key) % nodes.length;}

        ListNode find(ListNode bucket, int key){
            ListNode node = bucket, prev = null;
            for(; node != null && node.key != key; node = node.next)
                prev = node;
            return prev;
        }

        class ListNode{
            int key, val;
            ListNode next;

            ListNode(int key, int val){
                this.key = key;
                this.val = val;
            }
        }
    }
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
