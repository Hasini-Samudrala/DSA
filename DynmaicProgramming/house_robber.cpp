/*problem link - https://leetcode.com/problems/house-robber/*/

class Solution {
public:
    int rob(vector<int>& nums) {
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
};

/*intution - At every house, we have two choices: rob it or skip it. If we rob house i,
 we cannot rob house i-1, so the total becomes nums[i] + dp[i-2]. If we skip it, we keep
  the previous best, dp[i-1]. Therefore, dp[i] = max(take, nontake), and dp[n-1] gives the 
  maximum money we can rob.*/