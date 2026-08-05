/*
probelm link -https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
*/
//actual algo at the bottom

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


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[low]<=nums[mid]){
                ans = min(ans,nums[low]);
                low  = mid+1;
            }
            else{
                high =  mid-1;
                ans = min(ans,nums[mid]);
            }
        }
        return ans;
    }
};

// it is like since the array is sorted but not in correct way 
// we should try to find the point at which it is rotated 
// so  evertime you do that u maintain a min of the part which u r gonna skip next iteration 