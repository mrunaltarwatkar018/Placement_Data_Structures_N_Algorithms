/* Leetcode Problem No.: 547. Number of Provinces  */

/*
        Company Tags                 : Google, Microsoft, Amazon
        Leetcode Link                : https://leetcode.com/problems/number-of-provinces/
        GfG Link                     : https://practice.geeksforgeeks.org/problems/number-of-provinces/1
*/


//Approach-3 : [ Using BFS : Creating our own Map as graph ]
class Solution {
public:

    void bfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited) {
        queue<int> que;
        que.push(u);
        visited[u] = true;
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
           //Visit neighbours
            for(int &v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    que.push(v);
                }
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
                bfs(adj, i, visited);
                count++;
            }
        }
        
        return count;
        
    }
};


//Approach-4 : [ Using BFS - Using given input graph]


class Solution {
public:
    int n;
    void bfs(vector<vector<int>>& isConnected, int u, vector<bool>& visited) {
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for ( int v  = 0; v < n; v++) {
                if ( !visited[v] && isConnected[u][v] == 1 ) {
                    bfs(isConnected, v, visited);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        n = isConnected.size();

        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                bfs(isConnected, i, visited);
                count++;
            }
        }
        
        return count;
        
    }
};









// another way


class Solution {
public:
    int n;
    void bfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {
        queue<int> que;
        que.push(u);
        visited[u] = true;
        
        
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            //Visit neighbours
            for(int v = 0; v<n; v++) {
                if(adj[u][v] == 1 && !visited[v]) {
                    visited[v] = true;
                    que.push(v);
                }
            } 
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                bfs(isConnected, i, visited);
                count++;
            }
        }
        
        return count;
        
    }
};






















/*
        YOUTUBE VIDEOS ON THIS Qn : DFS - https://www.youtube.com/watch?v=70LNE8RMPNc
                                    BFS - https://www.youtube.com/watch?v=YDMkSvNdB20
*/