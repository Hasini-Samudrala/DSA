class Solution{
    void dfs(int node, vector<int> adj[], int vis[], vectro<int>&ls){
        vis[node]=1;
        ls.push_back(node);

        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,ls);
            }
        }
    }

    vector<int> dfs0(int v,vector<int>adj[]){
        int vis[v]=0;
        int start =0;
        vector<int>ls;
        dfs(start,sdj,vis,ls); 
    }
}


//space complexity - o(n)
//time complexity - o(n_+(2e))