/* problem link - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/ */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int left = 0;
        int ans = 0 ; 
        for(int right = 0 ; right < s.length(); right++){
            freq[s[right]]++;
            while(freq[s[right]]>1)
            {
                freq[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};

