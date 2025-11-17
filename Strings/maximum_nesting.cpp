/*
problem link - https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
*/

//approach -1
class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int final=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
            count++;

            if(s[i]==')')
            count--;

            final = max(final ,count);
        }

        return final;
    }
};

//intution 
/*
this is basically that valid paarntheseis probelm wjhere u replca e( with +1 nd ) with -1 
*/