/*
Probelm link -https://leetcode.com/problems/search-insert-position/description/
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r = nums.size()-1;
        int m;
        while(l<r)
        {
            m=(l+r)/2;
            if(nums[m]==target)
            {
                return m;
            }

            else if(nums[m]>target)
            r=m;

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

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=target){
                ans = mid;
                high = mid-1;
            }
            else
            low = mid+1;
        }
        return ans;
    }
};

/*basically we are searching the lower bound of that element in that array , so if the element exists it return that index
if not it returns the element which is just greater than this .. which is esentially where the insertion should take place */