/*problem link - https://leetcode.com/problems/valid-palindrome/*/

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        while(left < right)
        {
            while(left < right && !isalnum(s[left]))
                left++;

            while(left < right && !isalnum(s[right]))
                right--;

            if(tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};

/*
Use two pointers, one starting from the beginning and one from the end of the string. 
Skip all characters that are not letters or digits. Convert both valid characters to lowercase before comparing them. 
If any pair doesn't match, return false; otherwise, continue until the pointers cross.
*/