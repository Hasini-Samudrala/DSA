/* problem link - https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1 */

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]==-1)
                dist[i][j]=1e9;
                
                 if(i==j) dist[i][j]=0;
            }
           
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]==1e9)
                dist[i][j]=-1;
            }
        }
    }
};