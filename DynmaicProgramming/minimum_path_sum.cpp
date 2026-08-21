/*problem link  - https://leetcode.com/problems/minimum-path-sum/*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,0));

        dp[0][0]=  grid[0][0];

        for(int i =1;i<m;i++){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }

        for(int j=1;j<n;j++){
            dp[j][0] = grid[j][0] + dp[j-1][0];
        }

        for(int i = 1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = grid[i][j]+ min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};

/*intuition - 
To reach any cell, the robot can come only from the top or the left. We already know the minimum 
cost to reach both of these cells, so choose the smaller one and add the current cell's value. Thus, 
dp[i][j] stores the minimum cost to reach (i,j). Finally, dp[m-1][n-1] gives the minimum path sum.
*/