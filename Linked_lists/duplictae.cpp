/*problem link - https://leetcode.com/problems/find-the-duplicate-number/description/
*/

// appraoch - 1
using hashmap is not corrrect coz uses more space , we are supposed to se 

// approach -2
using a variable sum maynot help when teh array is [3,3,3,3,3]

//approach -3
using XOR also might not help coz when the array is [3,3,3,3] teh xor result would be 0

2 and 3 wont work work coz we dont know how many times a number is repeated in a array 
we know only one number is repeating but we dont know how manyy times that number is repeating 4

//apparoach -4
using binary search , the array is not sorted , i can not sort the array coz i cant modify the array 
thats where thsi appraoch steps in 

//approach - 5

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int slow =0;
       int fast =0;
       while(true){
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(slow==fast){
            break;
        }
       }

       slow = 0;
       while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
       }
       return slow;

    }
};

/*
## First: stop thinking of it as an “array problem”

The **breakthrough intuition** is this:

> You are **not** using slow & fast pointers on an array.
> You are using them on a **hidden linked structure**.

That’s the mental shift.

---

## How the array secretly becomes a linked structure

* Every index is a **node**
* The value at that index tells you **where to go next**

So:

```
i → nums[i]
```

Because:

* `nums[i]` is always in `[1, n]`
* Every “next” pointer is valid
* You never go out of bounds

This creates a **directed graph** where every node has **exactly one outgoing edge**.

---

## Now the unavoidable truth (this is the key)

You have:

* **n + 1 nodes**
* but only **n possible next nodes**

So at least **two nodes point to the same node**.

👉 That **forces a loop (cycle)**.
No escape. No exception.
---

## Why the duplicate = cycle entry (intuition)

The duplicate number means:

* Two different indices say: “go to **the same next index**”

That shared “next index” is where paths **merge**, and after merging,
you are **trapped in a loop forever**.

That loop exists **only because of the duplicate**.

So:

* **Cycle exists → duplicate exists**
* **Cycle entry → duplicate number**

---

## Now: why slow & fast pointers MUST meet

Forget arrays for a moment.
Think of a circular track.

* Slow moves **1 step**
* Fast moves **2 steps**

Question:
Can fast keep running forever without meeting slow?

❌ No.

Why?

* Fast gains **1 step per move**
* In a circle, that extra step **must catch up**

This is pure **relative speed**, nothing fancy.

---

## But why do we reset one pointer to the start?

This is the part that feels “why on earth does this work??”

Here’s the intuition (no math):

* When slow & fast meet, they are **somewhere inside the loop**
* The distance from:

  * **start → loop entry**
  * and **meeting point → loop entry**
    turns out to be the **same**

So if:

* One pointer starts from beginning
* One starts from meeting point
* Both move **one step at a time**

They are **forced** to meet at the **cycle entry**.

And the cycle entry is the **duplicate number**.

---

## Why this works even for `[3,3,3,3,3]`

Let’s check your scary case:

```
nums = [3,3,3,3,3]
```

Structure:

```
0 → 3 → 3 → 3 → 3 ...
```

* Cycle exists ✔️
* Entry is 3 ✔️
* Slow & fast meet ✔️
* Reset logic still holds ✔️

No dependence on:

* how many times it repeats
* distribution
* order

That’s why sum/XOR fail but this survives.

---

## One-line intuition (the “aha” sentence)

> Slow and fast pointers work because the duplicate forces the array to behave like a linked list with a cycle, and cycles cannot hide from relative motion.

---

## Why this solution feels unnatural (important reassurance)

This trick:

* is **not obvious**
* is **not expected instantly**
* is learned once, then reused forever

Almost everyone feels:

> “Why does this even work??”

before it clicks.

You’re **exactly at the right stage**.

---
*/