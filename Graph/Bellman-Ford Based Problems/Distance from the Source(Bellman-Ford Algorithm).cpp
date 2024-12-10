/* GFG Problem No.: Distance from the Source(Bellman-Ford Algorithm)  */

/*
    Company Tags                : FAmazon, Microsoft (Generally asked as a follow up qn of Dijkstra's Algorithm)
    GFG Link                    : https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
*/

// TC:
// O(V*E)


class Solution {
    public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> result(V, 1e8);
        result[src] = 0;
        
        for (int count = 1; count <= V - 1; count++ ) {
            for (auto &edge : edges ) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if (result[u] != 1e8 && result[u] + w < result[v]) {
                    result[v] = result[u] + w;
                }
                
            }
        }
        //Now detect negative cycle
        for (auto & edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if (result[u] != 1e8 && result[u] + w < result[v]) {
                return {-1};
            }
        }
        return result;
    }
};











// OR
class Solution {
    public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> result(V, 1e8);
        result[S] = 0;
        
        for(int c = 1; c<=V-1; c++) {
            
            for(auto &edge : edges) {
                
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u] != 1e8 && result[u] + w < result[v]) {
                    result[v] = result[u] + w;
                }
                
            }
            
        }
        
        //Now detect negative cycle
        for(auto &edge : edges) {
            
            int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u] != 1e8 && result[u] + w < result[v]) {
                    return {-1};
                }
        }
        
        return result;
    }
};













// OR 

//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> result(V, INT_MAX);
        result[src] = 0;
        
        for (int count = 1; count <= V - 1; count++ ) {
            for (auto &edge : edges ) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if (result[u] != INT_MAX && result[u] + w < result[v]) {
                    result[v] = result[u] + w;
                }
                
            }
        }
        //Now detect negative cycle
        for (auto & edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if (result[u] != INT_MAX && result[u] + w < result[v]) {
                return {-1};
            }
        }
        return result;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends