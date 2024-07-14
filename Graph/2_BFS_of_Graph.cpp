/* GFG problem:  BFS of Graph  */

/*
    Company Tags                : Flipkart, Amazon, Microsoft, Samsung, Ola Cabs, Adobe, SAP Labs 
    GFG Link                    : https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/



class Solution {
    public:
    
    void BFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<int> & result) {
        queue<int> que;
        
        que.push(u);
        visited[u] = true;
        result.push_back(u);
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            for ( int & v: adj[u]) {
                if ( !visited[v]) {
                    que.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
            
            
        }
    }
    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> mp[]) {
        
        
        unordered_map<int, vector<int>> adj;
        
        for ( int i = 0; i < V; i++) {
            
            for ( auto it = mp[i].begin(); it != mp[i].end(); it++) {
                adj[i].push_back(*it);
            } 
        }
        
        vector<bool> visited(V, false);
        vector<int> result;
        
        BFS(adj, 0, visited, result);
        
        return result;
    }
};





































/*
    YT Link: https://www.youtube.com/watch?v=V4xpJNgxMDY&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=3
*/