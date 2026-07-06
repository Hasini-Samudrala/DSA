/*Bro, this is one of the most common **Hashing** interview questions.

The trick is to realize that **anagrams have something in common that can be used as a key.**

Once you see that, the solution is just a hash map.

---

# Problem

Given an array of strings,

```text
["eat","tea","tan","ate","nat","bat"]
```

Group all anagrams together.

Output

```text
[
    ["eat","tea","ate"],
    ["tan","nat"],
    ["bat"]
]
```

The order of groups doesn't matter.

---

# Step 1 : Pattern Recognition

The question says

> Group similar strings.

Whenever you hear

* Group
* Frequency
* Same property

🚨 Think **Hash Map**.

Now the question becomes:

> **What should be the key?**

---

# Step 2 : What is an Anagram?

Two strings are anagrams if

```text
eat

tea
```

contain exactly the same letters.

Not necessarily in the same order.

So

```text
eat

tea

ate
```

all belong together.

---

# Step 3 : How can we identify anagrams?

Suppose

```text
eat
```

If we sort it

```text
aet
```

Now

```text
tea
```

Sort

```text
aet
```

Again

```text
ate
```

Sort

```text
aet
```

Amazing!

Every anagram has exactly the same sorted string.

---

# BIG INTUITION ⭐⭐⭐

Instead of asking

> Are these two strings anagrams?

Ask

> If I transform every string into its sorted version, do they become identical?

Yes.

That sorted string becomes the key.

---

# Example

Input

```text
eat

tea

tan

ate

nat

bat
```

Transform

```text
eat -> aet

tea -> aet

tan -> ant

ate -> aet

nat -> ant

bat -> abt
```

Now group by key.

```
Key          Strings
----------------------------
aet    ->    eat tea ate

ant    ->    tan nat

abt    ->    bat
```

Done.

---

# Step 4 : Data Structure

Use

```cpp
unordered_map<string, vector<string>>
```

Key

```text
Sorted string
```

Value

```text
All anagrams
```

---

# Dry Run

Input

```text
["eat","tea","tan","ate","nat","bat"]
```

Initially

```text
Map

Empty
```

---

Read

```text
eat
```

Sorted

```text
aet
```

Map

```
aet

↓

eat
```

---

Read

```text
tea
```

Sorted

```text
aet
```

Map

```
aet

↓

eat

tea
```

---

Read

```text
tan
```

Sorted

```text
ant
```

Map

```
aet

↓

eat

tea

-----------------

ant

↓

tan
```

---

Read

```text
ate
```

Sorted

```text
aet
```

Map

```
aet

↓

eat

tea

ate
```

---

Read

```text
nat
```

Sorted

```text
ant
```

Map

```
ant

↓

tan

nat
```

---

Read

```text
bat
```

Sorted

```text
abt
```

Map

```
abt

↓

bat
```

Finished.

Return all values.

---

# Algorithm

```text
Create hash map

For every string

    Make a copy

    Sort it

    Use sorted string as key

    Push original string into map[key]

Return all map values
```

---

*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string str : strs) {

            string key = str;

            sort(key.begin(), key.end());

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

/*
```
# Complexity

Suppose

* `n` = number of strings
* `k` = maximum length of a string

Sorting each string takes

```text
O(k log k)
```

Total

```text
Time = O(n × k log k)

Space = O(n × k)
```

---

# Can we do better? ⭐⭐⭐

Yes.

Sorting costs

```text
O(k log k)
```

Instead,

build a **frequency count**.

Example

```
eat

a = 1
e = 1
t = 1
```

Represent it as

```text
1#0#0#0#1#0#0...1...
```

(26 counts for lowercase English letters).

Now

```
tea

↓

same frequency vector
```

No sorting needed.

---

## Frequency Key Code

```cpp
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string str : strs) {

            vector<int> freq(26, 0);

            for(char c : str)
                freq[c - 'a']++;

            string key = "";

            for(int x : freq)
                key += "#" + to_string(x);

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto &it : mp)
            ans.push_back(it.second);

        return ans;
    }
};

/*```

---

## Complexity of Frequency Method

Building the frequency array takes

```text
O(k)
```

instead of

```text
O(k log k)
```

So the total complexity becomes:

| Method          | Time               | Space    |
| --------------- | ------------------ | -------- |
| Sorting         | **O(n × k log k)** | O(n × k) |
| Frequency Count | **O(n × k)**       | O(n × k) |

---

# Which solution should you write in an interview?

✅ **Sorting solution** is the standard and is accepted almost everywhere. It's shorter, easier to explain, and sufficient unless the interviewer specifically asks for optimization.

If the interviewer asks:

> "Can you optimize it further?"

then propose the **frequency-count key** and explain that it removes the sorting cost.

---

# Interview Pattern ⭐⭐⭐

Whenever you see:

* Group similar strings
* Detect anagrams
* Same character frequencies

Think:

> **Transform each string into a canonical representation (sorted string or frequency signature), then use a hash map to group them.**

This "canonical key + hash map" pattern appears in many string and hashing interview problems.
*/