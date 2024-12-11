/* GFG Problem No.: Minimum Spanning Tree (Prim's)  */

/*
    Company Tags                : Amazon, Cisco, Samsung
    GFG Link                    : https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
*/



//Approach-1 : Using Priority_queue
// TC: O(E * (logE + log E)) = O(ElogE)

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    typedef pair<int, int> P;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        priority_queue<P, vector<P>, greater<P>> pq;  // {weight, node}
        
        pq.push({0, 0});
        vector<bool> inMST(V, false);
        int sum = 0;
        
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            
            int weight = p.first;
            int node = p.second;
            
            if (inMST[node] == true) 
                continue;
                
            inMST[node] = true; // added to our inMSt
            sum += weight;
            
            for (auto & temp : adj[node]) {
                int neighbor = temp[0];
                int neighbor_wt = temp[1];
                
                if (inMST[neighbor] == false) {
                    pq.push({neighbor_wt, neighbor});
                }
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends




// OR
class Solution
{
    typedef pair<int, int> P;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});
        vector<bool> inMST(V, false);
        int sum = 0;
        
        while(!pq.empty()) {
            
            auto p = pq.top();
            pq.pop();
            
            int wt     = p.first;
            int node   = p.second;
            
            if(inMST[node] == true)
                continue;
            
            inMST[node] = true; //added to mst
            sum += wt;
            
            for(auto &tmp : adj[node]) {
                
                int neighbor      = tmp[0];
                int neighbor_wt   = tmp[1];
                
                if(inMST[neighbor] == false) {
                    pq.push({neighbor_wt, neighbor});
                }
 
            }
        }
        
        return sum;
    }
};


//Approach-2 :Without using Priority_queue
int minKey(int V, vector<bool> inMST, vector<int> key) {
    int minValue  = INT_MAX;
    int min_index;
    for(int v = 0; v<V; v++) {
        if(inMST[v] == false && key[v] < minValue) {
            min_index = v;
            minValue  = key[v];
        }
    }
    return min_index;
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V);
    vector<bool> inMST(V, false);
    
    parent[0] = -1;
    key[0] = 0; //so that we start from vertex '0'
    /*
        since we need all V vertices in our MST
        0 will be included in the beginning (key[0] = 0 is minimum) ,
        we will need V-1 more vertices to cover whole graph
    */
    for(int count = 1; count <= V-1; count++) {
        int u = minKey(V, inMST, key);
        inMST[u] = true;
        
        for(int v = 0; v<V; v++) {
            if(graph[u][v] != 0 && inMST[v] == false && graph[u][v] < key[v]) {
                key[v]    = graph[u][v];
                parent[v] = u;
            }
        }
    }
    int sum = 0;
    for(int i = 1; i<V; i++) {
        sum += key[i];
    }
    return sum;
}