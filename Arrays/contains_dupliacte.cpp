/*problem link - https://leetcode.com/problems/contains-duplicate/ */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(auto num:nums){
            if(st.find(num)!=st.end())
            return true;

            st.insert(num);
        }
        return false;
    }
};

/*Use unordered_set in C++ because it provides average O(1) insertion and lookup*/