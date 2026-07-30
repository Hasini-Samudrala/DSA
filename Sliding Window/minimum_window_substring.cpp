/* problem link - https://leetcode.com/problems/minimum-window-substring/description/ */

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(256,0);
        int l = 0 ;
        int r = 0 ;
        int count = 0 ;
        int minLen = INT_MAX;
        int sIndex = -1;
        for(int i = 0 ; i <t.size();i++){
            hash[t[i]]++;
        }
        while(r<s.length()){
            if(hash[s[r]]>0) {
                count++;
            }
            hash[s[r]]--;
            while(count == t.length()){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) count--;

                l++;
            }
            r++;
        }
        return sIndex == -1? "" : s.substr(sIndex,minLen);
    }
};