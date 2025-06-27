/*
Probelm link -https://leetcode.com/problems/search-insert-position/description/
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r = nums.size()-1;
        int m;
        while(l<=r)
        {
            m=(l+r)/2;
            if(nums[m]==target)
            {
                return m;
            }

            else if(nums[m]>target)
            r=m-1;

            else
            l=m+1;
        }
        return l;
    }
};

//Intution 
/*
So we need to find a perfect place where we can insert the target so 
do binary search to find teh position as the given array is in sorted order 
*/