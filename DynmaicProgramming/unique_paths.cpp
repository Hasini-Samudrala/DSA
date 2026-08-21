/*problem linmk - https://leetcode.com/problems/unique-paths/*/

class Solution {
public:
    int uniquePaths(int n, int m) {
       vector<vector<int>> dp(n,vector<int>(m,0)) ;

       for(int i =0;i<m;i++){
        dp[0][i]=  1;
       }

       for(int j=0;j<n;j++){
        dp[j][0] = 1;
       }

       for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
       }
       return dp[n-1][m-1];
    }
};

/*intuition - 
At every cell, the robot can arrive only from above or from the left. So the number of ways to reach a 
cell is the sum of the ways to reach those two previous cells. The first row and first column have only one 
possible path, because you can only move in one direction there. Finally, dp[m-1][n-1] gives the total number 
of unique paths.*/