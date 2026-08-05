/*problem link - https://leetcode.com/problems/longest-palindromic-substring/ */

class Solution {
public:
    int maxLen = 0;
    int start =0;

    void expand(string &s , int left , int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;

            int len = right-left-1;
            if(len>maxLen){
                maxLen = len;
                start = left+1;
            }
        }
        return ;
    }
    string longestPalindrome(string s) {
        for(int i  = 0;i<s.size();i++){
            expand(s,i,i);
            expand(s,i,i+1);
        }
        return s.substr(start,maxLen);
    }
};

/*
Every palindrome has a center.

Check both odd and even length palindromes:

expand(i, i);
expand(i, i + 1);

*/