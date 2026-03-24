/*
problem link - https://leetcode.com/problems/single-number/description/
// find the number that is not repeated twice in the given array 
*/

class Solution{
    public:
    int singleNumber(vector<int>&nums){
        int n = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            n = n^nums[i];
        }
        return n;
    }
}

/*
whne u do XOR on same numbers it results in 0 and when 0 xOR's with any number x , the reult is x , hence we get the number which
is repeated only once */