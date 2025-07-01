/*
Problem link - https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*/

//Appraoch 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;        
    }
};

//Intution
/*
Start with binary search setup: left = 0, right = n - 1.

Find the middle:
mid = (left + right) / 2.

Check if nums[mid] is the target.
If yes, return mid.

Now, check which half is sorted:

If nums[mid] >= nums[left]:
👉 Left part is sorted

Check if target lies in this range (nums[left] <= target <= nums[mid])

If yes, move right = mid - 1

Else, search in the right half: left = mid + 1

Else:
👉 Right part is sorted

Check if target lies in this range (nums[mid] <= target <= nums[right])

If yes, move left = mid + 1

Else, search in the left half: right = mid - 1

If not found, return -1
*/