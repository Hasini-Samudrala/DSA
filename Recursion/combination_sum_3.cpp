/*problem link - https://leetcode.com/problems/combination-sum-iii/*/

class Solution {
public:
    vector<vector<int>>result;
    vector<int>current;

    void backtrack(int start , int k , int remaining){
        if(current.size()==k){
            if(remaining==0){
                result.push_back(current);
                return;
            }
        }
        for(int i = start;i<10;i++){
            if(i>remaining) break;

            current.push_back(i);
            backtrack(i+1,k,remaining-i);
            current.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(1,k,n);
        return result;
    }
};

/*intution - 
The "candidates" are fixed and always distinct: digits 1 through 9. So no sorting or duplicate-skip logic is needed at
 all (digits are naturally unique). The only two constraints to track are: exactly k numbers used, and sum equals n. 
Backtrack through digits 1-9 in increasing order, and only record a combination when both conditions hit simultaneously.

Why the pruning matters here: if (i > remaining) break is what keeps this fast — since digits are tried in increasing order,
 once a digit exceeds the remaining sum needed, every larger digit will too, so you can stop the loop entirely rather
  than just skipping one digit.

Why no duplicate-skip logic is needed: unlike the last two problems, the candidate pool (1 to 9) has no duplicate values 
by definition — every digit appears exactly once as a possible choice — so the i > start && nums[i]==nums[i-1] check from
 Combination Sum II / Subsets II simply doesn't apply here.*/