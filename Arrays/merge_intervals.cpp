/*
problem link - https://leetcode.com/problems/merge-intervals/description/*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int small= intervals[0][0];
        int large = intervals[0][1];
        vector<vector<int>> ans;
        
        int i =1;
        while(i<intervals.size()){
            if(large<intervals[i][0]){
                ans.push_back({small,large});
                small = intervals[i][0];
                large = intervals[i][1];
            }
            else{
                if(large<intervals[i][1]){
                    large= intervals[i][1];
                }
                if(small>intervals[i][0]){
                    small = intervals[i][0];
                }

            }
            i++;
        }
        ans.push_back({small,large});
        return ans;
    }
};

/*
\normal only */