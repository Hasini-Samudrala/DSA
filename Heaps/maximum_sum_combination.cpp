
/*probelm link - https://www.geeksforgeeks.org/problems/maximum-sum-combination/1 */

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int N = a.size();
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>vis;
        
        pq.push({a[N-1]+b[N-1],{N-1,N-1}});
        vis.insert({N-1,N-1});
        
        vector<int>ans;
        while(k--){
            auto top = pq.top();
            pq.pop();
            
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            ans.push_back(sum);
            if(i-1>=0 && vis.find({i-1,j})==vis.end()){
                pq.push({a[i-1]+b[j],{i-1,j}});
                vis.insert({i-1,j});
            }
            
            if(j-1>=0 && vis.find({i,j-1})==vis.end()){
                pq.push({a[i]+b[j-1],{i,j-1}});
                vis.insert({i,j-1});
            }
        }
        return ans;
    }
};

/*
Sort both arrays. The maximum sum always comes from the largest elements (bottom-right of the sum matrix). 
Use a max heap to always pick the current largest unexplored sum. After removing a pair (i, j), only its left (i, j-1) 
and up (i-1, j) neighbors can produce the next largest sums. Use a visited set to avoid inserting the same pair twice.
*/