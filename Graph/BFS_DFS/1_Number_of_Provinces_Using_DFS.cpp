/* Leetcode Problem No.: 547. Number of Provinces  */

/*
        Company Tags                 : Google, Microsoft, Amazon
        Leetcode Link                : https://leetcode.com/problems/number-of-provinces/
        GfG Link                     : https://practice.geeksforgeeks.org/problems/number-of-provinces/1
*/

//Approach-1 : [ Using DFS - Creating our own Map as graph ]

class Solution {
public:


    void dfs(unordered_map<int, vector<int>> & adj, int u, vector<bool> & visited ) {
        visited[u] = true;

        // visite neighbours
        for ( int & v : adj[u] ) {
            if ( !visited[v] ) {
                dfs(adj, v, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> visited(n, false);

        // make Graph
        unordered_map<int, vector<int>> adj;  

        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( isConnected[i][j] == 1 ) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        for ( int i = 0; i < n; i++ ) {
            if ( !visited[i] ) {
                dfs(adj, i, visited);
                count++;
            }
        }

        return count;
    }

};


// other way similar
class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true;
        
        //Visit neighbours
        for(int &v : adj[u]) {
            if(!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(adj, i, visited);
            }
        }
        
        return count;
        
    }
};














//Approach-2 : [ Using DFS - Using given input graph]

class Solution {
public:

    int n;
    void dfs(vector<vector<int>>& isConnected, int u, vector<bool> & visited ) {
        visited[u] = true;

        // visite neighbours
        // find neigbhours
        for ( int v = 0; v < n; v++ ) {
            if ( !visited[v] && isConnected[u][v] == 1) {
                dfs(isConnected, v, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();

        vector<bool> visited(n, false);

        int count = 0;
        for ( int i = 0; i < n; i++ ) {
            if ( !visited[i] ) {
                count++;
                dfs(isConnected, i, visited);
            }
        }

        return count;
    }

};


// other similar way
class Solution {
public:
    int n;
    void dfs(vector<vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true;
        
        //Visit neighbours
        for(int v = 0; v < n; v++) {
            if(adj[u][v] == 1 && !visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(isConnected, i, visited);
            }
        }
        
        return count;
        
    }
};
























/*
        YOUTUBE VIDEOS ON THIS Qn : DFS - https://www.youtube.com/watch?v=70LNE8RMPNc
                                    BFS - https://www.youtube.com/watch?v=YDMkSvNdB20
*/