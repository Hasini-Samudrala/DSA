/*
Problem link - https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int i=0, j=1;
        for(int k=0; k<nums.size(); k++)
        {
            if(nums[k] > 0) {
                ans[i] = nums[k];
                i += 2;
            }
            else 
            {
                ans[j] = nums[k];
                j += 2;
            }
        }
        return ans;
    }
};

//Intution 
/*
We want to alternate positive and negative numbers, starting with a positive.

So, we fix two pointers:

i = 0 → index for placing positive numbers (even indices)

j = 1 → index for placing negative numbers (odd indices)

We create a result array ans of same size as nums, filled with zeros initially.

Then, we loop through the input array:

If we find a positive number, place it at index i, and move i forward by 2 (to the next even spot).

If we find a negative number, place it at index j, and move j forward by 2 (to the next odd spot).

This guarantees that positives and negatives are placed alternately and in original relative order.

This method uses O(n) time and O(n) space and ensures all positives go to even and all negatives to odd positions.
*/

//approach -2
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;

        // Separate positive and negative numbers
        for(int num : nums) {
            if(num > 0)
                pos.push_back(num);
            else
                neg.push_back(num);
        }

        vector<int> result;
        for(int i = 0; i < pos.size(); ++i) {
            result.push_back(pos[i]);
            result.push_back(neg[i]);
        }

        return result;
    }
};

//Intution 
/*
juss make two seperate arrays for both the positive and negative numbers 
and then liek two pointers do this and solve 
*/