/*problem link - https://leetcode.com/problems/insert-interval/ */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;

        for(auto interval : intervals){
            if(interval[1]<newInterval[0]){
                ans.push_back(interval);
            }
            else if(interval[0]>newInterval[1]){
                ans.push_back(newInterval);
                newInterval = interval;
            }
            else{
                newInterval[0] = min(interval[0],newInterval[0]);
                newInterval[1] = max(interval[1],newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        return ans;
    }
};

/*
Since the intervals are already sorted and non-overlapping, we process them from left to right. For each interval, 
there are only three possibilities: it lies completely before the new interval, completely after it, or overlaps with it. 
We add non-overlapping intervals directly to the answer and merge all overlapping intervals into newInterval. 
At the end, we insert the last remaining newInterval, which represents the final merged interval.
*/