/*problem link - https://leetcode.com/problems/triangle/*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int>dp(n);
        for(int i=0;i<n;i++){
            dp[i] = triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};

/*intuition - 
Start from the bottom row, because from each element you can directly choose between the two elements below it. 
dp[j] represents the minimum path sum from the current position (i,j) to the bottom. For each element, choose the 
cheaper of the two possible paths: dp[j] or dp[j+1], then add the current value. We update from bottom to top, so 
finally dp[0] contains the minimum path sum from the top to the bottom.*/