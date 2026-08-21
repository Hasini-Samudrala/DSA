/**problem link - https://leetcode.com/problems/house-robber-ii/ */

class Solution {
public:
     int rob1(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];

        for(int i =1;i<n;i++){
            int take = nums[i];
            if(i>1) take+= dp[i-2];

            int nontake  = dp[i-1];
            dp[i] = max(take,nontake);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        vector<int>temp1,temp2;

        int n = nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
    }
};

/*intuttion - 
Since the houses are in a circle, the first and last houses are adjacent, so we cannot rob both. 
We split the problem into two cases: exclude the first house or exclude the last house. For each case,
 use the normal House Robber DP to find the maximum non-adjacent sum. Finally, take the maximum of these two cases.*/