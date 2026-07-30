/* problem link - https://leetcode.com/problems/binary-subarrays-with-sum/description/ */

class Solution {
public:
    int atMost(vector<int> nums,int k ) {
        if(k<0)
        return 0;

        int l = 0;
        int sum =0 ;
        int count = 0 ; 
        for(int r= 0 ; r< nums.size();r++){
            sum += nums[r];
            while(sum>k){
                sum -= nums[l];
                l++;
            }
            count +=(r-l+1);
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // int l = 0 ;
        // int r = 0 ;
        // int n = nums.size();
        // int sum = 0 ;
        // int count = 0;
        // while(l<r){
        //     if(r!= (n-1) ) sum += nums[r];
        //     if(sum< goal && r!=(n-1))
        //     r++;

        //     else if( sum == goal){
        //         count++;
        //         if(r!=(n-1))r++;
        //     }    

        //     else{
        //         l++;
        //         sum -= nums[l];
        //     }
        // }
        // return count;
        int n = nums.size();
        return atMost(nums,goal) - atMost(nums,goal-1);
    }
};