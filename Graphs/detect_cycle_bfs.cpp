/* detecting cycle in a undirected graph using bfs */

class Solution{
    private:
        bool detect(int src, vector<int> adj[], int vis[]){
            vis[src]=1;
            queue<pair<int,int>>q;
            q.push({src,-1});
            while(!q.empty()){
                int parent = q.front().second;
                int node = q.front().first;

                q.pop();

                for(auto adjNode: adj[node]){
                    if(!vis[adjNode]){
                        vis[adjNode]=1;
                        q.push({adjNode,node});
                    }
                    else if(parent != adjNode){
                        return true;
                    }               
                }
            }
            return false;
        }

        bool detectCycle(int V, vector<int>adj[]){
            int vis[V]={0};
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    if(detect(i,adj,vis)==true)
                    return true;
                }
            }
            return false;
        }
};