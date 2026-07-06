Bro, this is a **Hashing + Sorting (or Bucket Sort)** problem.

The biggest trick is to identify **what exactly needs to be sorted**.

Let's derive it from scratch.

---

# Problem

Given a string,

sort the characters in **decreasing order of frequency**.

Example

```text id="on9r26"
s = "tree"
```

Output

```text id="rbqggo"
"eert"
```

or

```text id="ee0nr8"
"eetr"
```

Both are correct because

```text id="am3jlk"
e -> 2

r -> 1

t -> 1
```

---

# Step 1 : Pattern Recognition

The question says

> Sort according to frequency.

Immediately ask

> **How do I know each character's frequency?**

Answer

```text id="s6d9hu"
Hash Map
```

---

# Step 2 : The Big Intuition ⭐⭐⭐

Suppose

```text id="8mchf4"
tree
```

Instead of thinking about characters,

think about

```text id="p20wkc"
Character

↓

Frequency
```

Build

```text id="1sg7be"
t -> 1

r -> 1

e -> 2
```

Now ask

> What should be sorted?

Not the string.

The

```text id="f6umyi"
(character, frequency)
```

pairs.

---

# Step 3 : How do we sort?

Suppose map is

```text id="kxsh2w"
e -> 2

t -> 1

r -> 1
```

Convert it into

```text id="r2lt6k"
[
(e,2)

(t,1)

(r,1)
]
```

Now sort by

```text id="dgbb2n"
frequency
```

descending.

After sorting

```text id="lkgdqb"
(e,2)

(t,1)

(r,1)
```

Now reconstruct.

```text id="aymcmg"
ee

t

r
```

Output

```text id="34jgwv"
eetr
```

Done.

---

# Dry Run

Example

```text id="v3zdn2"
cccaaa
```

Frequency

```text id="0k0v59"
c -> 3

a -> 3
```

Vector

```text id="r1n7wg"
(c,3)

(a,3)
```

Sort

Same frequency.

Either order works.

Output

```text id="1sv40q"
cccaaa
```

or

```text id="xdr33c"
aaaccc
```

Both accepted.

---

# Algorithm

```text id="0jtw0j"
Count frequencies.

Convert map into vector.

Sort by frequency.

Append every character frequency times.
```

---

# C++ Code (Sorting)

```cpp
class Solution {
public:

    static bool cmp(pair<char,int> &a, pair<char,int> &b){
        return a.second > b.second;
    }

    string frequencySort(string s) {

        unordered_map<char,int> freq;

        for(char c : s)
            freq[c]++;

        vector<pair<char,int>> vec;

        for(auto &it : freq)
            vec.push_back(it);

        sort(vec.begin(), vec.end(), cmp);

        string ans = "";

        for(auto &it : vec){

            ans.append(it.second, it.first);
        }

        return ans;
    }
};
```

---

# Dry Run of the Code

Input

```text id="l8glnb"
tree
```

Map

```text id="i4v3qc"
t ->1

r ->1

e ->2
```

Vector

```text id="vjlwmk"
(t,1)

(r,1)

(e,2)
```

After sorting

```text id="0k5l7e"
(e,2)

(t,1)

(r,1)
```

Now

```cpp
ans.append(2,'e');
```

Answer

```text id="zj8mj0"
ee
```

Then

```cpp
ans.append(1,'t');
```

Answer

```text id="8gchjl"
eet
```

Then

```cpp
ans.append(1,'r');
```

Answer

```text id="mg5bzt"
eetr
```

---

# Complexity

Suppose

```text id="fcf3n3"
n = string length

k = distinct characters
```

Building map

```text id="crtn2h"
O(n)
```

Sorting

```text id="j6pypn"
O(k log k)
```

Building answer

```text id="pv77ol"
O(n)
```

Total

```text id="k7fy1q"
O(n + k log k)
```

Since

```text id="k9utg6"
k ≤ 256
```

for ASCII,

this is practically

```text id="ymusna"
O(n)
```

---

# Can we do Better? ⭐⭐⭐

Yes.

Notice

Maximum frequency

can never exceed

```text id="d49smo"
n
```

Instead of sorting,

make

```text id="jlwmbo"
Bucket[i]
```

store all characters occurring

```text id="p1a0hb"
i
```

times.

Example

```text id="lq9mde"
tree
```

Frequency

```text id="5l0frd"
e ->2

r ->1

t ->1
```

Buckets

```text id="4cf3hj"
Bucket[2]

↓

e

----------------

Bucket[1]

↓

r

t
```

Now traverse

```text id="rtutni"
from n down to 1
```

Output

```text id="uk0wdu"
e

e

r

t
```

No sorting needed.

Time

```text id="5r49kv"
O(n)
```

---

# Bucket Sort Code (Optimal)

```cpp
class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> freq;

        for(char c : s)
            freq[c]++;

        vector<vector<char>> bucket(s.size()+1);

        for(auto &it : freq){
            bucket[it.second].push_back(it.first);
        }

        string ans;

        for(int f = s.size(); f >= 1; f--){

            for(char c : bucket[f]){

                ans.append(f, c);
            }
        }

        return ans;
    }
};
```

---

# Which one should you write in an interview?

### Sorting Solution

✅ Easier

✅ More readable

✅ Accepted everywhere

---

### Bucket Sort

Mention only if interviewer asks

> "Can you optimize the sorting?"

Then explain:

> Since frequency ranges only from `1` to `n`, we can bucket characters by frequency and avoid sorting altogether, reducing the complexity to **O(n)**.

---

# Interview Pattern ⭐⭐⭐

Whenever you see:

* Sort by frequency
* Most frequent element
* Top K frequent
* Group by count

Think in this order:

1. **Count frequencies** using a hash map.
2. Ask: **Do I really need to sort?**
3. If yes → sort the `(element, frequency)` pairs.
4. If the frequency range is bounded (like `1` to `n`) → consider **Bucket Sort** instead.

This "count first, then sort/bucket" pattern appears in many interview questions like **Top K Frequent Elements**, **Top K Frequent Words**, and **Sort Characters By Frequency**.
