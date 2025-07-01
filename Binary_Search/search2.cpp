/*
Probelm link -https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
*/

//Apprach 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return true;
            } 
            if (nums[mid] == nums[left]) {
                left++;
                continue;
            }
            if (nums[mid] >= nums[left]) {
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

        return false;        
    }
};


//Intution
/*
🧠 Key Idea:
We still use binary search, but duplicates can break the guarantee of one sorted half. So, we add a check to skip duplicates.

✨ Step-by-step Intuition:
Initialize:
left = 0, right = n - 1.

Binary search loop while left <= right:

Find mid = (left + right) / 2.

If nums[mid] == target, return true.

Handle duplicates:

If nums[mid] == nums[left], we can't be sure which half is sorted.
👉 So we just skip the duplicate: left++.

Otherwise, check which half is sorted:

If nums[mid] >= nums[left]:
👉 Left half is sorted

Check if target lies in [left, mid].

If yes, move right = mid - 1.

Else, search in right half: left = mid + 1.

Else:
👉 Right half is sorted

Check if target lies in [mid, right].

If yes, move left = mid + 1.

Else, search in left half: right = mid - 1.

Return false if not found.

❗ Why left++ is needed:
When nums[mid] == nums[left], we can't decide which half is sorted. Skipping the duplicate narrows the search window safely.

💡 One-liner Trick:
“When duplicates exist, be ready to skip the confusing ones (left++) when you're unsure which side is sorted.”
*/