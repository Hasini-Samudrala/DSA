/*problem link - https://leetcode.com/problems/combination-sum/*/

class Solution {
public:
    vector<vector<int>>result;
    vector<int>current;

    void backtrack(vector<int>candidates,int target,int start, int remaining ){
        if(remaining ==0)
        {
            result.push_back(current);
            return;
        }
        if(remaining<0) return;

        for(int i = start;i<candidates.size();i++){
            current.push_back(candidates[i]);

            backtrack(candidates,target,i,remaining-candidates[i]);
            current.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,target,0,target);
        return result;    
    }
};


/*intution - 
This is another backtracking problem — Combination Sum. Since numbers can be reused unlimited times, but combinations must be unique 
(order doesn't matter, [2,2,3] and [3,2,2] are the same), the trick is: at each recursive call, only consider candidates from the 
current index onward (never go backward). This naturally avoids generating duplicate permutations of the same combination, since you're 
always picking numbers in non-decreasing order of index.

At each step you either:

Include the current candidate again (stay at the same index, since reuse is allowed), or
Move on to the next candidate (skip it).

Stop and backtrack when the running sum exceeds target (prune), and record the combination when the sum exactly equals target.
*/