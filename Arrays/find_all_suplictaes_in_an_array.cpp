/*problem link - https://leetcode.com/problems/find-all-duplicates-in-an-array/ */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result;
        for(int i = 0 ;i<nums.size();i++){
            int idx = abs(nums[i])-1;
            if(nums[idx]<0)
            result.push_back(abs(nums[i]));
            else
            nums[idx] = -nums[idx];
        }
            return result;

    }
};

/*Since every value is between 1 and n, each value v has a "designated home" at index v-1. Walk through the array,
 and for each number, go to its home index and flip the sign of whatever's there. The first time you visit an index, 
 it's positive → you flip it negative. If you land on an index that's already negative, that means its corresponding
  value has already been seen once before — so the current number is a duplicate. This trick uses the array itself as 
  a hashmap, avoiding extra space.*/