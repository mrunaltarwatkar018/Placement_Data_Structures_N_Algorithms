/* GFG problem:  DFS of Graph  */

/*
    Company Tags                : Accolite, Amazon, Samsung, Intuit
    GFG Link                    : https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
*/



class Solution {
  public:
  
    void DFS(unordered_map<int, vector<int>> & adj, int u, vector<bool> & visited, vector<int> & result ) {
        if ( visited[u] == true)
            return;
            
        visited[u] = true;
        result.push_back(u);
        
        for ( int &v : adj[u]) {
            if (!visited[v]) {
                DFS(adj, v, visited, result);
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> mp[]) {
        // Code here
        
        unordered_map<int, vector<int>> adj;
        
        for (int u = 0; u < V; u++) {
            for (auto v = mp[u].begin(); v != mp[u].end(); v++) {
                adj[u].push_back(*v);
            }
        }
        
        vector<int> result;
        vector<bool> visited(V, false);
        
        DFS(adj, 0, visited, result);
        
        return result;
        
        
    }
};





































/*
    YT Link: https://www.youtube.com/watch?v=V4xpJNgxMDY&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=3
*/