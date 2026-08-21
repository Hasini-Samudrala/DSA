/*problem link - https://www.geeksforgeeks.org/problems/minimal-cost/1*/

class Solution {
  public:
    int minimizeCost(int k, vector<int>& stones) {
        // code here
        int n = stones.size();
        vector<int>dp(n,0);
        dp[0]=0;
        for(int i =1;i<n;i++){
            int minSteps = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    int jump = dp[i-j]+abs(stones[i]-stones[i-j]);
                    minSteps = min(minSteps,jump);
                }
                dp[i] = minSteps;
            }
        }
        return dp[n-1];
    }
};

/*intution - 
At every stair i, the frog can come from any of the previous k stairs. For each possible previous stair i-j,
 calculate the cost of reaching it plus the cost of the current jump. Take the minimum of all these possibilities 
 as dp[i]. Finally, dp[n-1] gives the minimum total cost to reach the last stair.*/