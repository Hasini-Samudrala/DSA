/*
Problem link -https://leetcode.com/problems/find-peak-element/description/
*/

//Approach 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
        return 0;
        
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
            return i;
        }

        if(nums[nums.size()-1]>nums[nums.size()-2])
        return nums.size()-1;

        return 0;
    }
};

/*intution 
noraml O(n) procedure
*/

//Apprach -2
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;        
    }
};

