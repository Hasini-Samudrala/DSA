/*
Problem link - https://leetcode.com/problems/binary-search/description/
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
       int low=0;
       int high = nums.size()-1;

       while(low <= high)
       {
        int mid = (low+high)/2;

        if(nums[mid]==target)
        return mid;

        else if(nums[mid]>target)
        high = mid-1;

        else
        low = mid+1;

       }
        return -1;
    }
};

//Intution
/*
basic binary serach which takes logn time to complete and then it is used maximum only when teh array is sorted either in ascedng order or in descdeing order 

if there is no low<=high , if there is no '=' then basically it is gonna fail for teh n = 1 cases 
*/