/* Leetcode Problem No.: 207. Course Schedule  */

/*
    Company Tags                : Apple, Twitter, Meta, Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    Leetcode Link               : https://leetcode.com/problems/course-schedule/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?
*/






//Approach-2 (Using DFS Cycle Check)
class Solution {
public:

    bool isCycleDFS(unordered_map<int, vector<int>> & adj, int u, vector<bool> &visited, vector<bool> & inRecursion ) {
        visited[u] = true;
        inRecursion[u] = true;

        for ( int  & v : adj[u] ) {
            //if not visited, then we check for cycle in DFS
            if ( !visited[v] && isCycleDFS(adj, v, visited, inRecursion) ) {
                return true; // cycle exist
            } 
            else if (inRecursion[v] == true) {
                return true;
            }
        }
        inRecursion[u] = false;
        return false; // no cycle
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b ---> a
            adj[b].push_back(a);
        }
        
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
                return false; // course complete nahi kar shkte
        }
        
        return true; //complete kar shkte hain saare courses
    }
};



























































/*
    YOUTUBE VIDEO ON THIS Qn :  BFS - https://www.youtube.com/watch?v=lqjlGGMjSMU
                                DFS - https://www.youtube.com/watch?v=X1TIkW4C254
*/