class Solution{
    private:
    bool dfs(int node,int parent , vector<int> adj[], vector<int> vis[]){
        vis[node]=1;
        for(auto adjNode:adj[node]){
            if(!vis[adjNode])
            {
                if(dfs(adjNode,node,adj,vis)==true)
                return true;
            }
            else if(adjNode != parent)
            return true;
        }
        return false;
    }

    public:
    bool detect(int V, vector<vector<int>> adj[]){
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i])
            if(dfs(i,-1,adj,vis)==true) return true;
        }
        return false;
    }

}