/* Leetcode Problem No.: 210. Course Schedule - II  */


/*
    Company Tags                : Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    Leetcode Link               : https://leetcode.com/problems/course-schedule-ii/
*/


//Approach-2 (Using DFS Topological Sort Concept)

class Solution {
public:

    bool hasCycle;

    void DFS(unordered_map<int, vector<int>> & adj, int u, vector<bool> & visited, stack<int>& st, vector<bool> & inRecursion ) {
        visited[u] = true;
        inRecursion[u] = true;

        //pehle mere ('u' ke node ke ) bachho ko daalo
        for ( int & v : adj[u] ) {
            if ( inRecursion[v] == true ) {
                hasCycle = true;
                return;
            }

            if ( !visited[v] ) {
                DFS( adj, v, visited, st, inRecursion );
            }
        }

        //ab mujhe daalo stack me
        st.push(u);
        inRecursion[u] = false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        vector<bool> inRecursion(numCourses, false);
        vector<bool> visited(numCourses, false);
        hasCycle = false;

        for ( auto & vec : prerequisites ) {
            int a = vec[0];
            int b = vec[1];

            // b ---> a
            adj[b].push_back(a);
        }

        stack<int> st;

        for ( int  i = 0; i < numCourses; i++ ) {
            if ( !visited[i] ) {
                DFS(adj, i, visited, st, inRecursion);
            }
        }

        // is there is any cycle, cycle exist
        if ( hasCycle == true ) {
            return {};
        }

        vector<int> result;

        while( !st.empty() ) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};



// other way

//Approach-2 (Using DFS)


class Solution {
public:
    bool hasCycle = false;
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, stack<int>& st, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;

	    //pehle mere ('u' ke node ke ) bachho ko daalo
        for(int &v : adj[u]) {
            if(inRecursion[v] == true) {
                hasCycle = true;
                return;
            }
            
            if(!visited[v])
                DFS(adj, v, visited, st, inRecursion);
        }

	    //ab mujhe daalo stack me
        st.push(u);
        inRecursion[u] = false;

	}
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        hasCycle = false;
        
        stack<int> st;
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b--->a
            adj[b].push_back(a);
        }
        
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i])
                DFS(adj, i, visited, st, inRecursion);
        }
        
        vector<int> result;
        
        if(hasCycle)
            return {};
        
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};






























/*
    MY YOUTUBE VIDEO ON THIS Qn :   BFS - https://www.youtube.com/watch?v=W1WhSN9wAw0
                                    DFS - https://www.youtube.com/watch?v=yiR95dxinjs
*/