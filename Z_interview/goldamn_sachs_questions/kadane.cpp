class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int currentSum = 0;
        int maxSum = INT_MIN;

        for (int x : nums) {

            currentSum += x;

            maxSum = max(maxSum, currentSum);

            if (currentSum < 0)
                currentSum = 0;
        }

        return maxSum;
    }
};

// anytime we encounter a negative sum we again set as 0 , coz teh negative sum will not help in getting teh maximum sum of teh subarray 