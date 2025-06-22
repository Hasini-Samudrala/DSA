/*
Problem link - https://leetcode.com/problems/move-zeroes/
in short - we are asked to move all the zeroes to the right without changing the order of non zero elements 
 */

 class Solution 
 {
    public:
    void moveZeroes(vector<int>& nums) {
        int left =0;
        for(int right =0;right<nums.size();right++)
        {
            if(nums[right]!=0)
            {
                swap(nums[right],nums[left]);
                left++;
            }
        }
 }
};

// INTUTION 
/*
So we would like to move all the zeroes so we would check every element and if it is not zero then we would like to swap 
that element with another left element till there from ther ewould liek to continue 
*/