Bro, this is another classic **Stack** problem.

The trick is to realize that the problem says:

> **Whenever two adjacent characters are equal, remove them.**

The moment you remove them, **new adjacent duplicates can be created**.

That is exactly why a **Stack** is needed.

---

# Problem

Given a string,

repeatedly remove adjacent duplicates until no more exist.

Example

```text
s = "abbaca"
```

Output

```text
"ca"
```

---

# Step 1 : Pattern Recognition

Keywords:

* Adjacent
* Remove
* Repeatedly

Whenever removing something may create a new pair,

🚨 Think **Stack**.

---

# Step 2 : Big Intuition ⭐⭐⭐

Suppose

```text
abbaca
```

Read one character at a time.

Initially

```text
Stack

Empty
```

---

Read

```text
a
```

Stack

```text
a
```

---

Read

```text
b
```

Stack

```text
a b
```

---

Read

```text
b
```

Oops.

Current character

```text
b
```

equals

Stack Top

```text
b
```

Adjacent duplicate.

Remove it.

Instead of pushing,

pop.

Stack

```text
a
```

Notice

We removed both b's.

---

Read

```text
a
```

Now

Top

```text
a
```

Current

```text
a
```

Again duplicate.

Pop.

Stack

```text
Empty
```

---

Read

```text
c
```

Push.

Stack

```text
c
```

---

Read

```text
a
```

Push.

Stack

```text
c a
```

Finished.

Answer

```text
ca
```

---

# Why Stack?

Suppose

```text
azxxzy
```

Initially

```text
a z x x z y
```

Remove

```text
x x
```

Now string becomes

```text
a z z y
```

Oops!

Now

```text
z z
```

became adjacent.

Remove them.

Final

```text
a y
```

A stack naturally handles this because after popping `x`, the previous `z` is now back on top and can be compared with the next `z`.

---

# Algorithm

For every character:

* If the stack is **not empty** and the top equals the current character:

  * Pop the top (this removes both duplicates).
* Otherwise:

  * Push the current character.

At the end, the stack contains the answer.

---

# Dry Run

Input

```text
azxxzy
```

| Character | Stack |
| --------- | ----- |
| a         | a     |
| z         | az    |
| x         | azx   |
| x         | az    |
| z         | a     |
| y         | ay    |

Answer

```text
"ay"
```

---

# C++ Code (Using Stack)

```cpp
class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> st;

        for(char ch : s){

            if(!st.empty() && st.top() == ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }

        string ans = "";

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```

---

# Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

---

# Interview Optimization ⭐⭐⭐

Most interviewers prefer the **string as a stack** solution because it's cleaner and avoids reversing at the end.

## Intuition

A string supports:

* `push_back()` → Push
* `pop_back()` → Pop
* `back()` → Top

So the string itself behaves like a stack.

---

# C++ Code (Preferred)

```cpp
class Solution {
public:
    string removeDuplicates(string s) {

        string ans;

        for(char ch : s){

            if(!ans.empty() && ans.back() == ch){
                ans.pop_back();
            }
            else{
                ans.push_back(ch);
            }
        }

        return ans;
    }
};
```

---

# Dry Run of Optimized Version

Input

```text
abbaca
```

| Character | ans |
| --------- | --- |
| a         | a   |
| b         | ab  |
| b         | a   |
| a         | ""  |
| c         | c   |
| a         | ca  |

Final answer

```text
ca
```

---

# Why does this work?

Think of `ans` as the processed string so far.

When the next character arrives, there are only two possibilities:

1. It matches the last character in `ans` → they become adjacent duplicates, so remove the last character.
2. It doesn't match → it cannot form a duplicate, so append it.

Because we process left to right, every adjacent pair is handled exactly once.

---

# Interview Pattern ⭐⭐⭐

Whenever you hear:

* Remove adjacent duplicates
* Undo previous operation
* Cancel matching pairs
* Eliminate neighbors repeatedly

Think:

> **Stack**

The stack always stores the **current valid result**. Each new character either:

* **extends** the result (`push`), or
* **cancels** the previous character (`pop`).

This same stack pattern appears in:

* ✅ Remove All Adjacent Duplicates in String
* ✅ Remove All Adjacent Duplicates in String II (with counts)
* ✅ Valid Parentheses
* ✅ Asteroid Collision
* ✅ Backspace String Compare
