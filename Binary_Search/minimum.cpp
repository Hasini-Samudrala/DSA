/*
probelm link -https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
*/

//Apprach 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int r = nums.size()-1;
        int m;
        while(l<r)
        {
            m=(l+r)/2;
            if(nums[m]<=nums[r])
            r=m;

            else
            l=m+1;
        }
        return nums[l];
    }
};

//Intution 
/*
🔍 Problem:
Find the minimum element in a rotated sorted array (no duplicates).

🧠 Key Idea:
The smallest element is the pivot point (where rotation happens).
Use binary search to narrow down where this pivot is.

✨ Step-by-step Intuition:
Start with:
l = 0, r = n - 1.

Binary search loop while l < r:

Calculate mid: m = (l + r) / 2.

Now compare nums[m] and nums[r]:

If nums[m] <= nums[r]:
👉 The right part is sorted, so the min could be m or to its left.
🔁 So, move r = m.

Else (i.e., nums[m] > nums[r]):
👉 Pivot lies to the right of m, so the min must be after m.
🔁 So, move l = m + 1.

When loop ends (l == r), we've found the minimum at nums[l].

💡 One-liner Trick:
“Compare nums[mid] with nums[right]. If mid is bigger, min is right side; if smaller or equal, min is at mid or left side.”

✅ Why it works:
Even though the array is rotated, binary search still works if you look at sorted halves carefully.
*/