/* GFG Problem: Strongly Connected Components (Kosaraju's Algo) */

/*
    Company Tags                : Amazon, Visa
    Question Link               : https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
*/



//Kosaraju's Algorithm :     Time  : O(V+E), V = # vertices, E = # edges , Space : O(V)
class Solution
{
	public:
	
	void dfsFill(int u, vector<vector<int>>& adj, vector<bool> &visited, stack<int>& st) {
	    visited[u] = true;
	    
	    for(int &v : adj[u]) {
	        
	        if(!visited[v]) {
	            dfsFill(v, adj, visited, st);
	        }
	        
	    }
	    
	    st.push(u);
	}
	
	void dfsTraverse(int u, vector<vector<int>>& adjReversed, vector<bool> &visited) {
	    visited[u] = true;
	    
	    for(int &v : adjReversed[u]) {
	        
	        if(!visited[v]) {
	            dfsTraverse(v, adjReversed, visited);
	        }
	        
	    }

	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> st;
        vector<bool> visited(V, false);
        
        for(int i = 0; i<V; i++) {
            if(!visited[i]) {
                dfsFill(i, adj, visited, st);
            }
        }
        
        
        vector<vector<int>> adjReversed(V);
        for(int u = 0; u<V; u++) {
            for(int &v : adj[u]) {
                
                //u->v
                //v->u
                adjReversed[v].push_back(u);
                
            }   
        }
        
        int count = 0;
        
        visited = vector<bool>(V, false);
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!visited[node]) {
                dfsTraverse(node, adjReversed, visited);
                count++;
            }
        }
        
        return count;
        
    }
};




































// OR


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  void dfsFill(int u, vector<vector<int>>& adj, vector<bool> & visited, stack<int> & st) {
      visited[u] = true;
      
      for (int & v : adj[u]) {
          if(!visited[v]) {
              dfsFill(v, adj, visited, st);
          }
      }
      
      st.push(u);
  }
  
  void dfsTraversal(int u, vector<vector<int>>& adjReversed, vector<bool> & visited) {
      visited[u] = true;
      for (int &v : adjReversed[u]) {
          if (!visited[v]) {
              dfsTraversal(v, adjReversed, visited);
          }
      }
  }
  
  
  
  
    // Function to find number of strongly connected components in the graph.
    int kosaraju(vector<vector<int>>& adj) {
        // code here
        
        // Step 1: Store order of DFS in stack in Topological Sort
        
        stack<int> st;
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsFill(i, adj, visited, st);
            }
        }
        
        
        // Step 2: make reverse graph
        vector<vector<int>> adjReversed(V);
        for (int u = 0; u < V; u++) {
            for (int &v : adj[u]) {
                // here u -> v but we want v -> u
                adjReversed[v].push_back(u);
            }
        }
        
        
        // Step 3: Call DFS based on stack order
        int countSCC = 0;
        visited = vector<bool> (V, false);
        
        while(!st.empty()) {
            int node =st.top();
            st.pop();
            
            if (!visited[node]) {
                dfsTraversal(node, adjReversed, visited);
                countSCC++;
            }
        }
        
        
        return countSCC;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends