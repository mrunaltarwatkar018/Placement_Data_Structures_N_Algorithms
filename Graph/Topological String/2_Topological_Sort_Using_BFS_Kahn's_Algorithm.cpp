/* GFG problem:  Topological Sort  */

/*
    MY YOUTUBE VIDE ON THIS Qn		: https://www.youtube.com/watch?v=uVl4ftleTes
    Company Tags                        : Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    GfG Link                            : https://practice.geeksforgeeks.org/problems/topological-sort/1#
    
    Related Leetcode Qn                 : Course Schedule, Course Schedule II
    Course Schedule (Leetcode - 207)    : https://leetcode.com/problems/course-schedule/
    Course Schedule II (Leetcode - 210) : https://leetcode.com/problems/course-schedule-ii/
    
    Solution (Course Schedule)          :   (Using BFS Kahn's Algorithm) https://github.com/mrunaltarwatkar018/Placement_Data_Structures_N_Algorithms/blob/master/Graph/Topological%20String/3_Course_Schedule_Using_BFS_Kahn's_Algorithm_Topological_Sort.cpp
                                            (Using DFS Cycle Check) https://github.com/mrunaltarwatkar018/Placement_Data_Structures_N_Algorithms/blob/master/Graph/Topological%20String/4_Course_Schedule_Using_DFS_Cycle_Check.cpp
    
    Solution (Course Schedule II)       :   (Using BFS Kahn's Algorithm) https://github.com/mrunaltarwatkar018/Placement_Data_Structures_N_Algorithms/blob/master/Graph/Topological%20String/5_Course_Schedule-II_using_BFS_Kahn's_Algorithm.cpp
                                            (Using DFS Cycle Check) https://github.com/mrunaltarwatkar018/Placement_Data_Structures_N_Algorithms/blob/master/Graph/Topological%20String/6_Course_Schedule-II_using_DFS.cpp
    NOTE: This can also be used to check if the graph contains cycle or not (Please see Line:56 below)
*/


//NOTE : This assumes that, we don't have cycle in the given directed graph. You can simply add few things in the same code to check for cycle also


    class Solution
    {
        public:
        //Function to return list containing vertices in Topological order. 
            vector<int> topoSort(int V, vector<int> adj[]) 
            {
                queue<int> que;
                vector<int> indegree(V, 0);
                
                //1. fill indegree
                for(int u = 0; u<V; u++) {
                    for(int &v : adj[u]) {
                        indegree[v]++;
                    }
                }
                
                //2. Fill que, indegree with 0
                for(int i = 0; i<V; i++) {
                    if(indegree[i] == 0) {
                        que.push(i);
                    }
                }
            
                //3. Simple BFS
                vector<int> result;
                while(!que.empty()) {
                    int u = que.front();
                    result.push_back(u);
                    que.pop();
                    
                    for(int &v : adj[u]) {
                        indegree[v]--;
                        
                        if(indegree[v] == 0) {
                            que.push(v);
                        }
                        
                    }
                }
                
                return result;
            }
    };













// other way
    class Solution {
        public:
        //Function to return list containing vertices in Topological order. 
        vector<int> topoSort(int N, vector<int> adj[])  {
            queue<int> que;
            vector<int> indegree(N, 0);
            
            //1. 
            for(int u = 0; u<N; u++) {
                for(int &v : adj[u]) {
                    indegree[v]++;
                }
            }
            
            //2. Fill que, indegree with 0
            for(int i = 0; i<N; i++) {
                if(indegree[i] == 0) {
                    que.push(i);
                }
            }
            
            //3. Simple BFS
            vector<int> result;
            while(!que.empty()) {
                int u = que.front();
                result.push_back(u);
                que.pop();
                
                for(int &v : adj[u]) {
                    indegree[v]--;
                    
                    if(indegree[v] == 0) {
                        que.push(v);
                    }
                    
                }
            }
            
            return result;
        }
    };