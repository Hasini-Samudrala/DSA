/*problem link - https://takeuforward.org/data-structure/find-the-two-numbers-appearing-odd-number-of-times
// */

class Solution{
    public:

    vector<int> findTwoNumbers(vector<int>&nums){
        int x=0;

        for(int num:nums) {
            x = x^num;
        }

        int setBit = x&(-x);

        int a =0;
        int b=0;
        for(int num:nums){
            if(num & setBit){
                a = a^num;
            }
            else{
                b = b^num;
            }
        }
        if(a>b) swap(a,b);
        return {a,b};
    }
}

/*
Perfect — let’s do a **full step-by-step dry run** (no skipping anything) 🔥
Example:

```
nums = [1,2,1,3,5,2]
```

---

# 🔹 Step 1: XOR all elements

Start:

```
x = 0
```

Now go one by one:

```
x = 0 ^ 1 = 1
x = 1 ^ 2 = 3
x = 3 ^ 1 = 2
x = 2 ^ 3 = 1
x = 1 ^ 5 = 4
x = 4 ^ 2 = 6
```

👉 Final:

```
x = 6
```

---

## 🔍 What is 6?

```
6 = 110 (binary)
```

👉 This means:

```
x = a ^ b = 3 ^ 5
```

---

# 🔹 Step 2: Find rightmost set bit

```
setBit = x & (-x)
```

We already know:

```
x = 6 = 110
-x → gives → 010 (conceptually)
```

So:

```
setBit = 110 & 010 = 010 = 2
```

👉 This bit will **separate 3 and 5**

---

# 🔹 Step 3: Divide into 2 groups

Condition:

```
if (num & setBit)
```

👉 setBit = 2 → binary `010`

---

## 🔹 Grouping

### Group A (bit present → num & 2 ≠ 0)

```
2 → 010 ✔
3 → 011 ✔
2 → 010 ✔
```

👉 Group A:

```
[2, 3, 2]
```

---

### Group B (bit NOT present)

```
1 → 001 ❌
1 → 001 ❌
5 → 101 ❌
```

👉 Group B:

```
[1, 1, 5]
```

---

# 🔹 Step 4: XOR inside each group

---

## Group A:

```
2 ^ 3 ^ 2
= (2 ^ 2) ^ 3
= 0 ^ 3
= 3
```

---

## Group B:

```
1 ^ 1 ^ 5
= (1 ^ 1) ^ 5
= 0 ^ 5
= 5
```

---

# 🔹 Step 5: Final answer

```
[3, 5]
```

(sort if needed)

---

# 🧠 WHAT JUST HAPPENED (MOST IMPORTANT)

1. XOR all → got `a ^ b`
2. Found a **bit where they differ**
3. Used that bit to:

   * send duplicates to same group (cancel)
   * separate a and b into different groups
4. XOR again → get both numbers

---

# 🔥 FINAL INTUITION

> “Find difference → use that difference to split → cancel duplicates → get uniques”

---

If you want, next I can:
👉 show a **visual bit diagram (like columns)** — makes it even clearer
👉 or give you a similar question to test yourself 😏
*/