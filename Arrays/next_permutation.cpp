/*
problem link - https://leetcode.com/problems/next-permutation/description/
*/class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i >= 0) {
            int j = n - 1;

            while (nums[j] <= nums[i])
                j--;

            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

/*
intution - 
go from the right, find the first digit that can be increased, 
increase it by swapping with the smallest larger digit on its right, 
then make everything after it as small as possible (reverse)
*/