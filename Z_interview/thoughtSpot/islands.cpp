int n = grid,size();
int m - grid[0].size();

vector<vector<int>> visited(n,vector<int>(m,0));

int count =0;

for(int i = 0;i<n;i++){
    for(int j = 0;j<m;j++){
        if(vis[i][j] != 1 && grid[i][j] =='1')
        {
            bfs(i,j,grid,visited);
            count++;
        }
    }
}

void bfs(int row , int col, vector<vector<int>>& grid, vector<vector<int>>&vis){
    int n = grid.size();
    int m = grid[0].size();
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,-1,0,1};
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty()){
        auto row = q.front().first;
        auto col = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1 && grid[nrow][ncol]==1){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }
        }
    }
}



// detetcing cycle in a undirected graph 
bool detect(int node, vector<vector<int>>&adj, vector<int>&vis){
    vis[node]=1;
    queue<pair<int,int>>q;
    q.push({node,-1});
    while(!q.empty()){
        auto node = q.front().first;
        auto parent = q.front().second;
        q.pop();
        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                vis[adjNode]=1;
                q.push({adjNode,parent});
            }
            else if(parent != adjNode) return true;
        }
    }
    return false;
}

for(int i=0;i<V;i++){
    if(!vis[i]){
        if(detect(i,adj,vis))
        return true;
    }
}
return fasle;


//detect cycle in a drected graph 
bool detct(int node, vector<vector<int>>&adj, vector<int>pathVis, vector<int>&vis){
    vis[node]=1;
    pathVis[node]=1;
    for(auto adjNode : adj[node]){
        if(!vis[adjNode]){
        if(dfs(adjNode,adj,pathVis,vis);==true) return true;
        }
        else if(!pathVis[node]){
            return true;
        }
    }
}


//biparttite graoh 
// it is liek we should be able to colour doffernt colours for teh adjacent nodes
bool check(int node, vetor<vector<int>>&adj, vector<int>&vis, vector<int>&col){
    queue<int>q;
    q.push(node);
    vis[node]=1;
    col[node] = 0;

    while(!q.empty()){
        auto node = q.front();
        q.pop();

        for(auto adjNode: adj[node]){
            if(col[adjNode]==-1){
                col[adjNode] = !col[node];
                vis[adjNode]=1;
            }
            else if(col[adjNode]==col[node])return false;
        }
    }
    return true;
}


// topological sort 
vector<int>inDegree(V,0);
for(int i =0;i<V;i++){
    for(auto it:adj[it]){
        inDegree[it]++;
    }
}

queue<int>q;
for(int i =0;i<V;i++){
    if(inDegree[i]==0)
    q.push(i);
}
int cnt=0;
while(!q.empty()){
    int node = q.front();
    q.pop();
    cnt++;

    for(auto adjNode : adj[node]){
        inDegree[adjNode]--;
        if(inDegree[adjNode]==0)
        q.push(adjNode);
    }
}

if(cnt==V) return true;
return false;



//for rotten oranges 
int n = grid.size();
int m = grid[0].size();
vector<vector<int>>vis(n,vector<int>(m,0));
queue<pair<pair<int,int>>,int>q;
fro(int i =0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]==2){
            q.push({{i,j},0});
            vis[i][j]=2;
        }
        else{
            vis[i][j]=0;
        }
    }
}

int tm = 0;
while(!q.empty()){
    int r = q.front().first.first;
    int c = q.front().first.second;

    int t = q.front().second;
    tm = max(tm,t);
    q.pop();

    vector<int>delRow = {-1,0,1,0};
    vector<int>delCol = {0,-1,0,1};

    for(int i =0;i<4;i++){
        int nrow = r+ delRow[i];
        int ncol = c+delCol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] !=2 && grid[nrow][ncol]==1){
            q.push({{nrow,ncol},t+1});
            vis[nrow][ncol] = 2;
        }
    }
}

for(int i =0;i<n;i++)+{
    for(int j =0;j<m;j++){
        if(grid[i][j]==1 && vis[i][j]==0)
        return false;
    }
}
return true;


// number of provinces
vector<vector<int>>adj(V);

for(int i =0;i<V;i++){
    for(int j = 0;j<m;j++){
        if(isConnected[i][j]==1 && i!=j){
            adj[i].push_back(j);
        }
    }
}

vector<int>vis(V);
for(int i =0;i<V;i++){
    if(vis[i]!=1)
    {
        cnt++;
        dfs(node,adj,vis);
    }
}

vois dfs(int node, vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it])dfs(it,adj,vis);
    }
}


// max dpeth of binary tree 
int maxDepth(TreeNode* node){
    if(node==NULL)
    return 0;

    int lh = maxDepth(lh->left);
    int rh = maxDepth(rh->right);

    return 1+max(lh,rh);
}
