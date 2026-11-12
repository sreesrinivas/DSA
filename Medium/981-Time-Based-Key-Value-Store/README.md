# [981. Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: Go](https://img.shields.io/badge/Language-Go-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the `TimeMap` class:

- `TimeMap()` Initializes the object of the data structure.

- `void set(String key, String value, int timestamp)` Stores the key `key` with the value `value` at the given time `timestamp`.

- `String get(String key, int timestamp)` Returns a value such that `set` was called previously, with `timestamp_prev <= timestamp`. If there are multiple such values, it returns the value associated with the largest `timestamp_prev`. If there are no values, it returns `""`.

 

**Example 1:**

```
Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"
```

 

**Constraints:**

- `1 <= key.length, value.length <= 100`

- `key` and `value` consist of lowercase English letters and digits.

- `1 <= timestamp <= 107`

- All the timestamps `timestamp` of `set` are strictly increasing.

- At most `2 * 105` calls will be made to `set` and `get`.

---

## 💡 Solution Explanation

Hash-table lookup approach enabling constant-time O(1) element retrieval to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.go)**

```go
var keys, vals [40]string // list of unique keys and values, its index in the list is their id
var stamps [40][63]uint32 // upper 24 bits holds the timestamp, lower 8 bits holds the value id

type TimeMap struct{ k, v int } // number of unique keys and values currently living in the lists

func Constructor() TimeMap { return TimeMap{} }

func (this *TimeMap) Set(key string, val string, stamp int) {
	v := slices.Index(vals[:this.v], val)
	if v == -1 { // new value
		v = this.v
		vals[this.v] = val
		this.v++
	}
	entry := uint32(stamp<<8 | v)
    // stamps list is 1-based, so that stamps[0] is always empty
	k := slices.Index(keys[:this.k], key) + 1
	if k == 0 { // new key
		keys[this.k] = key
		this.k++
		stamps[this.k][0] = 1
		stamps[this.k][1] = entry
		return
	}
	if stamps[k][stamps[k][0]]&255 == uint32(v) { // same value as last entry, reuse older timestamp
		return
	}
	stamps[k][0]++
	stamps[k][stamps[k][0]] = entry
}

func (this *TimeMap) Get(key string, stamp int) string {
	row := &stamps[slices.Index(keys[:this.k], key)+1]
	limit := uint32(stamp<<8 | 255)
	for i := row[0]; i >= 1; i-- {
		if row[i] <= limit {
			return vals[row[i]&255]
		}
	}
	return ""
}
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
