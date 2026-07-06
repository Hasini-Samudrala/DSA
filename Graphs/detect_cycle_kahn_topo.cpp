
class Solution{
   
        bool detectCycle(int V, vector<int>adj[]){
           vector<int>inDegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it : adj[it]){
                inDegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0)
            q.push(i);
        }
        int cnt;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }
        if(cnt==V) return true;
        return false;
        }
};