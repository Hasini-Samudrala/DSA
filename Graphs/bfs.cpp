class Solution bfs(int V , vector<int> adj[]){
    int vis[n]= {0};
    vis[0]= 1;
    queue<int> qu;
    qu.push(0);
    vector<int>bfs;
    while(!qu.empty()){
        int node = qu.front();
        qu.pop();
        bfs.push_back(node);

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it] =1;
                qu.push(it);
            }
        }
    }
    return bfs;
}

//space complexity - O(3N) == O(N)
//time complexity - every node goes once into the queue - O(n) + O(2e)