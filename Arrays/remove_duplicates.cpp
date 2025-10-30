/*
Problem Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
in short - we need to modify teh array in such a way that we dont have any duplicates in the array and also we need 
to return teh number of unique elements in the array */

//Code 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k =1;
        for(int i =1;i<nums.size();i++)
        {
            
            if(nums[i-1]!= nums[i])
            {
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};

//INTUTION AND CORE LOGIC 
/*
firstly while finding an element whoch is unique we are keep tracking of the number of the unique elemnet it is in the array so 
we can just go to that particular index k in the array and change the value of that element in the array 
and now we increment the index by 1 ,that is teh number of unique elements that are found till date 
we dont need to change the nums[0] becoz it will already be the desired element only 
*/


/* just that u need to remove duplictaes , u will take two integers ( i and k ) nd k is represetig the index of teh one which are 
not duplicates where as teh index i is going through teh whoe array 
at last we will be returning teh integer k */