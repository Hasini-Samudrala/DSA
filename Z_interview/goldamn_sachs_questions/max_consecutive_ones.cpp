Maximum consecutive ones after flipping K zeros
/**Problem

Given a binary array

0 1 1 0 1 0 1 1

and an integer

K

You may flip at most K zeros into ones.

Return the maximum consecutive ones possible.

Step 1 : Pattern Recognition

Whenever you hear

Longest subarray...

or

Maximum window...

or

At most K something...

🚨 Think Sliding Window.

Step 2 : The BIG Intuition

Don't think

Which K zeros should I flip?

That's difficult.

Instead, think like this:

"If a window contains at most K zeros, I can flip all those zeros."

So the question becomes

Find the longest subarray containing at most K zeros.

That's it.

This is the entire trick. */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int zeroCount = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] == 0)
                zeroCount++;

            while (zeroCount > k) {

                if (nums[left] == 0)
                    zeroCount--;

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};