/*
problem link - https://leetcode.com/problems/next-greater-element-i/description/
*/

class Solution{
    public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int>& nums2){
        stack<int> st;
        unordered_map<int,int> nextGE;

        for(int num:nums2){
            while(!st.empty() && num>st.top()){
                nextGE[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty()){
            nextGE[st.top()]=-1;
            st.pop();
        }

        vector<int> res;
        for(int num:nums1){
            res.push_back(nextGE[num]);
        }

        return res;
    }
};

// The key idea is that the stack always contains elements whose next greater element hasn't been found yet. 
// As soon as a larger element appears, it resolves the next greater element for all smaller elements on the top of the stack. 
// Each element is pushed and popped at most once, giving an O(n + m) time complexity.