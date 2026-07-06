/* problem link - https://www.geeksforgeeks.org/problems/bipartite-graph/1 */
class Solution {
    private:
        bool check(int start,int V,vector<vector<int>>& adj,vector<int>&col){
            queue<int>q;
            q.push(start);
            col[start]=0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(col[it]==-1){
                        col[it]= !col[node];
                        q.push(it);
                    }
                    else if(col[it]==col[node]){
                        return false;
                    }
                }
            }
            return true;
        }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int>col(V,-1);
        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
            }
        for(int i=0;i<V;i++){
            if(col[i]==-1){
                if(check(i,V,adj,col) == false)
                return false;
            }
        }
        return true;
    }
};