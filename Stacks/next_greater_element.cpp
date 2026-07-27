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

class Solution{
    public:

    vector<int> nextGreater(vector<int>& nums) {
        // Stack to store elements
        stack<int> st;

        // Result array of same size
        int n = nums.size();
        vector<int> res(n);

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Pop all smaller or equal elements
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // If stack is empty, no greater element
            if (st.empty()) res[i] = -1;

            // Else top of stack is the answer
            else res[i] = st.top();

            // Push current element
            st.push(nums[i]);
        }

        // Return the result
        return res;

    }
}