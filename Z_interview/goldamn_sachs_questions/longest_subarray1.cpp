/*
Suppose

P[i] = prefix sum till i

Subarray

l........r

Sum is

P[r] - P[l-1]

We want

P[r] - P[l-1] = K

Rearrange

P[l-1] = P[r] - K

This is the magic equation.

*/


class Solution {
public:
    bool subarraySum(vector<int>& nums, int k) {

        unordered_map<long long,int> mp;

        mp[0] = -1;

        long long prefix = 0;

        for(int i = 0; i < nums.size(); i++) {

            prefix += nums[i];

            if(mp.find(prefix - k) != mp.end()) {
                return true;
            }

            if(mp.find(prefix) == mp.end()) {
                mp[prefix] = i;
            }
        }

        return false;
    }
};


//without negative numbers
/*
Intuition

Since every number is positive,

expanding the window always increases the sum.
shrinking the window always decreases the sum.

So we can use Sliding Window.*/ 

bool subarraySum(vector<int>& nums, int k) {

    int left = 0;
    long long sum = 0;

    for(int right = 0; right < nums.size(); right++) {

        sum += nums[right];

        while(sum > k) {
            sum -= nums[left];
            left++;
        }

        if(sum == k)
            return true;
    }

    return false;
}