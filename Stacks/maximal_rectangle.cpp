/* problem link - https://leetcode.com/problems/maximal-rectangle/description/*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = INT_MIN;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
                if(matrix[i][j] =='1') heights[j]++;
                else heights[j]=0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
       int n = heights.size();
        int maxArea = INT_MIN;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int element = s.top();
                s.pop();
                int nse = i;
               int pse = s.empty() ? -1 : s.top();
                maxArea = max(maxArea, heights[element]*(nse-pse-1));
            }
            s.push(i);
        }
        while (!s.empty()) {
            int element = s.top();
            s.pop();

            int nse = n;
            int pse = s.empty() ? -1 : s.top();

                maxArea = max(maxArea,
                heights[element] * (nse - pse - 1));
        }
        return maxArea;
    }
};


//similar to largest rectangle in histgram .. but yuou should like make teh histoogram here .. so basically 
// you should calculate the prefix sum and calculate the histograms 