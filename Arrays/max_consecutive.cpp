/*
Problem link - https://leetcode.com/problems/max-consecutive-ones/
*/

//Approach 
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=1)
            {
                if(c>max)
                max =c;
                c=0;
            }
            else
            c++;
        }
        if(c>max) max =c;
        return max;
    }
};

// Intution 
/*
Here we need to find teh maximum num of consecutive ones so we took a varibale and everytime we see 
a number other than one then we have to check the max and teh count of number of 2's till there and 
then try to change the max and return the max aat the end
*/