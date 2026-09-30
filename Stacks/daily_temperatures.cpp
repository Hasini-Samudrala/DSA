/*problem link - */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> ans(n, 0);

        stack<int> st;   // stores indices

        for(int i = 0; i < n; i++) {

            while(!st.empty() &&
                  temperatures[i] > temperatures[st.top()]) {

                int prev = st.top();
                st.pop();

                ans[prev] = i - prev;
            }

            st.push(i);
        }

        return ans;
    }
};

/*For every day, we need to find the next day with a higher temperature. Instead of looking forward for every day, 
keep the indices of days that are still waiting for a warmer temperature in a decreasing stack. When today's temperature 
is greater than the temperature at the stack's top, today's temperature is the answer for that earlier day, so pop it and
 store the distance. Each index is pushed and popped at most once, giving O(n) time*/