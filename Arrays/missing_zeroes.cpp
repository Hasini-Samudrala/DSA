/*
Problem Link - https://leetcode.com/problems/missing-number/description/
*/

// Approach -1
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i)
            {
                return i;
            }
        }
        return nums.size();
    }
};

//Intution 
/*
we need the elemnet which is not there in teh array when said that array would consist elements from 0 to n , so basicallly we 
can sort the array and then find that the index of that particular element has to be equal to the element value else 
that element index is teh value we woud be finding 
*/

//Approach -2
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
        }
        int n = nums.size();
        int k = (n*(n+1))/2;
        return k-sum;
    }
};

//Intution 
/*
We know that only one number os missing so basically we can sum all the elements till there and then we could actually find the
sum of elements till n ( size of array)we can do that and from there we can find teh missing number 
*/