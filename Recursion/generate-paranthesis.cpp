/*problem link - https://leetcode.com/problems/generate-parentheses/*/

class Solution {
public:
    vector<string>result;
    void backtrack(string current , int open, int close , int n ){
        if(current.length()== 2*n){
            result.push_back(current);
            return;
        }
        if(open<n){
            backtrack(current+"(" , open+1, close, n);
        }
        if(close<open){
            backtrack(current+")", open , close+1, n);
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        backtrack("",0,0,n);
        return result;
    }
};

/*intution - 
Build the string character by character, tracking how many ( and ) you've used so far. At each step you have at most two choices:

Add ( — allowed only if you haven't used all n opens yet.
Add ) — allowed only if the count of ) used so far is less than the count of ( used so far (otherwise the string becomes invalid, e.g. ())).

When the string reaches length 2n, it's guaranteed to be a valid combination, so add it to the result.

This naturally prunes all invalid paths early instead of generating every possible string and filtering afterward.
*/