/* GFG problem:  Undirected Graph Cycle */

/*
    Company Tags                : Flipkart, Amazon, Microsoft, Samsung, MakeMyTrip, Adobe, Oracle 
    GFG Link                    : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/


// Approach 2 : Using Queue of Pair {node, parent_of_node} (BFS)
// Expected Time Complexity: O(V + E)
// Expected Space Complexity: O(V)


class Solution {
    public:
    
    bool isCycleBFS(vector<int> adj[], int u, vector<bool> & visited) {
        queue<pair<int, int>> que;
        
        que.push({u, -1});
        visited[u] = true;
        
        while(!que.empty()) {
            pair<int, int> P = que.front();
            que.pop();
            
            int source = P.first;
            int parent = P.second;
            
            for ( int & v : adj[source]) {
                if (visited[v] == false) {
                    visited[v] = true;
                    que.push({v, source});
                } else if (v != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        
        for ( int i = 0; i < V; i++) {
            if (!visited[i] && isCycleBFS(adj, i, visited) ) {
                return true;
            }
        }
        
        return false;
    }
};


//Using Queue of Pair {node, parent_of_node}
class Solution {
    public:
    bool isCycleBFS(vector<int> g[], int V, int start, vector<bool>& visited) {
        queue<pair<int, int>> que;
        que.push({start, -1});
        visited[start] = true;
        while(!que.empty()) {
            int curr   = que.front().first;
            int parent = que.front().second;
            que.pop();
            
            for(auto x : g[curr]) {
                if(visited[x] == false) {
                    que.push({x, curr});
                    visited[x] = true;
                }
                else if(x != parent)
                    return true;
            }
        }
        
        return false;
    }


    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i] && isCycleBFS(adj, V, i, visited)) {
                return true;
            }
        }
        
        return false;
        
    }
};


/*
    YT Link: https://www.youtube.com/watch?v=UrQv5YMC060&list=PLpIkg8OmuX-LZB9jYzbbZchk277H5CbdY&index=5
*/