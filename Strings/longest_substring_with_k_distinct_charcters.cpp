//longest substring with atmost k distinct characters

class Solution {
public:
    int longestKSubstr(string& s, int k) {

        unordered_map<char, int> mp;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++) {

            mp[s[right]]++;

            // Too many distinct characters
            while(mp.size() > k) {

                mp[s[left]]--;

                if(mp[s[left]] == 0)
                    mp.erase(s[left]);

                left++;
            }

            // Current window is valid
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};