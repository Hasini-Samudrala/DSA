class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int S) {
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
        
        set<pair<int, int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0, S});
    dist[S] = 0;

    while (!st.empty())
    {
        auto it = *(st.begin());

        int node = it.second;
        int dis = it.first;

        st.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (dis + edgeWeight < dist[adjNode])
            {
                // Remove the old distance if it exists
                if (dist[adjNode] != 1e9)
                {
                    st.erase({dist[adjNode], adjNode});
                }

                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
    }
};


//set is better in one way , coz it removes the old distance if it exists ( in the striver video , he takes the example of
// {8,5} and {10,5} where after the distance to the node 5 is updated as 8 , it need not again take the pair {10,5} which 
// is redundant , so we can use set and erase that one )