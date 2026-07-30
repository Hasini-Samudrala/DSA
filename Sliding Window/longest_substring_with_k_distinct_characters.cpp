/* problem link - https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1 */

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
         int maxLen = -1 ;
        int r = 0 ;
        int l = 0 ;
        unordered_map<char,int>mpp;
        while(r<s.length()){
            mpp[s[r]]++;
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            if(mpp.size()==k){
                maxLen = max(maxLen,r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};