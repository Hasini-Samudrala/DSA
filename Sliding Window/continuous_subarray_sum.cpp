/*problem link - https://leetcode.com/problems/continuous-subarray-sum/ */

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=-1;
        int sum = 0 ;
        for(int i =  0;i<nums.size();i++){
            sum += nums[i];
            int rem  = sum%k;

            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2)
                return true;
            }
            else
            mp[rem]=i;
        }
        return false;
    }
};

/*Maintain a running prefix sum and compute its remainder when divided by k. If the 
same remainder is seen again, then the sum of the elements between the two occurrences 
is divisible by k. Store the first index where each remainder appears in a HashMap. 
If the same remainder appears again and the subarray length is at least 2, return true.

If

prefixSum1 % k == prefixSum2 % k

then

(prefixSum2 - prefixSum1) % k == 0

which means

The subarray between them has a sum that is a multiple of k.

This is the entire trick.

*/