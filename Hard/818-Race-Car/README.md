# [818. Race Car](https://leetcode.com/problems/race-car/)

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Language: JavaScript](https://img.shields.io/badge/Language-JavaScript-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

Your car starts at position `0` and speed `+1` on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions `'A'` (accelerate) and `'R'` (reverse):

- When you get an instruction `'A'`, your car does the following:

	
`position += speed`
`speed *= 2`

- When you get an instruction `'R'`, your car does the following:
	
If your speed is positive then `speed = -1`
otherwise `speed = 1`

	Your position stays the same.

For example, after commands `"AAR"`, your car goes to positions `0 --> 1 --> 3 --> 3`, and your speed goes to `1 --> 2 --> 4 --> -1`.

Given a target position `target`, return *the length of the shortest sequence of instructions to get there*.

 

**Example 1:**

```
Input: target = 3
Output: 2
Explanation: 
The shortest instruction sequence is "AA".
Your position goes from 0 --> 1 --> 3.
```

**Example 2:**

```
Input: target = 6
Output: 5
Explanation: 
The shortest instruction sequence is "AAARA".
Your position goes from 0 --> 1 --> 3 --> 7 --> 7 --> 6.
```

 

**Constraints:**

- `1 <= target <= 104`

---

## 💡 Solution Explanation

Dynamic programming / memoized recursion approach storing overlapping subproblems to satisfy all problem constraints with optimal runtime performance.

### ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## 💻 Source Code

👉 **[View Solution File](./solution.js)**

```javascript
var racecar = function(target) {
	let dp=Array.from({length:10001}, x=>-1);
	return (function helper(t){
		if(dp[t]>0) return dp[t];
		let n=Math.ceil(Math.log(t+1)/Math.LN2); 
		// because t<=2^n-1, here n is the number of 'A' we used (no 'R‘’)
		if((1<<n)-1===t) dp[t]=n;
		else{
			dp[t]=helper((1<<n)-1-t)+n+1;
			// +n 'A' + 1 'R' === +n+1;
			// to reach the target, we may go as far as possible to just reach or pass the target
			// and then we take some steps back
			for(let r=0; r<n-1; r++){
				dp[t]=Math.min(dp[t], helper(t-(1<<(n-1))+(1<<r))+n+r+1);
				// (n-1) is the number of 'A' before the first 'R';
				// r is the number of 'A' after the first 'R' and before the second 'R';
				// and helper(...) return the number of steps after the second R;
				// +(n-1) 'A' + 1 'R' + r 'A' + 1 'R' === +n+r+1 (the number of steps before the second 'R'(including it))
				// for instance, to reach 5, we need to take 7 steps: AARARAA
				// to reach the target, we go as far as possible before passing the target (if we just reached it, we can stop)
				// and then we take some steps back (r steps back)
				// and then we continue going forward (by taking a 'R') and so on...
			}
		}
		return dp[t];
	})(target);
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
