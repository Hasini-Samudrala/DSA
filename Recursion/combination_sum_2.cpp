/*problem link - https://leetcode.com/problems/combination-sum-ii/*/

class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>candidates,int target, int start, int remaining){
        if(remaining==0){
            result.push_back(current);
            return;
        }

        if(remaining<0) return;

        for(int i = start;i<candidates.size();i++){
            if(i>start && candidates[i]== candidates[i-1]) continue;
            current.push_back(candidates[i]);

            backtrack(candidates,target,i+1,remaining-candidates[i]);

            current.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0,target);
        return result;
    }
};

/*intution 
Intuition:

Sort the array first. This does two things: it lets you detect duplicate values easily (they'll be adjacent), and it lets you
 prune early once the running sum exceeds target (since later elements only get bigger).

In the recursion, move to i+1 for the next call (not i, unlike the last problem) — since each number can only be used once.

Skip duplicates at the same recursion depth: if candidates[i] == candidates[i-1] and i > start, skip it. This is the key trick
 — it prevents picking the "same value" twice at the same decision point,
 which is what causes duplicate combinations like picking the 1st 1 vs the 2nd 1 and getting identical results.*/