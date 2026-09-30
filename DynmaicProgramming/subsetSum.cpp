/*problem link - https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1*/

class Solution {
  public:
  bool f(int i , int target , vector<int>&arr, vector<vector<int>>&dp){
      if(target==0)
      return true;
      
      if(i ==0)
      return arr[0] == target;
      
      if(dp[i][target]!=-1)
      return dp[i][target];
      
      
      bool nonTake = f(i-1, target, arr, dp);
      
      bool take = false;
      
      if(arr[i]<=target){
          take = f(i-1, target-arr[i], arr, dp);
      }
      
      return dp[i][target] = take || nonTake;
  }
    bool isSubsetSum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(k+1,-1));
        return f(n-1,k,arr,dp);
        
    }
};

//intution 
/*
For every element, we have two choices: take it or not take it.
If we don't take it, the target remains the same; if we take it, the target becomes target - arr[i]. Since each element can be used only once, we move to i-1 in both cases.
We use memoization to store the result of each (index, target) state so that the same state is not calculated repeatedly.
*/