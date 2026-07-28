Longest substring without repeating characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            freq[s[right]]++;

            while (freq[s[right]] > 1) {

                freq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

/*
The question says

Longest substring

and

without repeating characters

We need the longest VALID window.

Whenever the window becomes invalid (contains duplicates),

we shrink it.

This is exactly the Longest Sliding Window pattern.

Step 2 : Intuition ⭐⭐⭐

Imagine you're reading characters one by one.

Current window

a b c

Everything is unique.

Can we expand?

Of course.

Now we read

a

Window becomes

a b c a

Oops.

Duplicate.

Window is INVALID.

What should we do?

Remove characters from the left until the duplicate disappears.

That's the whole algorithm.
Step 3 : Why does shrinking work?

Suppose

Window

a b c a

Duplicate

a

Remove left

b c a

Now every character is unique.

Window becomes valid again.

Notice

We never move the right pointer backwards.

Every character

enters once
leaves once

Hence

O(n)
Step 4 : Data Structure

We need to know

Is this character already inside my window?

Use

unordered_map<char,int> freq;

or

unordered_set<char>

Frequency map is more general and easier to extend.
*/