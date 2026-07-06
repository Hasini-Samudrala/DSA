/*
Problem

S

ADOBECODEBANC

T

ABC

Need

A

B

C
Intuition

We don't care about extra letters.

We only care whether

All required letters exist.

We'll keep

frequency map

of

T

Need

A=1

B=1

C=1

Expand.

Eventually

ADOBEC

contains

A B C

Valid.

Now shrink.

Can we remove

A

No.

Window becomes invalid.

Stop.

Continue expanding.

Eventually

BANC

is found.

Length

4

Optimal.
*/


class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;

        // Store frequency of characters in t
        for(char c : t)
            need[c]++;

        int required = t.size();

        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++) {

            // If current character is still needed
            if(need[s[right]] > 0)
                required--;

            // Take current character into the window
            need[s[right]]--;

            // Window is valid
            while(required == 0) {

                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                need[s[left]]++;

                // We removed a required character
                if(need[s[left]] > 0)
                    required++;

                left++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};