longest subarray sum <= k

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>  // for lower_bound

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, long long k) {
        // Input validation
        if (nums.empty()) {
            return 0; 
        }

        long long prefix = 0;
        vector<long long> incPrefix;     // strictly increasing prefix sums
        vector<int> incIndex;            // corresponding indices

        int result = 0;

        // Base prefix sum (0 at index -1)
        incPrefix.push_back(0);
        incIndex.push_back(-1);

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];

            long long target = prefix - k;

            // Find earliest j such that prefix[j] >= target
            auto it = lower_bound(incPrefix.begin(), incPrefix.end(), target);

            if (it != incPrefix.end()) {
                int pos = it - incPrefix.begin();
                int j = incIndex[pos];
                result = max(result, i - j);
            }

            // Maintain strictly increasing prefix sums
            if (incPrefix.empty() || prefix > incPrefix.back()) {
                incPrefix.push_back(prefix);
                incIndex.push_back(i);
            }
        }

        return result;
    }
};

// Optional main() for running the code
int main() {
    vector<int> nums = {2, -1, 2, -2, 3};
    long long k = 2;

    Solution s;
    cout << "Longest subarray length = " << s.longestSubarray(nums, k) << endl;
    return 0;
}
