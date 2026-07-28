class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> st;

        for(int x : nums){

            if(st.count(x))
                return true;

            st.insert(x);
        }

        return false;
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[left] <= nums[mid]) {

                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            // Right half is sorted
            else {

                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};


class Solution {
public:

    int firstOccurrence(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return ans;
    }

    int lastOccurrence(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        int ans = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        return {
            firstOccurrence(nums, target),
            lastOccurrence(nums, target)
        };
    }
};