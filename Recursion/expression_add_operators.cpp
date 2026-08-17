/*problem link - https://leetcode.com/problems/expression-add-operators/ */

class Solution {
public:
    vector<string>result;
    void backtrack(string &num, int target, int index, string expr, long long evaluated, long long lastOperand){
        if(index ==num.length()){
            if(evaluated == target){
                result.push_back(expr);
            }
            return;
        }

        for(int i=index;i<num.length();i++){
            if(i>index && num[index]=='0') break;

            string currStr = num.substr(index,i-index+1);
            long long curr = stoll(currStr);

            if(index==0){
                backtrack(num,target,i+1,currStr,curr,curr);
            }
            else{
                backtrack(num,target,i+1,expr+"+"+currStr,evaluated+curr,curr);

                backtrack(num, target, i+1, expr+"-"+currStr,evaluated-curr,-curr);

                backtrack(num,target,i+1,expr+"*"+currStr,evaluated-lastOperand+lastOperand*curr,lastOperand*curr);
            }
        }
        return;
    }
    vector<string> addOperators(string num, int target) {
        backtrack(num,target,0,"",0,0);
        return result;
    }
};


/*
intutuion - 
Core idea:

At each recursive step, pick a substring starting at the current index (this becomes one "number" 
in the expression) — skip it if it has a leading zero (unless it's literally "0" alone). Then try 
appending it to the expression with +, -, or *, tracking:

evaluated: the running total so far
lastOperand: the value of the last number term added (needed to "undo and redo" for *)

Why the * case looks weird — the key trick explained:

Say evaluated = 1+2 = 3 and lastOperand = 2 (the "2" we just added). Now we want to append *3 to get 1+2*3.

We can't just do evaluated * curr (that'd wrongly multiply the whole running total). Instead:

Undo the last addition: evaluated - lastOperand → 3 - 2 = 1 (back to just "1")
Redo with multiplication applied only to the last term: + (lastOperand * curr) → 1 + (2*3) = 7

So evaluated - lastOperand + lastOperand * curr = 1 + 6 = 7, which correctly represents 1+2*3=7 (not (1+2)*3=9).

The new lastOperand becomes lastOperand * curr (i.e., 6), so if another * follows immediately (e.g., 1+2*3*4), 
it multiplies the whole 2*3 term correctly, not just the 3.*/