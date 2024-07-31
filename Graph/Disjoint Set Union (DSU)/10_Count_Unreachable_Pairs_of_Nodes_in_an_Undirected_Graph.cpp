/* Leetcode Problem No.: 2316. Count Unreachable Pairs of Nodes in an Undirected Graph  */

/*
        Company Tags                : MICROSOFT
        Leetcode Link               : https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
        
        NOTE : DFS and BFS Approach already shared here (below link) : 
        https://github.com/mrunaltarwatkar018/Placement_Data_Structures_N_Algorithms/blob/master/Graph/BFS_DFS/3_Count_Unreachable_Pairs_of_Nodes_in_an_Undirected_Graph.cpp
*/

// Approach-4 : Using DSU : Time complexity: O(V+E) ,  Here 'V' is the number of nodes and 'E' is the total number edges.
class Solution {
public:

    // Step 1: find() and Union() for DSU
    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);

        // initialize parent, 
        for ( int i = 0; i < n; i++ ) {
            parent[i] = i;
        }

        // Step 2: prpcess all the given edges for making components 
        for ( auto &vec : edges ) {
            int u = vec[0];
            int v = vec[1];

            Union(u, v);
        }

        // step 3: creating map for storing "parent(component)" correspomding to size of component
        unordered_map<int, int> mp;

        for ( int i = 0; i < n; i++ ) {
            int parent_of_i = find(i); // parent or representative

            mp[parent_of_i]++;
        }

        // step 4: with the help og map, calculate result
        long long result = 0;
        long long remainingNodes = n;

        for ( auto &it : mp ) {
            long long sizeOfComponent = it.second;

            result += (sizeOfComponent) * (remainingNodes - sizeOfComponent);

            remainingNodes -= sizeOfComponent;
        }

        return result;
    }
};



// another way

//DSU : Time complexity: O(V+E) ,  Here 'V' is the number of nodes and 'E' is the total number edges.
class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        rank.resize(n, 0);
        
        for(int i = 0; i<n; i++) {
            parent[i] = i;
        }
        
        for(auto &vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            Union(u, v);
            
        }

        unordered_map<int, int> mp;
        
        for(int i = 0; i<n; i++) {
            int papa = find(i);
            mp[papa]++;
        }
        
        long long result = 0;
        long long remainingNodes = n;
        
        for(auto &it : mp) {
            
            long long size = it.second;
            
            result += (size) * (remainingNodes-size);
            
            remainingNodes -= size;
            
        }
        
        return result;
        
    }
};









/*
        YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Hh_9ppxgzpo
*/