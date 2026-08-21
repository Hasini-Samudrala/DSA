/*problem link- https://www.geeksforgeeks.org/problems/geek-jump/1 */

class Solution {
  public:
    int minCost(vector<int>& heights) {
        // Code here
        int n = heights.size();
        vector<int>dp(n,0);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int fs = dp[i-1] + abs(heights[i]-heights[i-1]);
            
            int ss = INT_MAX;
            if(i>1) ss = dp[i-2]+abs(heights[i]-heights[i-2]);
            
            dp[i] = min(fs,ss);
        }
        return dp[n-1];
        
    }
};

/*intution - At every stair i, you have only two choices: come from the previous stair (i-1) or jump from 
two stairs before (i-2). Calculate the minimum cost for both possibilities and choose the smaller one. dp[i] 
represents the minimum cost required to reach stair i. Finally, dp[n-1] gives the minimum cost to reach the last stair.
*/