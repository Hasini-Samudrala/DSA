/*problem link  - https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/ */

class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        unordered_set<int>setp;
        int deletions =0;
        for(int f:freq){
            while(f>0 && setp.count(f)){
                f--;
                deletions++;
            }
            setp.insert(f);
        }
        return deletions;
    }
};

/*intution
First count how many times each character appears.
We keep a set of frequencies that are already used.
If a frequency is already present, keep deleting characters from that frequency (f--) until we get an unused frequency.
Each decrement means one deletion, and this guarantees that all remaining character frequencies are unique.*/