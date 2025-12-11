/*
Problem link - https://leetcode.com/problems/maximum-subarray/
*/

//Approach - 1
// Brute force liek in O(n^2) time complexity 

//Optimised approach 
//Kadane's Algorithm 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0;
        int max = INT_MIN;
        for(int n:nums)
        {
            sum +=n;
            if(sum>max)
            {
                max = sum;
            }
            if(sum<0)
            {
                sum =0;
            }
        }
        return max;
    }
};


//Intution 
/*
Like see first we initialsed sum to zero and teh max sum to teh lowest 
everytime we add the element to the sum , if the sum is greater then the max_sum we saw so far then we update that 
and if at all teh sum till there is <0 then we would not like to continue that sum further coz it anyways gng to reduce my whole sum 
so when teh sum is <0 then we wont carry further 
but even if the element is <0 but teh overall sum is >0 we wont chnage teh sum coz our main thing is the final 
sum is >0 or not . that is wht we consider 
*/

/*

---

### ✅ **Kadane's Algorithm — Notes for Understanding**

#### 🔍 Problem:

Given an integer array `nums`, find the **maximum sum of a contiguous subarray**.

---

### 💡 Core Idea:

Instead of checking all possible subarrays (which takes O(n²)), we use a **greedy approach** to find the answer in **O(n)** time.

---

### 🧠 Logic Behind the Code:

```cpp
int sum = 0;
int max = INT_MIN;
```

* `sum` keeps track of the **current subarray sum**.
* `max` stores the **maximum subarray sum** found so far.
* Initialized to `INT_MIN` to handle cases where all numbers are negative.

---

### 🔁 Looping through the array:

```cpp
for (int n : nums)
```

* Go through each number in the array.

---

### ➕ Add current number to running sum:

```cpp
sum += n;
```

* Try to include `n` in the current subarray.

---

### 📈 Update maximum if current sum is better:

```cpp
if (sum > max)
    max = sum;
```

* If current subarray sum is better than `max`, update `max`.

---

### 🚫 Reset if current sum becomes negative:

```cpp
if (sum < 0)
    sum = 0;
```

* If `sum` goes below 0, it **won’t help** any future subarray → discard it and start fresh from next number.

---

### 🏁 Return the result:

```cpp
return max;
```

* `max` holds the **maximum subarray sum** found.

---

### 🧪 Example Dry Run: `nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`

| Step | `n` | `sum` after `+=` | Updated `max`? | `sum` after reset? |
| ---- | --- | ---------------- | -------------- | ------------------ |
| 1    | -2  | -2               | Yes (-2)       | 0                  |
| 2    | 1   | 1                | Yes (1)        | -                  |
| 3    | -3  | -2               | No             | 0                  |
| 4    | 4   | 4                | Yes (4)        | -                  |
| 5    | -1  | 3                | No             | -                  |
| 6    | 2   | 5                | Yes (5)        | -                  |
| 7    | 1   | 6                | Yes (6)        | -                  |
| 8    | -5  | 1                | No             | -                  |
| 9    | 4   | 5                | No             | -                  |

✅ Final answer: `6`

---

### 🧠 Key Takeaway:

* This is **Kadane’s Algorithm** — optimal, simple, and fast.
* It works well even when array contains negative numbers.

---


*/

//KADANE's Algorithm 

//code

class Solution{
    public:
    int maxSubArray(vector<int> arr){
        int current = arr[0];
        int best = arr[0];
        for(int i=1;i<arr.size();i++){
            current = max(arr[i],current+arr[i]);
            best = max(best,current);
        }
        return best;
    }
};
