/* problem link - https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1 */

class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        // code here
        int n =mat.size();
        int m = mat[0].size();
        
         if(mat[src[0]][src[1]]==0 || mat[dest[0]][dest[1]]==0)
         return -1;
        
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>> q;
        
        dis[src[0]][src[1]] = 0;
        q.push({0,{src[0],src[1]}});
         int dr[] = {-1,0,1,0};
        int dc[]  = {0,-1,0,1};
            
            //  vector<int> dr(4) = {-1,0,1,0};
            // vector<int>dc(4)= {0,-1,0,1};
        while(!q.empty()){
           int dist = q.front().first;
           int r = q.front().second.first;
           int c = q.front().second.second;
           
           q.pop();
           for(int i=0;i<4;i++){
               int newr = r +dr[i];
               int newc = c + dc[i];
               
               if(src==dest) return 0;
               
               if(newr>=0 && newr<n && newc>=0 && newc<m && mat[newr][newc]==1 && 
               dist + 1< dis[newr][newc]){
                   dis[newr][newc] = dist+1;
                   
                   if(newr == dest[0] && newc==dest[1])
                   return dist+1;
                   
                   q.push({dist+1, {newr,newc}});
               }
               
              
           }
        }
        return -1;
    }
};

/*
 if ( src == dest ) very very important */