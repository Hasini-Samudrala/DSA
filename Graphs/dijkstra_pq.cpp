/* problem link - https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1 */

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>> adj[V];

        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});   // because graph is undirected
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>>pq;
        vector<int>dist(V,1e9);
        
        dist[src]=0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            if(dis > dist[node])
        continue;
            for(auto it:adj[node])
            {
                int edgeWeight = it.second;
                int adjNode = it.first;
                
                if(dis+edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};

/* tc - o(elogV)*/