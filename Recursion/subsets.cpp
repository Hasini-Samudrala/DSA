/*problem link - https://leetcode.com/problems/subsets-ii/*/

class Solution {
public:
    vector<vector<int>>result;
    vector<int>current;

    void backtrack(vector<int>nums,int start){
        result.push_back(current);

        for(int i = start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]) continue;

            current.push_back(nums[i]);
            backtrack(nums,i+1);
            current.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return result;
    }
};

/*intuition
This is Subsets II — same duplicate-skipping trick as the last problem, but now instead of stopping at a target sum
, you record every node in the recursion tree as a valid subset (not just leaves), since every prefix built along t
he way is itself a valid subset.

Sort first — so duplicate values become adjacent, letting you detect and skip them.
At every call (not just when some condition is met), add the current subset to the result — because every partial
 combination built so far is a valid subset.
In the loop, skip candidates[i] == candidates[i-1] when i > start — this prevents choosing the "same value" twice a
t the same decision point, which is exactly what would create duplicate subsets like two identical [2]s.*/