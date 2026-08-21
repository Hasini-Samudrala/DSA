/*problem link - https://www.geeksforgeeks.org/problems/geeks-training/1*/

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>>dp(n,vector<int>(3,0));
        
        dp[0][0] = mat[0][0];
        dp[0][1] = mat[0][1];
        dp[0][2] = mat[0][2];
        
        for(int i =1;i<n;i++){
            dp[i][0] = mat[i][0] + max(dp[i-1][1],dp[i-1][2]);
            
            dp[i][1] = mat[i][1] + max(dp[i-1][0],dp[i-1][2]);
            
            dp[i][2] = mat[i][2] + max(dp[i-1][0],dp[i-1][1]);
        }
        
        return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
        
    }
};

/*Intuition: For each day, Geek has 3 choices: Running, Fighting, or Learning, but he cannot choose 
the same activity as the previous day. Let dp[i][activity] represent the maximum points achievable up 
to day i if that activity is performed on day i. For each activity, add its points to the maximum of the 
other two activities from the previous day. Finally, take the maximum among the three activities on the last day.
*/

//space optimization 
class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<int> prev = mat[0];

        for(int i = 1; i < n; i++) {

            vector<int> curr(3);

            curr[0] = mat[i][0] +
                      max(prev[1], prev[2]);

            curr[1] = mat[i][1] +
                      max(prev[0], prev[2]);

            curr[2] = mat[i][2] +
                      max(prev[0], prev[1]);

            prev = curr;
        }

        return max({prev[0], prev[1], prev[2]});
    }
};