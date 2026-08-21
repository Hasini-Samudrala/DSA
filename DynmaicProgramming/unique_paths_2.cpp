/*problem link - https://leetcode.com/problems/unique-paths-ii/ */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        if(obstacleGrid[0][0]==1)
        return 0;

        dp[0][0] = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;

                if(obstacleGrid[i][j]==1)
                dp[i][j]=0;

                else{
                    if(i>0)
                    dp[i][j] += dp[i-1][j];

                    if(j>0) 
                    dp[i][j] += dp[i][j-1];
                }

            }
        }

        return dp[n-1][m-1];
    }
};

/*intuition - 
At every non-obstacle cell, the robot can only come from above or from the left, so add the number of paths 
from those two cells. If the current cell is an obstacle (1), no path can pass through it, so dp[i][j] = 0. 
The starting cell has one path if it isn't blocked. Finally, dp[m-1][n-1] gives the total number of valid paths.*/