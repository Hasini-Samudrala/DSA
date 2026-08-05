/*problem link - https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1*/

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> vis(V,0);
        
        pq.push({0,0});
        vector<vector<pair<int,int>>> adj(V);

for(auto &it : edges)
{
    int u = it[0];
    int v = it[1];
    int wt = it[2];

    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});   // because MST graph is undirected
}
        
        int sum =0;
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            
            int node = it.second;
            int wt = it.first;
            
            if(vis[node]==1) continue;
            
            vis[node]=1;
            sum+=wt;
            
            for(auto it:adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if(!vis[adjNode])
                pq.push({edW,adjNode});
            }
        }
         return sum;
    }
};

/*Start from any node and keep growing the Minimum Spanning Tree one node at a time. Use a min heap to 
always pick the minimum-weight edge that connects a visited node to an unvisited node. After adding a node to the MST, 
push all of its outgoing edges into the heap. Ignore edges leading to already visited nodes to avoid cycles.*/