/* problem link - https://leetcode.com/problems/longest-repeating-character-replacement/description/ */

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l  = 0 ;
        int r = 0 ; 
        int maxF = 0 ;
        int maxlen = 0 ;
        
        int n  = s.length();
        vector<int> hash(26,0);
        while(r<n){
            hash[s[r]-'A']++;
            maxF = max(maxF , hash[s[r]-'A']);

            while((r-l+1)-maxF>k){
                hash[s[l]-'A']--;
                maxF=0;
                for(int i = 0 ;i<hash.size();i++){
                    maxF = max(maxF, hash[i]);
                }
                l++;
            }

            if((r-l+1)-maxF <= k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
         }
         return maxlen;
    }
};