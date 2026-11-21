# [1116. Print Zero Even Odd](https://leetcode.com/problems/print-zero-even-odd/)

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Language: C++](https://img.shields.io/badge/Language-C++-blue?style=for-the-badge)
[![LeetCode Profile](https://img.shields.io/badge/LeetCode-Profile-FFA116?style=for-the-badge&logo=leetcode&logoColor=white)](https://leetcode.com/sreesrinivas/)

---

## 📝 Problem Statement

You have a function `printNumber` that can be called with an integer parameter and prints it to the console.

- For example, calling `printNumber(7)` prints `7` to the console.

You are given an instance of the class `ZeroEvenOdd` that has three functions: `zero`, `even`, and `odd`. The same instance of `ZeroEvenOdd` will be passed to three different threads:

- **Thread A:** calls `zero()` that should only output `0`'s.

- **Thread B:** calls `even()` that should only output even numbers.

- **Thread C:** calls `odd()` that should only output odd numbers.

Modify the given class to output the series `"010203040506..."` where the length of the series must be `2n`.

Implement the `ZeroEvenOdd` class:

- `ZeroEvenOdd(int n)` Initializes the object with the number `n` that represents the numbers that should be printed.

- `void zero(printNumber)` Calls `printNumber` to output one zero.

- `void even(printNumber)` Calls `printNumber` to output one even number.

- `void odd(printNumber)` Calls `printNumber` to output one odd number.

 

**Example 1:**

```
Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.
```

**Example 2:**

```
Input: n = 5
Output: "0102030405"
```

 

**Constraints:**

- `1 <= n <= 1000`

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
class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn;
    int i;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->turn=0;
        this->i=1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex>lock(m);
        while(i<=n){
          while(i<=n && turn!=0) cv.wait(lock);
          if(i<=n)printNumber(0);
          turn=(i%2==0)?1:2;
          cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex>lock(m);
        while(i<=n){
            while(i<=n && turn!=1) cv.wait(lock);
            if(i<=n)printNumber(i);
            turn=0;
            i++;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex>lock(m);
        while(i<=n){
            while(i<=n && turn!=2) cv.wait(lock);
            if(i<=n)printNumber(i);
            turn=0;
            i++;
            cv.notify_all();
        }
    }
};
```

---
*Automatically solved and synced to GitHub by [sreesrinivas](https://leetcode.com/sreesrinivas/) using [LeetCode Automation](https://github.com/sreesrinivas/DSA).*
