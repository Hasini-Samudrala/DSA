/*
Problem Link : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
In short description - Check if the given array is sorted or not after non negative number of rotations 
*/

//Code -Approach 1 
class Solution {
public:
    bool check(vector<int>& nums) {
        int prev;
        int k = nums.size();
        int i =0;
        while((i+1< k) && (nums[i]<=nums[i+1]))
        i++;
        prev = nums[0];
        i = i+1;
        int root = INT_MIN;
        while(i<k)
        {
            if(prev >= nums[i] && root <= nums[i])
            {
                root = nums[i];
                i++;   
            }

            else
            {
                return false;
            }

        }

        return true;
    }
};

//INTUTION AND CORE LOGIC 
/*
examples - [3,4,5,1,2], [5,1,5,1],[2,7,10,6,7,7]
so first check the point where you can observe teh first decrease in the array 
secondly check if all teh elements from here are less than teh vallue of elements seen so far 
to check if all are less than all the elements seen so far you can check taht with teh least element seen so far
and that is the first element of teh array , so prev is teh initial element of teh array .
and teh other condition you need to check is if all the elements that you are seeing from now are in increasing order or not
for this we can keep track of the variable root and check if teh next sequence is in increasing order or not 
*/

//Code - Approach -2

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }
        if(nums[n-1]>nums[0]){
            cnt++;
        }
        return cnt<=1;
    }
};

//INTUTION AND CORE LOGIC 
/*
here we are checking how many times can we encounter a pair in which teh first number is greater than teh second number 
if this appears more than once then it is not teh answer that we want 
in other words this condition says whether the sequence later is in increasing order or not
and is the last element is less than teh first element of teh array then our work is done and this is teh array 
we want and we can return true from here , final condition to check is if teh count value is less tahn or equal to 1 our job is done 
*/