/* problem link - https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1 */

class Solution {
    private:
        void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid,
        vector<pair<int,int>>&vec,vector<int>&delRow,vector<int>&delCol,int row0,int col0){
        vis[row][col]=1;
        vec.push_back({row-row0,col-col0});
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
            grid[nrow][ncol]=='L'){
                dfs(nrow,ncol,vis,grid,vec,delRow,delCol,row0,col0);
            }
        }
        }
  public:
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        vector<int>delRow={-1,0,1,0};
        vector<int>delCol = {0,-1,0,1};
        
        set<vector<pair<int,int>>>st;
        
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='L'){
                vector<pair<int,int>> vec;
                dfs(i,j,vis,grid,vec,delRow,delCol,i,j);
                st.insert(vec);
            }
            }
        }
        return st.size();
    }
};
