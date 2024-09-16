/* GFG Problem No.: Shortest Path in Weighted undirected graph  */

/*
    Company Tags                : Nil
    GfG Link                    : https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
*/


class Solution {
    public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(n+1, INT_MAX);
        vector<int> parent(n+1);
        
        for(int i = 1; i<=n; i++) {
            parent[i] = i;
        }
        
        result[1] = 0;
		pq.push({0, 1});

		while(!pq.empty()) {

		    int d  = pq.top().first;
		    int node = pq.top().second;
		    pq.pop();

		    for(auto &it : adj[node]) {

    			int adjNode = it.first;
    			int dist    = it.second;
    
    			if(d + dist < result[adjNode]) {
    
    			    result[adjNode] = d + dist;
    			    pq.push({d+dist, adjNode});
    			    parent[adjNode] = node;
    
    			}

		    }

		}

        vector<int> path;
        int node = n;
        
        if(result[node] == INT_MAX)
            return {-1};
        
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(begin(path), end(path));
		return path;
    }
};



// another way

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        int source = 1;

        // constructing the adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
    
        for(auto vec: edges){
            auto u = vec[0];
            auto v = vec[1];
            auto wt = vec[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    
        // priority queue to store {distance, node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
        // distances from source to each node(ndexes)
        vector<int> result(n + 1, INT_MAX);
    
        // parent of each node for path reconstruction
        vector<int> parent(n + 1, -1);
    
        // initialize parent vector
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    
        // source to source distance
        result[source] = 0;
        pq.push({0, source}); // {distance, node}
    
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            
            int dist = top.first;
            int u = top.second;
    
            // visit adjacent nodes
            for (auto &v : adj[u]) {
                int adjNode = v.first;
                int adjDist = v.second;
    
                if (adjDist + dist < result[adjNode]) {
                    result[adjNode] = adjDist + dist;
                    pq.push({adjDist + dist, adjNode});
    
                    // update parent of adjNode
                    parent[adjNode] = u;
                }
            }
        }
    
        // edge case: if destination is unreachable
        int destNode = n;
        if (result[destNode] == INT_MAX) return {-1};
    
        // reconstruct path from destination to source using parent array
        vector<int> path;
    
        while (parent[destNode] != destNode) {
            path.push_back(destNode);
            destNode = parent[destNode];
        }
    
        // add the source node to the path
        path.push_back(source);
        
        // pushing the max dist as req in the problem statement
        //restlt vec will store -> dist from source to i -> 
        //at idx n -> dist from source to n-> which is our req max dist
        path.push_back(result[n]);
        
        // reverse to get the path from source to destination
        reverse(path.begin(), path.end());
    
        return path;
    }