/*
Problem link - https://leetcode.com/problems/remove-outermost-parentheses/description/

*/

//Approach-1

class Solution{
    public:
    string removeOuterParentheses(string s){
        string ans ="";
        int cnt =0;

        for(char c:s){
            if(c=='('){
                if(cnt>0) ans+=c;
                cnt++;
            }

            else{
                cnt--;
                if(cnt>0) ans+=c;
        }
    }
     return ans;
}
};

//intution
/*
The idea is to track how deep we are inside nested parentheses using a counter.
Every time we see '(', we increase the counter (depth), and every time we see ')',
we decrease it. In any valid parentheses string, the outermost pair of each primitive is always
the one that takes depth from 0 → 1 for '(' and 1 → 0 for ')'. These depth-1 brackets form the
external shell and must be removed. So while iterating, we only add a bracket to the answer if
the depth after adjusting shows we are strictly inside the outer layer — i.e., depth > 0. This ensures 
all outermost parentheses are skipped, and only the inner structure is kept.
*/