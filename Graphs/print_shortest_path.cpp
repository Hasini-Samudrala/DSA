/* problem link - https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1 */

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int n) {
        // Code here
        vector<pair<int, int>> adj[n + 1];

        for (auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> dist(n + 1, 1e9), parent(n + 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int dis = it.first;
            int node = it.second;

            for (auto it : adj[node]) {

                int adjNode = it.first;
                int edgeWt = it.second;

                if (dis + edgeWt < dist[adjNode]) {

                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        if (dist[n] == 1e9)
            return {-1};

        vector<int> path;
        int node = n;

        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }

        path.push_back(1);
        reverse(path.begin(), path.end());

        return path;
    }
};


//but the actual code is - this has other condition also , above was striver solutioon 
class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src)
    {
        const long long INF = 1e18;

        vector<int> dist(V + 1, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &[v, w] : adj[u])
            {
                if(dist[v] > d + w)
                {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    vector<int> shortestPath(int V, vector<vector<int>>& edges, int src, int dest)
    {
        vector<vector<pair<int,int>>> adj(V + 1);

        for(auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        for(int i = 1; i <= V; i++)
            sort(adj[i].begin(), adj[i].end());

        vector<int> distSrc = dijkstra(V, adj, src);
        vector<int> distDest = dijkstra(V, adj, dest);

        if(distSrc[dest] == INT_MAX)
            return {-1};

        int shortest = distSrc[dest];

        vector<int> path;

        int curr = src;
        path.push_back(curr);

        while(curr != dest)
        {
            for(auto &[next, wt] : adj[curr])
            {
                if(distSrc[curr] + wt + distDest[next] == shortest)
                {
                    path.push_back(next);
                    curr = next;
                    break;
                }
            }
        }

        return path;
    }
};