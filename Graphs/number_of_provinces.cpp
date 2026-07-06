/* problem link - https://leetcode.com/problems/number-of-provinces/*/

class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis)
    {
        vis[node] = 1;

        for(auto it : adjLs[node])
        {
            if(!vis[it])
                dfs(it, adjLs, vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int V = isConnected.size();

        vector<vector<int>> adjLs(V);

        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(isConnected[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                }
            }
        }

        vector<int> vis(V, 0);

        int cnt = 0;

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }

        return cnt;
    }
};


// so we do a dfs , and then calculate the number of provinces ( basically teh number of connected components )