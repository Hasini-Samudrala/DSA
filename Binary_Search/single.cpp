/*
Problem Link - https://leetcode.com/problems/single-element-in-a-sorted-array/
*/

//Appraoch-1
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1,m;
        while(l<=r)
        {
            m = (l+r)/2;
            if(m==0) break;
            if(m>0)
            {
            if(m%2==1)
            {
                if(nums[m]==nums[m-1])
                l=m+1;

                else if(nums[m]==nums[m+1])
                r=m-1;

                else break;
            }

            else if(m%2==0)
            {
                if(nums[m]==nums[m-1])
                r=m-1;

                else if(nums[m]==nums[m+1])
                l=m+2;

                else break;
            }
            }
            
        }
        return nums[m];
        
    }

    
};


//Intution 
/*
🔍 Problem:
In a sorted array, every element appears exactly twice, except one single element.
Find that element in O(log n) time.

🧠 Key Idea:
Since the array is sorted and all pairs are together, we can use binary search with index patterns to find the single element.

✨ Step-by-step Intuition:
Start with:

l = 0, r = n - 1.

Binary search loop while l <= r:

Find middle: m = (l + r) / 2.

What to look for:

Each pair starts at an even index and ends at the next (odd index), before the single element.

After the single element, this pattern breaks: pairs start at odd indices.

So:

If m is even:

If nums[m] == nums[m + 1] 👉 single is on the right, so l = m + 2.

If nums[m] != nums[m + 1] 👉 single is on the left or at m, so r = m.

If m is odd:

If nums[m] == nums[m - 1] 👉 single is on the right, so l = m + 1.

If nums[m] != nums[m - 1] 👉 single is on the left, so r = m - 1.

Break condition: If nums[m] is not equal to either neighbor, it’s the unique one.

At the end, return nums[m] (or even nums[l]).

💡 One-liner Trick:
“Use index pairing logic: before the single element, pairs start at even indices; after it, they start at odd ones.”
*/

//Appraoch -2
class Solution{
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int l=0;
        int r = nums.size()-1;
        int m;
        while(l<r)
        {
            m = (l+r)/2;
            if(m%2==1)
            m--;

            if(nums[m]!=nums[m+1])
            r=m;

            else 
            l=m+2;
        }

        return nums[l];
    }
};

//Intution 
/*
🔍 Problem:
In a sorted array, every element appears exactly twice, except for one single element. Find that one in O(log n) time.

🧠 Key Idea:
Use binary search and leverage the fact that:

Before the single element → all pairs are correctly aligned (even index matched with next odd).

After the single element → the pattern breaks.

✨ Step-by-step Intuition:
Start with l = 0, r = n - 1.

In each iteration:

Compute m = (l + r)/2.

If m is odd, decrement it to make it even, so you’re always checking the first element of a pair.

Now check:

If nums[m] == nums[m + 1]:
👉 The pair is valid.
🔁 So the single element must be after this pair → l = m + 2.

If nums[m] != nums[m + 1]:
👉 The pair is broken.
🔁 So the single element is at m or before → r = m.

Loop ends when l == r → that's the position of the single element.

💡 One-liner Trick:
“Align to even index, check its pair. If pair is fine → go right. If broken → go left.”
*/