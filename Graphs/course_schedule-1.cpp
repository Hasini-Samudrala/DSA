/* problem link - https://leetcode.com/problems/course-schedule/description/*/

class Solution {
public:

    vector<int> topoSort(int V, vector<int> adj[]) {

        vector<int> inDegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto it : adj[node]) {
                inDegree[it]--;

                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        return topo;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];

        for (auto it : prerequisites) {

            int course = it[0];
            int pre = it[1];

            adj[pre].push_back(course);
        }

        vector<int> topo = topoSort(numCourses, adj);

        return topo.size() == numCourses;
    }
};