/*
Probelm link - https://www.geeksforgeeks.org/problems/minimize-the-heights-i/1
*/

//approach-1

class Solution{
    int getMinDiff(vector<int>arr,int k){
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans = arr[n-1]-arr[0];
        for(int i=1;i<n;i++){
            int high = max(arr[i-1]+k,arr[n-1]-k);
            int low = min(arr[0]+k,arr[i]-k);
            ans = min(ans,high-low);
        }
        return ans;
    }

};

/*

# 🎯 **THE REAL INTUITION (SUPER SIMPLE)**

We want to **minimize the difference between the tallest and shortest tower**
*after adding or subtracting **exactly k** from every element*.

So each height becomes either:

```
height + k     OR     height - k
```

---

# ⭐ KEY OBSERVATION

After modifications, the **minimum height will always come from either**:

* the **smallest element increased** (`arr[0] + k`)
* OR some middle element **reduced** (`arr[i] - k`)

And the **maximum height will always come from**:

* the **largest element decreased** (`arr[n-1] - k`)
* OR some middle element **increased** (`arr[i-1] + k`)

Why?

---

# ⭐ BRILLIANT TRICK (the one you must understand)

After sorting the array, imagine a “cut point” at index `i`:

* All elements **before** `i` → you increase by `+k`
* All elements **from** `i` to end → you decrease by `-k`

Why does this work?

Because **you don't know which ones should be increased or decreased**,
so you test **every possible division**.

This gives **all possible valid height ranges**.

---

# 🧠 Now how do we compute the new MIN and MAX after the split?

Let’s say the split is at index `i`.

### Elements we ADD k to:

```
arr[0], arr[1], ..., arr[i-1]
```

### Elements we SUBTRACT k from:

```
arr[i], arr[i+1], ..., arr[n-1]
```

---

# 🟢 Highest possible tower (MAX)

It can only be one of:

1️⃣ The last element we increased → `arr[i-1] + k`
2️⃣ The largest element we decreased → `arr[n-1] - k`

We pick **max of these two**:

```
high = max(arr[i-1] + k, arr[n-1] - k)
```

---

# 🔵 Lowest possible tower (MIN)

It can only be one of:

1️⃣ The smallest element we increased → `arr[0] + k`
2️⃣ The first element we decreased → `arr[i] - k`

We pick **min of these two**:

```
low = min(arr[0] + k, arr[i] - k)
```

---

# 🟣 Difference

```
difference = high - low
```

Do this for all `i = 1 to n-1`, pick the minimum.

---

# 🌟 WHY THIS WORKS PERFECTLY

Because for any tower, once you decide:

* "This tower is in the +k group"
* "This tower is in the -k group"

the highest and lowest must be at the **boundary** of these two groups.

Sorting makes sure the boundary is meaningful.

Testing all boundaries ensures you check **every possible valid arrangement**.

---

# 🎉 Now let’s apply intuition to YOUR EXAMPLE

Sorted array:

```
1,2,2,3,4,7,9,9,9,10
```

Try splits:

| Split | MIN source | MAX source | Diff |
| ----- | ---------- | ---------- | ---- |
| i=1   | -2         | 6          | 8    |
| i=5   | 3          | 8          | ⭐ 5  |

The best difference is **5**, at split 5.

Meaning:

Group 1 (increase):

```
1,2,2,3,4  → +4  
→ 5,6,6,7,8
```

Group 2 (decrease):

```
7,9,9,9,10 → -4  
→ 3,5,5,5,6
```

Smallest = **3**
Largest  = **8**
Difference = **5**

---

# ❤️ Final Intuition in One Line

**Try every place where the +k group can end and the -k group can begin; compute the resulting max and min; choose the smallest possible gap.**

---

If you want a **visual diagram**, I can draw one too (it helps a lot).
*/