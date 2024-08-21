/* GFG Problem: Shortest path in Undirected Graph */

/*
    Company Tags                : Updated Soon
    GFG Link                    : https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
*/


class Solution {
    public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int> adj[N];
        for (auto it : edges) {
            int u = it[0], v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<pair<int, int>> q;
        vector<int> dist(N, 1e9);
        
        q.push({0, src});
        dist[src] = 0;
        
        while (!q.empty()) {
            
            int node = q.front().second;
            int dis = q.front().first;
            q.pop();
            
            if (dist[node] < dis)
                continue;
            
            
            for (auto it : adj[node]) {
                
                if (dist[it] > dis + 1) {
                    
                    dist[it] = dis + 1;
                    q.push({dist[it], it});
                }
            }
        }
        
        for (auto &it : dist)
            if (it == 1e9) it = -1;
        
        return dist;
    }
};