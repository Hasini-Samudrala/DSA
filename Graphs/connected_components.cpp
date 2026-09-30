/**problem link - https://www.geeksforgeeks.org/problems/number-of-provinces/1  */

class Solution {
  public:
    void bfs(int V,int node,vector<vector<int>>&adj,vector<int>&vis){
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto adjNode: adj[node]){
                if(!vis[adjNode]){
                    q.push(adjNode);
                vis[adjNode]=1;
            }}
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V+1);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int count =0;
        
        vector<int>vis(V+1,0);
        for(int i =0;i<V;i++){
            if(vis[i]!=1)
            {
                bfs(V,i,adj,vis);
                count++;
            }
        }
        return count;
    }
}; 

/*simple bfs*/