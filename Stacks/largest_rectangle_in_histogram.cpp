/* problem link - https://leetcode.com/problems/largest-rectangle-in-histogram/description/*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        int max_area = INT_MIN;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()? -1 : st.top();
                max_area = max(max_area, heights[element]*(nse-pse-1));
            }   
            st.push(i);
        }

        while(!st.empty()){
            int element = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty()? -1 : st.top();
            max_area = max(max_area, heights[element]*(nse-pse-1));
        }
        return max_area;
    }
};