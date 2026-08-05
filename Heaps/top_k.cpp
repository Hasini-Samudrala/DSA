/*problem link - https://leetcode.com/problems/top-k-frequent-elements/description/ */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;

        for(auto x:nums){
            freq[x]++;
        }
        priority_queue<pair<int,int>>pq;

        for(auto &it:freq){
            pq.push({it.second,it.first});
        }
        vector<int> ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

//we create a frequency map , so that we know wht is teh frequency of each unique element
// now that we have frequencies , we create a priority queue max heap technically and then try to extract the top k elements 
// from it 

//uk the logic .. be careful with the implememtation 