/*
Problem link - https://leetcode.com/problems/single-number/description/

find teh number which is not repeated liek every number is repeater twice except one so find that number 
*/

//Approach-1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> hash__map;
        for(int i=0;i<nums.size();i++)
        {
            hash__map[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(hash__map[nums[i]]==1)
            return nums[i];
        }
        return 0;
    }
};

//Intution
/*
i have created a hash map nd updated it according to teh numbers in teh array and then again linear search on teh 
hash map to find which is mapping to the number 1 
*/

//Approach -2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int n;
       n = nums[0];
       for(int i=1;i<nums.size();i++) 
       {
        n = n^nums[i];
       }
       return n;
    }
};

//Intution 
/*
XOR is used to remove the duplicates from the data 
say we have 4,1,2,1,2 then when we did XOR then basically we would get 4^1^2^2^1 = 4 
so this is used to remove the duplicates from teh data 
more optimised than teh previos approach 
*/