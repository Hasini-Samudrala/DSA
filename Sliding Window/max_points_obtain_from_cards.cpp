/* problem link - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/ */

class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum= 0 ;
        int rsum = 0 ;
        int maxS = 0 ;
        for(int i = 0;i<=k-1;i++){
            lsum += nums[i];
        }
        maxS = lsum;
        int n = nums.size();
        int rindex = n-1;

        for(int i = k-1;i>=0;i--){
            lsum -= nums[i];
            rsum += nums[rindex];
            rindex--;

            maxS = max(maxS, lsum+rsum);
        }
        return maxS;

    }
};