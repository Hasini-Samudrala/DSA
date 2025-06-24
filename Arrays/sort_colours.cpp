/*
Problem link - https://leetcode.com/problems/sort-colors/description/

*/

//Approach -1
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]>nums[j])
                swap(nums[i],nums[j]);
            }
        }
    }
};

//Intution -
/*
just used two loops to jsut sort it 
would be possible for any kind of arrays to sort 
*/

//Approach -2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low =0;
        int mid =0;
        int high =nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};


//Intution 
/*
we know that there r only three differenty elements in the array namely 0,1,2
so by taking this as advantage we can do something liek similar to how we do binary serach not actually binary serach 
but here we can liek take say if the middle element is zero then it has to be replaced with teh low index till there 
and if teh middle element is 1 we wont change anything and try to move the mid pointer 
and if it is 2 then we try to replca the same with the high index we saw till there 
*/